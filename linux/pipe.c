#include<stdio.h>
#include<string.h>
int main(){
	int p[2]; //p[0] p[1] index of pipe or subscript of array
	pipe(p); //p[0] read end p[1] for write end
	printf(" read end of pipe =%d\t write end of pipe =%d\n ",p[0],p[1]);
	if(fork()){
		char s[20];
		printf("in a perent enter a data \n");
		scanf(" %s ",s);
		write(p[1],s,strlen(s)+1); // parent send data on pipr write(fd,buf,20)
	}
	else{
		char buf[20];
		printf("in a child receive a data \n");
		read(p[0],buf,sizeof(buf)); // parent send data on pipr read(fd,buf,sizeof_buf)
		printf("child printing the data of perent process  %s\n",buf);
	}
	return 0;
}
