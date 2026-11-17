#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main(){
	char s2[20];
	int fd;
	mkfifo("newfifo1",0644);	//fifo is created
	
	printf("before open()......\n");
	fd=open("newfifo1",O_RDONLY);	//open fifo file for write only
	printf("After opening..\n");
	printf("read the data \n");
	read(fd,s2,sizeof(s2));		//writing the data in to fifo
	return 0;
}
	// this fifo for file for writing the data
