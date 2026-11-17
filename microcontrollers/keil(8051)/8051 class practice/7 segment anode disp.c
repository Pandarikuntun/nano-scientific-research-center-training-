#include<reg51.h>
void delay(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=i;j<1000;j++);
}	
int main(){
	unsigned char a[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0XF8,0x80,0x98};
	int i;
	while(1){
		for(i=0;i<10;i++){
			P2=a[i];
			delay();
		}
	}
}
