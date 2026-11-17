#include<stdio.h>
#include<pthread.h>

void *start_1(void *arg){
	int i;
	for(i=0;i<10;i++)
	printf("thread one is executing\n");
}
void *start_2(void *arg){
	int i;
	for(i=0;i<10;i++)
	printf("thread twos is executing\n");
}
int main(){
	pthread_t pt1,pt2;
	//getchar();
	pthread_create(&pt1,NULL,start_1,NULL);
	pthread_create(&pt2,NULL,start_2,NULL);
	
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);
	
	printf(" the main program ends heare\n");
}
