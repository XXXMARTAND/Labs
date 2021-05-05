#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#define PORTNO 10200
void PerformServerTask( int newsockfd, int s_addr){
	char buf[256];
	int n = 1;
	n = read(newsockfd,buf,sizeof(buf));

		printf("Date Requested from client %d\n",s_addr);
		time_t t;
		n = write(newsockfd,ctime(&t),sizeof(buf));

}
int CreateServerSocket(){
	int sockfd,newsockfd,PortNo;
	struct sockaddr_in seraddr;
	int i, value;
	//Unnamed socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family=AF_INET;
	seraddr.sin_addr.s_addr=INADDR_ANY;
	seraddr.sin_port = htons(PORTNO);
	bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
	///Create conn and queue
	listen(sockfd,5);
	return sockfd;
	
}
int main()
{
	int newsockfd,clilen;
	struct sockaddr_in cliaddr;
	while(1){
		
		printf("server WaiSWDAting\n");
		//Accept conn
		clilen = sizeof(clilen);
		newsockfd = accept(CreateServerSocket(),(struct sockaddr *)&cliaddr,&clilen);
		if (fork()==0)		
		{
			
		PerformServerTask(newsockfd,cliaddr.sin_addr.s_addr);

			close(newsockfd);
		exit(0);
		
		
			
		}
		else{
		//Re
			
			
		
	close(newsockfd);
			
		
		

		

	}
	//return 0;
}
}
