#include<reg51.h>
void delay(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=i;j<100;j++);
}
int main(){
	P1=0x00;
	while(1){
		P1 ^=(1<<0);
		delay();
	}
}