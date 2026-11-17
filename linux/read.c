#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	char buf[500];
	int fd;
	int res;
	//fd=creat("/home/pandari/Desktop/ram/ram_txt/one1.txt",O_CREAT);
	fd=open("open.c",O_RDONLY,777);
	res =read(fd,buf,300);
	printf("fd=%d\n",fd);
	printf(" %s\n",buf);
	close(fd);
return 0;
}
