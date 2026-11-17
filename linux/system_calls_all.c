#include<stdio.h>
#include<sys/types.h>		//fork  + parent wait + child execl
#include<sys/wait.h>
int main(){
	pid_t pid;
		pid=fork();
		if(pid==0){
			printf(" PID of chid process =%d\n",getpid()); //pid=1122
			printf("i am child pro running is program \n");
			execl("/ls","-l",0);		//ls -l main.............return 0
		sleep(10);
wait(0);
		}

		printf("PID of parent process =%d\n",getpid());	//pid parent =1121
		printf("Parent waiting for child process\n");
//		wait(0);	//wait() parent suspended
				//child teminated parent unblock ...wait return terminated pid into new pid.....
				//wait() fetch / get terminated process exit code(5) into stsrt var
		printf("parent terminates after child execution\n");
		return 0;
}
