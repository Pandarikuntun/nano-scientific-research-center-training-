#include<reg51.h>
void deley(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=i;j<100;j++);
}
int main(){
			P2=0x00;
	while(1){
		P2^=((1<<0)|(1<<2)|(1<<4)|(1<<6));
		deley();
		
	}
	return 0;
}