#include<reg51.h>
sbit led =P1^0;
sbit sw = P1^1;
int main(){
	while(1){
		if(sw==1){
			led=1;
		}
			else{
				led=0;
		}
	}
}