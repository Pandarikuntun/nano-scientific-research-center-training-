#include<reg51.h>
void delay(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=i;j<1000;j++);
}	
int main(){
	unsigned char a[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
	int i;
	while(1){
		for(i=0;i<10;i++){
			P2=a[i];
			delay();
		}
	}
}
