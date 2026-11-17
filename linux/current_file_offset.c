#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
int fd,len;
char wr_buf[50]="hi how are you ? waoww ";
char rd_buf[50];
fd=open("/home/pandari/Desktop/ram/ram_txt/offset.txt",O_CREAT|O_RDWR,0777);
len=write(fd,wr_buf,50);
printf("return value from %d\n",len);
		//close(fd);
		lseek(fd,0,SEEK_SET);
read(fd,rd_buf,len);
printf("data recorded from : %s\n",rd_buf);
close(fd);
return 0;
}
