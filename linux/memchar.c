#include<stdio.h>
int main(){
	const char str[]="linuxkernel.com";
	const char ch='.';
	char *ret;
	ret = memchr(str,ch,strlen(str));
	printf("ofter the memchar %c and the value is %s \n" ,ch,ret);
	printf("ofter the memchar %c and the value is - 2 is %s \n" ,ch,ret-2);
	printf("ofter the memchar %c and the value is + 2 is %s \n" ,ch,ret+2);
	return 0;
}
