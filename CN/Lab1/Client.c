#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define PORTNO 10200
int main()
{
	int SocketDescriptor,Result,Length, n=1;
	struct sockaddr_in Address;
	char buf[256],ch[256];
	//Unnamed socket
	SocketDescriptor = socket(AF_INET,SOCK_STREAM,0);
	Address.sin_family=AF_INET;
	Address.sin_addr.s_addr=INADDR_ANY;
	Address.sin_port = htons(PORTNO);
	Length = sizeof(Address);
	//Connect
	Result = connect(SocketDescriptor,(struct sockaddr *)&Address,Length);
	if (Result==-1){
		printf("%d\n",Result );
		perror("\n Client Error");
		exit(1);

	}
	//Read Write
	printf("Enter String\t");
	gets(ch);
	ch[strlen(ch)]='\0';
	write(SocketDescriptor,ch,strlen(ch));
	printf("String sent back is\n");
	while(n){
		n=read(SocketDescriptor,buf,sizeof(buf));
		puts(buf);
	}
}