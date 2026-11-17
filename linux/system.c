#include<stdio.h>
#include<unistd.h>
int main(){
	int result,result2;
	printf("I am going to execute system() function\n");
	result=system("pwd \n");
	wait(1);
	sleep(10);
	result2=system("ls -l\n");
	printf(" i executed program \n");
	printf("Return value of system lib call %d\n %d\n",result,result2);
	return 0;
}
//system() executed -------internally fork() called
//parent-------wait()
//child--------------execl("/bin/ls"---);
