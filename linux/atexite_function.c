#include<stdio.h>
#include<stdlib.h>
void fun1(){
	printf("function 1 is called\n");
	}
void fun2(){
	printf("function 2 is called\n");
	}
void fun3(){
	printf("function 3 is called\n");
	}
int main(){
	printf("regestring the fun1\n");
	atexit(fun1);
	printf("regestring the fun2\n");
	atexit(fun2);
	printf("regestring the fun3\n");
	atexit(fun3);
	
	return 0;
	}
	/* atexit function is execute the ofter execution of main function 
	then it can exicute the function reverse order last registered is execute first first registered fun execute last */
	
