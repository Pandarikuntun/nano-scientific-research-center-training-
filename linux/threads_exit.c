#include<stdio.h>
#include<pthread.h>
pthread_t pth1,pth2,pth3;
void thread1(void *arg){
printf("thread1 is executing\n");

}
void thread2(void *arg){
printf("thread2 is executing\n");
}
void thread3(void *arg){
printf("thread3 is executing\n");
}
int main(){
int ret1=pthread_create(&pth1,NULL,thread1,NULL);
int ret2=pthread_create(&pth2,NULL,thread1,NULL);
int ret3=pthread_create(&pth3,NULL,thread1,NULL);
if(ret2 |ret3 )
printf("thread is not created");
else
printf("thread is created\n");
pthread_join(pth1,NULL);
pthread_join(pth1,NULL);
pthread_join(pth1,NULL);

return 0;
}
