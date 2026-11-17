#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
int pid;
pid=fork();
if(pid){
	printf(" ram technology\n");
	}
	else{
	while(1){
		printf("embedded technology\n");
		//
		exit (0);
		return 0;
	}
	}
return 0;
}
/*we are running the non termination process or infinity loop 
\in a program we should use the 
exit(0); or return 0; it is normal termination 
when at running the process it will newer terminate 
it is called the abnormal termination we externelly 
give the termination interrupts to the system that is 
{CTRL + C } it will terminates
*/
