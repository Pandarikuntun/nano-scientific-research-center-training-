//function pointer
#include<stdio.h>
int tik(int x,int y){
	return x+y;
}
int main(){
	int (*k)(int,int);
	k=&tik;	
	printf("%d",k(5,5));
	return 0;
}
