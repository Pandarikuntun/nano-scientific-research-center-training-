#include<reg51.h>
#include<stdio.h>
sbit S =P1^0;  // sensor IR
sbit R =P1^1;  // BUTTON
char Rx;
void delay(int n) {			//delay 
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i; j < 100; j++);
    }
}
//---------------------
void serial_init() {
    TMOD = 0x20;   // Timer1 in Mode2 for baud rate generation
    TH1 = 0xFD;    // 9600 baud rate for 11.0592MHz crystal
    SCON = 0x50;   // Serial mode 1, REN enabled
    TR1 = -3;       // Start Timer1
		TI = 0;
}
void transmit_char(char ch) {
    SBUF = ch;         // Send character
    while(TI == 0);    // Wait for transmission
    TI = 0;            // Clear flag
}
void transmit_string(char *str) {
    while(*str)
        transmit_char(*str++);
}

void led_switch(){
	        if (S ==1 && R==1) {
            P2 &= ~(1<<0);  // led on
        } else {
            P2 |= (1<<0);		//len off
        }
}

/////////////// BT FuNCTION//////////////////------
void blutooth_fun(){
	
	if(RI==1){
	Rx=SBUF;
	SBUF=Rx;
	RI=0;
		transmit_char(Rx);
				if(Rx=='1'){
					P2 |=(1<<1);			//led 1 on
				}
				else if(Rx=='2'){
					P2 &=~(1<<2);						//led 2 on
				}
				else if(Rx=='3'){
					P2 &=~(1<<3);						//led 3 on
				}
				else if(Rx=='0'){					// 3 led's off
					P2 &=~(1<<1);
					P2 |=(1<<2);
					P2 |=(1<<3);
				}
				else{
				//transmit_string("\ninvalid number\n");			// invalid key pressed
				}
			}
}
//------------------------

void main(){
		
   P2 = 0xFF;
	 //P3 = 0x00;
	serial_init();
	delay(10);
	transmit_string("blutooth is redy connect now\n");
	delay(10);
    while (1) {
         //---------------
			led_switch();
				//----------------------------	
		blutooth_fun();
				//----------------------------*/
				
		}
}