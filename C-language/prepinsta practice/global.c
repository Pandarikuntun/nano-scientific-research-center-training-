#include<stdio.h>
struct test{
	int a;
	float b;
	char c;
}t;
int main(){

	printf("%d,%f,%c\n",t.a=5,t.b=2.2,t.c='c');
	printf("%d",sizeof(struct test));
	
}
