#include<reg51.h>

sbit moterp = P1^0;  // Assuming moterp is connected to P1.0
sbit motern = P1^1;  // Assuming motern is connected to P1.1

void main() {
  unsigned int i;
	moterp=motern=0;
	while(1) 
		{
		moterp = 1;
    motern = 0;
    for(i = 0; i <60000; i++);
    moterp = 0;
    motern = 1;
    for(i = 0; i <60000; i++);
    }
}
