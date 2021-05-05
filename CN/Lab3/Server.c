#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORTNO 10200
int SocketDescriptor,newSocketDescriptor,PortNo,ClientLength, n=1;
	struct sockaddr_in ServerAddress,ClientAddress;
	int i, value;
	int matrix [200][200];
	int rowno;
	int rowno1;
void addtoMatrix(int row[],int n){
	
	for (int i = 0; i < n; ++i)
	{
		matrix[rowno][i]=row[i];

	}
	rowno++;
}
int main()
{
	
	//Unnamed socket
	SocketDescriptor = socket(AF_INET,SOCK_DGRAM,0);
	ServerAddress.sin_family=AF_INET;
	ServerAddress.sin_addr.s_addr=INADDR_ANY;
	ServerAddress.sin_port = htons(PORTNO);
	int result = 
	bind(SocketDescriptor,(struct sockaddr *)&ServerAddress,sizeof(ServerAddress));
	///Create conn and queue


		char buf[256];
		printf("server Waiting\n");
		//Accept conn
		ClientLength = sizeof(ClientLength);
		while(1) {

			int n;
		//Read Write
		int na = recvfrom(SocketDescriptor,&n,sizeof(int),0,(struct sockaddr *)&ClientAddress,&ClientLength);
		int row[n];
		printf(" %d\n",n );
				 na = recvfrom(SocketDescriptor,&rowno1,sizeof(int),0,(struct sockaddr *)&ClientAddress,&ClientLength);

		na = recvfrom(SocketDescriptor,row,sizeof(row),0,(struct sockaddr *)&ClientAddress,&ClientLength);
		addtoMatrix(row,n);
		printf("matrix \n");
		for (int i = 0; i < rowno1; ++i)
		{
			int k=0;
			while(matrix[i][k]!=0&&k<3){
				printf("%d \t",matrix[i][k]);
				k++;
			}
			printf("\n\n\n");
		}

		printf("Message from client %s\n",buf);

		na = sendto(SocketDescriptor,buf,sizeof(buf),0,(struct sockaddr *)&ClientAddress,ClientLength);
}

	
	//return 0;
}
