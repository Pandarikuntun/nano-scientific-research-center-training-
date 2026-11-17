#include<stdio.h>
int main(){
	char buf1[20];
	char buf2[20];
	int ret;
	memcpy(buf1,"madam",5);
	memcpy(buf2,"mad",5);
	
	ret=memcmp(buf1,buf2,5);
	printf("ascii value is %d\n",ret);
	
	if(ret>0){
	printf("buf1 is greterthen buf2\n");
	}
	else if(ret<0){
	printf("buf2 is greterthen buf2\n");
	}
	else{
	printf(" buf1 and buf are equal\n");
	}
	
	return 0;
}
