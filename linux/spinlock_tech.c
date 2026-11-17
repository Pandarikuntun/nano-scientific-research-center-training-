#include<stdlib.h>
#include<errno.h>
#include<bits/types.h>
#include<sys/types.h>

static pthread_spinlock_t slock;		//static pthread spinlock variable

void *spinlockThread(void *i){
	int rc;
	int count=0;
	printf("Entered thread %d getting the spin lock \n",(int *)i);
	
	rc= pthread_spin_lock(&slock);
	
	printf("%d ofter 5 sec ,thread unlock the spin lock\n",(int *)i);
	
	rc= pthread_spin_unlock(&slock);
	printf("%d thread complete\n",(int *)i);
	return NULL;
}

int main(){
	int rc=0;
	pthread_t thread,thread1;
	if(pthread_spin_init(&slock,NULL)!=0)
		perror("init");
	printf("main gets spinlock\n");
	
	rc= pthread_spin_lock(&slock);
	printf("main creats the spin lock thread\n");
	rc=pthread_create(&thread,NULL,spinlockThread,(int *)1L);
	
	printf("main wait a bit holding the spin lock\n");
	sleep(5);
	printf("main now gets unlock the  spinlock\n");
	rc= pthread_spin_unlock(&slock);
	printf("main wait for the thread to end \n");
	
	rc=pthread_join(thread,NULL);
	rc=pthread_spin_destroy(&slock);
	
	printf("main completed\n");
	return 0;
}
