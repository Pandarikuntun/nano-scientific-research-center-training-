#include<stdio.h>
#include<unistd.h>
int main(){
printf("maxfds:%d\n",getdtablesize());
exit(0);
}
