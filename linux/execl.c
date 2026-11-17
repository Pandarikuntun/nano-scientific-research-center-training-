#include<stdio.h>
int main(){
	printf("current process pid =%d\n",getpid());
	printf("current process pid =%d\n",getpid());
	execl("/home/pandari/Desktop/ram/ram_c/a.out","./a.out",0);
	printf("current process pid =%d\n",getpid());
	printf("current process pid =%d\n",getpid());
	return 0;
	}
	/*when execl system call is called the corrent process date will replaced with new deta 
	ofter the excel call data cannot be execute it will be stoped*/
	
