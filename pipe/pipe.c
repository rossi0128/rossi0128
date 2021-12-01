#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>


int main()
{
    int fd[2];
    int ret=pipe(fd);
    if(ret==-1)
    {
        perror("pipe error\n");
        return -1;
    }
    
    printf("Fd[0]:%d,Fd[1]:%d\n",fd[0], fd[1]);
        
    int id=fork();
    
    if(id==0)
    {  
        printf("child id:%d, my process id is %d\n",id,getpid()); 
        int i=1;
        //close(fd[0]);
        char* child="I am child!";
        char num[32];

        while(i<=5)
        {  
            sprintf(num,"%d", i);
            
            //printf("writing %s\n",num);
            write(fd[1],num,strlen(num));
            
            //printf("writing %s\n",child);
            write(fd[1],child,strlen(child));
            

            sleep(2);
            i++;
        }
    }
    else if(id>0)
    {
        printf("p id:%d, my process id is %d\n",id,getpid()); 
        //close(fd[1]);
        char msg[100];
        int j=1;
        while(1)
        {
            memset(msg,'\0',sizeof(msg));
            ssize_t s=read(fd[0],msg,sizeof(msg));
            if(s>0)
            {
                msg[s-1]='\0';
            }
            printf("reading msg no %d: %s\n",j,msg);
            j++;

        }
        
    }
    else
    {
        perror("fork error\n");
        return -1;
    }
    return 0;
}
