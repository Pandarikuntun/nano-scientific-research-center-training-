#include<stdio.h>
int main(){
	int pid;
	printf("current process pid =%d\n",getpid());
	pid = fork();
	if(pid){
		printf("embedded\n");
		printf("parrent process pid =%d\n",getpid());
	//sleep(10);

	}
	else{
		printf("technology\n");
		printf("child process pid =%d\n",getpid());
	}
	return 0;
}
