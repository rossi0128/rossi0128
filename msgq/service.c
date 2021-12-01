#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>


#define DEBUG 1
#define MSG_LEN 512
#define MSG_CYCLE_TIMES 500


struct mymesg{
	long int mtype;
	char mtext[MSG_LEN];
};

int send_form_stdin(int id)
{
	int count = 0;
	struct mymesg ckxmsg;
	ckxmsg.mtype = 1;

	
	while(1)
	{

		memset(ckxmsg.mtext,0,MSG_LEN);
		
		printf("input message:");
		fgets(ckxmsg.mtext,MSG_LEN,stdin);
		
		int len = strlen(ckxmsg.mtext);
		len-=1;       //去除读入的\n
		ckxmsg.mtext[len] = '\0';	
		
		#if DEBUG
		printf("sending msg %d length %d data:%s \n",count,len,ckxmsg.mtext);
		#endif
		
		if( msgsnd(id,(void *)&ckxmsg,len,0) < 0)
		{
			printf("send msg error\n");
			return -1;
		}

		if(strncmp(ckxmsg.mtext,"QUIT",4) == 0)
			break;
		
		count++; 
	}
	
	if(msgctl(id,IPC_RMID,NULL) < 0)
	{
		printf("del msg error \n");
		return 0;
	}
}

int send_cyclical(int id)
{
	int count = 0;
	struct mymesg ckxmsg;
	ckxmsg.mtype = 1;
	
	while(count < MSG_CYCLE_TIMES)
	{
		memset(ckxmsg.mtext,0,MSG_LEN);
		
		sprintf(ckxmsg.mtext,"this is msg no %d", count);
		int len = strlen(ckxmsg.mtext);

		#if DEBUG
		printf("sending msg %d length %d data:%s \n",count,len,ckxmsg.mtext);
		#endif

		if( msgsnd(id,(void *)&ckxmsg,len,0) < 0)
		{
			printf("send msg error\n");
			return -1;
		}

		count++;    
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int id = 0;

	key_t key = ftok("/tmp",66);
	id = msgget(key,IPC_CREAT | 0666);
	
	if(id == -1)
	{
		printf("create msg error \n");
		return -1;
	}
	
	if(argc > 1 &&  strncmp(argv[1],"1",1) ==0 )
		send_cyclical(id);
	else 
		send_form_stdin(id);

	return 0;
}
