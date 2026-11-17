#include<stdio.h>
int main(){
	int pid;
	printf("current process pid =%d\n",getpid());
	pid = fork();
	if(pid==0){
	sleep(2);
		printf("embedded\n");
		printf("parrent process pid =%d\n",getpid());
	sleep(10);

	}
	else{
	sleep(2);
		printf("technology\n");
		printf("child process pid =%d\n",getpid());
	}
	return 0;
}
