#include<stdio.h>
#include<fcntl.h>
int main(){	
	int fd1;
	fd1=open("/home/pandari/Desktop/ram/ram_txt/one.txt",O_RDONLY,777);
	printf("fd1 value return by linux =%d\n",fd1);

	pclose(fd1);

	return 0;
}
