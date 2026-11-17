#include<stdio.h>
#include<pthread.h>
//#include<mutex.h>
int sharedvar=0;			//our shared variable
pthread_key_t my_mutex;				//creat semaphore
void *thread_inc1(void *arg){
	int i;
	sem_wait(&my_mutex);		//take semaphore
	for(i=0;i<100;i++)
	sharedvar++;			//critical section
	printf("sharedvar =%d \n",sharedvar);	
			
	sem_post(&my_mutex);		//release semaphore
}

void *thread_inc2(void *arg){
	int i;
	sem_wait(&my_mutex);		//take semaphore
	for(i=0;i<100;i++)
	sharedvar++;
	printf("sharedvar =%d \n",sharedvar);
				//critical section
	sem_post(&my_mutex);		//release semaphore
return 0;
}
int main()
{
	pthread_t thread1,thread2;
	sem_init(&my_mutex,0,1);					//initialize semaphore

	pthread_create(thread1,NULL,thread_inc1,NULL);
	pthread_create(thread2,NULL,thread_inc2,NULL);
	
	pthread_join(thread1,NULL);
	
	pthread_join(thread2,NULL);		//proces suspended by until process 1 termination
	
	printf("sharedvar =%d \n",sharedvar);
	return 0;
}

