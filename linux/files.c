#include<stdio.h>
int main(){
int fd;
fd=creat("new.txt");
close(fd);
}
