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
	SocketDescriptor = socket(AF_INET,SOCK_DGRAM,0);
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
	int nn;
	scanf("%d",&nn);
	
	int m = sendto(SocketDescriptor,&nn,sizeof(int),0,(struct sockaddr *)&Address,Length);
	int na[nn];
	int nr;
	printf("Enter String\t");
		m  = sendto(SocketDescriptor,&nr,sizeof(int),0,(struct sockaddr *)&Address,Length);

	for (int i = 0; i < nn; ++i)
	{
		scanf("%d",&na[i]);
	}
	

	m = sendto(SocketDescriptor,na,sizeof(na),0,(struct sockaddr *)&Address,Length);

	printf("String sent back is\n");
		int nb[200][200];
		n=recvfrom(SocketDescriptor,nb,sizeof(nb),0,(struct sockaddr *)&Address,&Length);
		puts(buf);
	
}