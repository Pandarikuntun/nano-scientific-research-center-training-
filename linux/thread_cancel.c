#include<stdio.h>
#include<pthread.h>

void *printhello(void *threadid){
	printf("\n hello world\n");
	printf("\n %u \n ",pthread_self());
	printf("iam waiting \n");
	while(1);
	}

int main(){
	pthread_t thread;
	int rc,t;
	pthread_create(&thread,NULL,printhello,NULL);
	printf("\n thread id :%u",thread);
	sleep(5);
	t=pthread_cancel(thread);
	if(t==0)
	printf("\n thread is cancled\n");
	printf("thread id =%d\n",thread);
	}
