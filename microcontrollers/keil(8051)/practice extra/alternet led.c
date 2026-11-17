#include<reg51.h>
void delay(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=i;j<100;j++);
}
void main(){
	int i;
	while(1){
		for(i=0x01;i<0x90;i=i<<1){
			P1=i;
			delay();
		}
	}
}