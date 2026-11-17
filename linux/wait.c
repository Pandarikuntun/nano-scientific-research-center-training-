#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int pid1;
	pid1=fork();
	if(pid1==0){
		sleep(10);
		printf("i am a child process my pid is =%d\n",getpid());
		}
	else{
		int pid2;
		printf("i am a parent process my pid is =%d\n",getpid());
		pid2=wait(0);
		printf("parentt is saying the %d exited /terminated normally \n",pid2);
		printf("iam parent process my pids =%d\n",getpid());
		}
	return 0;
}
/* tha wait system call can be call in parent process only in 
child we called it shos the error tha wait is used for suspend 
the parent process for until child process terminatipn of child 
process then execute the parent process
*/
