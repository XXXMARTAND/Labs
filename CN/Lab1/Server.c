#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORTNO 10200
int main()
{
	int SocketDescriptor,newSocketDescriptor,PortNo,ClientLength, n=1;
	struct sockaddr_in ServerAddress,ClientAddress;
	int i, value;
	//Unnamed socket
	SocketDescriptor = socket(AF_INET,SOCK_STREAM,0);
	ServerAddress.sin_family=AF_INET;
	ServerAddress.sin_addr.s_addr=INADDR_ANY;
	ServerAddress.sin_port = htons(PORTNO);
	bind(SocketDescriptor,(struct sockaddr *)&ServerAddress,sizeof(ServerAddress));
	///Create conn and queue
	listen(SocketDescriptor,5);
	while(1){
		char buf[256];
		printf("server Waiting\n");
		//Accept conn
		ClientLength = sizeof(ClientLength);
		newSocketDescriptor = accept(SocketDescriptor,(struct sockaddr *)&ClientAddress,&ClientLength);
		//Read Write
		n = read(newSocketDescriptor,buf,sizeof(buf));
		printf("Message from client %s\n",buf);
		n = write(newSocketDescriptor,buf,sizeof(buf));

	}
	//return 0;
}