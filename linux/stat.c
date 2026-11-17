#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
struct stat my;
int fd;
	//fd=open("read.c",O_RDONLY);
	//fstat(fd,&my);
	//struct stat *ptr;
	
	
stat("read.c",&my);
printf("file size =%lu\n",my.st_size); 	//ls -l
printf("file inode =%lu\n",my.st_ino);   //ls -i
printf("\n\n");
close(fd);
return 0;
}
