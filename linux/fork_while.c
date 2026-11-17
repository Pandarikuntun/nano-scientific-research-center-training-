#include<stdio.h>
int main(){
	int pid;
	int cnt=0;
	printf("current process pid =%d\n",getpid());
	pid = fork();
	if(pid)
	{
		while(cnt<10)
		{	
			cnt++;
			printf("embedded\n");
			printf("parrent process pid =%d\n",getpid());
		sleep(7);
		}

	}
	else
	{
		while(cnt<20)
		{
			cnt++;
			printf("technology\n");
			printf("child process pid =%d\n",getpid());
			sleep(5);
		}
	}
	return 0;
}
