#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/msg.h>
#include<sys/ipc.h>

#define DEBUG 1
#define MSG_LEN 512

struct mymesg{
	long int mtype;
	char mtext[MSG_LEN];
};
int main()
{
	int id = 0;
	struct mymesg ckxmsg;
	
	key_t key = ftok("/tmp",66);
	id = msgget(key,0666|IPC_CREAT);
	
	if(id == -1)
	{
		printf("open msg error \n");
		return 0;
	}
	while(1)
	{
        int msg_len; 
		if( (msg_len = msgrcv(id,(void *)&ckxmsg,MSG_LEN,1,0)) < 0)
		{
			printf("msgrcv msg len error:%d\n",msg_len);
			return 0;
		}
		
		#if DEBUG
		printf("msgrcv msg length %d data:%s \n",msg_len,ckxmsg.mtext);
		#endif

		if(strncmp(ckxmsg.mtext,"QUIT",4) ==0)
			break;
	}
	return 0;
}

