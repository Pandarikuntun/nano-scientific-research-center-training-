#include<reg51.h>
sbit led=P1^0;
void delay(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=i;j<100;j++);
	
int main(){
	while(1){
		led=1;
		delay();
		led=0;
		}
}