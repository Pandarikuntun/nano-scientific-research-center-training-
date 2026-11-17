#include<stdio.h>
#include<string.h>
int main(){
	const char str[]="linuxkernel.com";
	const char ch='*';
	printf(" before memset %s \n",str);
	memset(str,ch,5);
	printf("ofter the memset %s\n",str);
	return 0;
}
