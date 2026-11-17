#include<stdio.h>
#include<sys/mman.h>
#include<string.h>
int main(){
	char *c;
	
	c=mmap(0,50,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,-1,0);			// maping
	perror("mmap");
	strcpy(c,"linuxkernel");
	printf("%s\n",c);
	munmap(c,50);		//un mapping or free the memory
	
	//printf("%s\n",c);   //ofter freeing the we cannot access the memory it can give segmntation falt or core damped error
	
	return 0;
}
