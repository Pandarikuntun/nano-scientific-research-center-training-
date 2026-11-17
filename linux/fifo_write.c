#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main(){
	char s1[20];
	int fd;
	mkfifo("newfifo1",0644);	//fifo is created
	perror("mkfifo");
	printf("before open()......\n");
	fd=open("newfifo1",O_WRONLY);	//open fifo file for write only
	printf("After opening..\n");
	printf("enter the data \n");
	scanf("%s",s1);
	write(fd,s1,strlen(s1)+1);		//writing the data in to fifo
	return 0;
}
	// this fifo for file for writing the data
