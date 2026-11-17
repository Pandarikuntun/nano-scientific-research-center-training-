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

