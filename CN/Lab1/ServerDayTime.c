#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#define PORTNO 10200
void PerformServerTask( int newSocketDescriptor, int s_addr){
	char buf[256];
	int n = 1;
	n = read(newSocketDescriptor,buf,sizeof(buf));

		printf("Date Requested from client %d\n",s_addr);
		time_t t;
		n = write(newSocketDescriptor,ctime(&t),sizeof(buf));

}
int CreateServerSocket(){
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
		//Read Write
		PerformServerTask(newSocketDescriptor,ClientAddress.sin_addr.s_addr);

	}
	//return 0;
}
