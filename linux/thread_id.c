#include<stdio.h>
#include<pthread.h>
pthread_t trd;
void *thread_fun(void *arg){
	pid_t pid;
	pthread_t trd;
	pid = getpid();
	trd = pthread_self();
	printf("pid %u thread id %u\n",(unsigned int) pid,(unsigned int) trd);
	
	}
int main(){
	int err;
	err= pthread_create(&trd,NULL,thread_fun,NULL);
	if(err !=0)
	printf(" cant creat thread :%s \n",strerror(err));
	pthread_join(trd,NULL);
	return 0;
}
