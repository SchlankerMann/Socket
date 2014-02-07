#include <sys/socket>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include "errore.h"

typedef struct sockaddr_in Addr;

int main (int argc, char* argv[])
{
	int port;
	int sockId;
	int len_addr;
	int ret_code;
	struct sockaddr_in* myself_addr;

	if(argc !=2)
		{ 
			printf("USAGE:%s PORT\n",argv[0]);
			return(-1);
		}	
	port=atoi(argv[1]);

	printf("Creo un socket....\n");
	sockId=socket(AF_INET,SOCK_STREAM,0);
	if(sockId<0) 		errore("ERRORE nella creazione del socket\n",-2);

	printf("Associo il socket alla porta%d.....\n",port);
	myself_addr=((Addr*) malloc(sizeof(Addr));
	len_addr=sizeof (Addr);
	ret_code = bind(sockId, (struct sockaddr *)myself_addr,(socklen_t)len_addr);
	if(ret_code)  		errore("ERRORE nella creazione della porta\n",-3);
	
	listen();


	accept();
	recv();
	send();

	close();
	shutdown();
