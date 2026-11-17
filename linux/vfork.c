#include<stdio.h>
int main(){
int pid;
printf("current process =%d\n",getpid());
pid=vfork();
if(pid){
	//sleep(5);
	printf("parent process =%d\n",getpid());
	}
	else{
	sleep(5);
	printf("child process =%d\n",getpid());
	}
	return 0;
	
}
/*the parent process is suspended 
 until child process termination, clid is terminated the parent process is start execution*/ 
