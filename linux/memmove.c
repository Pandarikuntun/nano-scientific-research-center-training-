#include<stdio.h>
int main(){
	char dest[]="oldstring";
	const char src[]="newstring";
	printf("before move option dest=%s source=%s\n",dest,src);
	memmove(dest,src,9);
	printf("ofter move option dest=%s source=%s\n",dest,src);
	return 0;
}
