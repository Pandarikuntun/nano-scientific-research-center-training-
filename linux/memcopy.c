#include<stdio.h>
int main(){
	const char dest[]="embedded_system";
	const char src[]="newlinux";
	printf("before the memcopy destination is %s source %s\n",dest,src);
	memcpy(dest,src,strlen(src));
	printf("ofter the memcopy destination is %s source %s\n",dest,src);
	return 0;
}
