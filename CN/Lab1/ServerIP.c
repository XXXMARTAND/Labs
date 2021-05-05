#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <unistd.h>
#define PORTNO 10200
void PerformServerTask( int newSocketDescriptor,int ClientLength, struct sockaddr_in * ClientAddress)
{
	char buf[256];
	int n = 1;
	n = read(newSocketDescriptor,buf,sizeof(buf));
		printf("Service Request from client %d\n",getpid());
		time_t t;
	 for(int i=0;i<strlen(buf);i++)
	 	{
        	buf[i] = toupper(buf[i]);
        }
		
		n = write(newSocketDescriptor,buf,sizeof(buf));
 
}
int CreateServerSocket()
{
	int SocketDescriptor,newSocketDescriptor,PortNo;
	struct sockaddr_in ServerAddress;
	int i, value;
	//Unnamed socket
	SocketDescriptor = socket(AF_INET,SOCK_STREAM,0);
	ServerAddress.sin_family=AF_INET;
	ServerAddress.sin_addr.s_addr=INADDR_ANY;
	ServerAddress.sin_port = htons(PORTNO);
	bind(SocketDescriptor,(struct sockaddr *)&ServerAddress,sizeof(ServerAddress));
	///Create conn and queue
	listen(SocketDescriptor,5);
	return SocketDescriptor;
	
}
int main()
{
	int newSocketDescriptor,ClientLength;
	struct sockaddr_in ClientAddress;
	while(1){
		
		printf("server Waiting\n");
		//Accept conn
		ClientLength = sizeof(ClientLength);
		newSocketDescriptor = accept(CreateServerSocket(),(struct sockaddr *)&ClientAddress,&ClientLength);
		printf("%d\n",ClientAddress.sin_addr);
		//Read Write
		PerformServerTask(newSocketDescriptor,ClientLength,&ClientAddress);

	}
	//return 0;
}
