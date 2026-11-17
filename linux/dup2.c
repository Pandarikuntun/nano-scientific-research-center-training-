#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd1,fd2,fd3,fd4;
	fd1=open("/home/pandari/Desktop/ram/ram_txt/dup.txt",O_RDONLY|O_CREAT|O_TRUNC,0777);
	fd2=open("/home/pandari/Desktop/ram/ram_txt/dup2.txt",O_RDONLY|O_CREAT|O_TRUNC,0777);
	printf("fd1=%d\n",fd1);
	printf("fd2=%d\n",fd2);
	fd3=dup(fd1);
	fd4=dup2(fd2,2);
	printf("fd3 dup of fd1=%d\n",fd3);
	printf("fd4 dup of fd2=%d\n",fd4);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	}
	
