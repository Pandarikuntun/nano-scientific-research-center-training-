#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SRV_UDP_PORT 8000
#define MAX_MSG 100
void errExit(char *str){
	puts(str);
	exit(0);
}

int main(){
	int sockfd;
	struct sockaddr_in servaddr,cliaddr;
	
	int clilen,n;
	char mesg[MAX_MSG];
	if((sockfd = socket(AF_INET,SOCK_DGRAM,0))<0)
		errExit("cant open datagram socket\n");
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htonl(SRV_UDP_PORT);
	
	if(bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0) 
		errExit("cant bin local address\n");
	printf("server is waiting for the message\n");
	while(1){
		clilen=sizeof(cliaddr);
		n= recvfrom(sockfd,mesg,MAX_MSG,0,(struct sockaddr*)&cliaddr,&clilen);
		if(n<0){
			errExit("receive erreor\n");
		if(sendto(sockfd,mesg,n,0,(struct sockaddr*)&cliaddr,&clilen)<!n)
			errExit("send to error\n");
			printf("receive following message from client %s\n%s\n",inet_ntoa(cliaddr.sin_addr),mesg);
			}
		}
}
			
	
