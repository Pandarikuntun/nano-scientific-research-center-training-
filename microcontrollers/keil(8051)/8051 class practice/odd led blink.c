#include<reg51.h>
void lag(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=i;j<1000;j++);

}
void main(){
	P1 =0x00;
	P1 |=((1<<1)|(1<<3)|(1<<5)|(1<<7));
	lag();
	P1 &=~((1<<1)|(1<<3)|(1<<5)|(1<<7));
	lag();
}