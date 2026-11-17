#include<reg51.h>
sbit LED = P1^1;
void delay(int n){
	int i,j;
	for(i=0;i<n;i++)
	for(j=i;j<100;j++);
}
void main(){
	while(1){
		LED=1;
		delay(100);
		LED=0;
		delay(100);
	}
}