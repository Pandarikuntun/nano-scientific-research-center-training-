#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
	int  pid;
	printf("current process pid =%d\n",getpid());
	pid=fork();
	if(pid==0){
	printf(" parent\n");
	printf("parent process pid =%d\n",getpid());
	}
	else{
	printf("child\n");
	printf("child process pid =%d\n",getpid());
	}
}
