#include<stdio.h>
#include<pthread.h>
pthread_t tid;

void thread1(void *srg){
printf("newly created thread executing delay 2 sec   \n");
sleep(2);
return NULL;
}
int main(){
	int ret=pthread_create(&tid,NULL,thread1,NULL);
	if(ret){
		printf("thread is not created\n");
	}
	else{
	printf("thread is created \n");
	//sleep(1);
	ptread_join(tid,NULL);
	}
	return 0;
}
