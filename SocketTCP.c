#include <sys/socket>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include "errore.h"

#define MAX_CONN 42
#define MYSELF_IP "0.0.0.0"
#define MAX_BUFFER 4096

typedef struct sockaddr_in Addr;

int main (int argc, char* argv[])
{
	char buffer[MAX_BUFFER+1];
	char *msg;	
	int port;
	int sockId;
	int connId;
	int len_addr;
	int ret_code;
	int i;
	
	Addr *myself_addr,*client_addr;

	if(argc !=3)
		{ 
			printf("USAGE:%s PORT\n",argv[0]);
			return(-1);
		}	
	port=atoi(argv[1]);
	msg=argv[2];	

	printf("Creo un socket....\n");
	sockId=socket(AF_INET,SOCK_STREAM,0);//istanza del socket
	if(sockId<0) 		errore("ERRORE nella creazione del socket\n",-2);

	printf("Associo il socket alla porta%d.....\n",port);

	myself_addr=((Addr*) malloc(sizeof(Addr));

	myself_adr->sin_family=AF_INET;

	inet_aton(MYSELF_IP,&(myself_addr->sin_addr));

	myself_addr->sin_port=htons(port);

	len_addr=sizeof (Addr);

	ret_code = bind(sockId, (struct sockaddr *)myself_addr,(socklen_t)len_addr);//assegno su quale porta ascoltare
	if(ret_code)  		errore("ERRORE nella creazione della porta\n",-3);
	
	printf("Indico il numero massimo di connessioni.....\n");
	ret_code=listen(sockId,MAX_CONN);//imposto il numero massimo di connessioni
	if(ret_code)  		errore("ERRORE nell'assegnare ilnumero massimo di connessioni\n",-4);


	printf("Attendo che il client mi contatti per stabilire una connessione....\n");
	len_addr=sizeof (Addr);
	client_addr=(Addr*) malloc (sizeof(Addr));

	connId = accept(sock_id,(struct sockaddr*) client_addr,(socklen_t*)&len_addr);

	if(connId<=0)  		errore("ERRORE nell'accettare la connessione\n",-5);

	printf("Accettata una connessione da %s:%d.../n",inet_ntoa(client_addr->sin_addr),
							htons(client_addr->sin_port));
	printf("Attendo che il client min dica qualcosa");
	ret_code= recv(connId,buffer,MAX_BUFFER,0);
	if(ret_code<=0)  		errore("ERRORE durante la recezione dal client\n",-6);
	buffer[ret_code]="\0";
	printf("Ho ricevuto '%s' dal client\n",buffer);
	
	printf("Rispondo al client...\n");
	
	len_msg=strlen(msg+1);

	ret_code=send(conn_id,msg,len_msg,0);
	if(ret_code != len_msg)  		errore("ERRORE durante l'invio della risposta al client\n",-7);

	printf("Chiudo la connessione...\n");
	close(connId);

	printf("Chiudo il socket...\n");
	shutdown(sockId,SHUT_RDWR);
	
	return 0;

}
