#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	printf(" tulasiram \n");
	fork();
	fork();
	fork();
	fork();
	printf(" pandari\n" );
	while(1);
	return 0;
	}
