#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>
int main(){
	int listfd,connfd,retval;
	socklen_t clilen;
	struct sockaddr_in cliaddr,servaddr;
	
	listfd= socket(AF_INET,SOCK_STREAM,0);
	if(listfd<0){
		perror("sock:");
		exit(1);
	}
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 	//htonl(INADDR_ANY);
	servaddr.sin_port = htons(8000); 			//TCP protocol HTTP-----PORT
	
	retval=bind(listfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(retval<0){
		perror("blind:");
		exit(2);
	}
	
	listen(listfd,5);
	printf(" server is running\n");
	while(1){
		int n;
		char buf[200];
		clilen = sizeof(cliaddr);
		connfd = accept(listfd,(struct sockaddr*)&cliaddr, &clilen);
		printf("client connected\n");
		
		/*read write*/
		n= read(connfd,buf,200);
		buf[n]='\0';
		printf("data is reseved from client =%s\n",buf);
	}
	close(listfd);
	return 0;
}
