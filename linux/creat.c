#include<stdio.h>
//#include<unistd>
int main(){
	int fd;
	fd=creat("/home/pandari/Desktop/ram/ram_txt/one.txt",767);
	printf("fd=%d\n",fd);
	close(fd);
	return 0;
	
}
