#include<stdio.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/types.h>


int main(){
	int msgid = msgget(55, IPC_CREAT|0644);
	
	
	
	printf("id=%d\n",msgid);
	struct message{
	long type;
	char text[20];
	}msg;
	msg.type=1;
	strcpy(msg.text," this is message 1");
	msgsnd(msgid,(void *)&msg,sizeof(msg.text),IPC_NOWAIT);
	strcpy(msg.text,"his is message 2");
	msgsnd(msgid,(void *)&msg,sizeof(msg.text),IPC_NOWAIT);
	
	return 0;
}
