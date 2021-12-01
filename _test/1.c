#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int func(int n)
{
    int sum = 0, i;
    for (i = 0; i < n; i++)
    {
        sum += i;
    }
    return sum;
}


void main()
{
    int i;
    char buffer[512];

	printf("input message:");
	fgets(buffer,512,stdin);
	
	
	int len = strlen(buffer);
	printf("input %s,length %d\n",buffer,len);
	buffer[len]='\0';
	
	//memset(buffer+len,'a',16);
	//buffer[len+16]='\0';
	printf("buffer: %s\n",buffer);

}

