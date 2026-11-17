#include<stdio.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/types.h>
#include<sys/msg.h>


int main(){
	int msgid = msgget(55, IPC_CREAT|0644);
	if(msgid<0){
	perror("msgget");
	return 0;
	}	
	//printf("id=%d\n",msgid);
	struct message{
	long type;
	char text[20];
	}msg;
	long msglng=1;
	msgrcv(msgid,(void *)&msg,sizeof(msg.text),msglng,MSG_NOERROR | IPC_NOWAIT);
	printf("%s \n",msg.text);
	
	return 0;
}
