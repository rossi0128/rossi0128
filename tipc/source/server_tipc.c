#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "common_tipc.h"


int main(int argc, char *argv[], char *dummy[])
{
	struct sockaddr_tipc server_addr;
	struct sockaddr_tipc client_addr;
	socklen_t alen = sizeof(client_addr);
	int sd;
	char inbuf[BUF_SIZE];
	char outbuf[BUF_SIZE] = "Uh ?";

	printf("****** TIPC server hello world program started ******\n\n");

	server_addr.family = AF_TIPC;
	server_addr.addrtype = TIPC_ADDR_NAMESEQ;
	server_addr.addr.nameseq.type = SERVER_TYPE;
	server_addr.addr.nameseq.lower = SERVER_INST;
	server_addr.addr.nameseq.upper = SERVER_INST;
	server_addr.scope = TIPC_ZONE_SCOPE;

	sd = socket(AF_TIPC, SOCK_RDM, 0);

	if (0 != bind(sd, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
		printf("Server: failed to bind port name\n");
		exit(1);
	}

	if (0 >= recvfrom(sd, inbuf, sizeof(inbuf), 0,
	                  (struct sockaddr *)&client_addr, &alen)) {
		perror("Server: unexpected message");
	}
	printf("Server: Message received: %s !\n", inbuf);

	if (0 > sendto(sd, outbuf, strlen(outbuf)+1, 0,
	                (struct sockaddr *)&client_addr, sizeof(client_addr))) {
		perror("Server: failed to send");
	}
	printf("\n****** TIPC server hello program finished ******\n");

	exit(0);
}
