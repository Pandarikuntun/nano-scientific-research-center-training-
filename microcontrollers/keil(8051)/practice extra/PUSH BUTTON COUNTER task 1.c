#include <reg51.h>  //8051 header file 

// -------LCD PIN DEFINITIONS ------------ 
sbit RS = P2^0;       // Register Select pin
sbit RW = P2^1;       // Read/Write pin
sbit EN = P2^2;       // Enable pin

//------ ADC PIN DEFINITIONS ---------- 
#define adc_data P1   // 8-bit ADC output connected to Port 1

sbit ale   = P3^0;    // Address Latch Enable
sbit start = P3^1;    // Start Conversion
sbit eoc   = P3^2;    // End of Conversion (Active High)
sbit oe    = P3^3;    // Output Enable

//================ DELAY FUNCTION ==============
void delay(unsigned int t) {
    unsigned int i, j;
    for(i = 0; i < t; i++)
        for(j = 0; j < 1275; j++);
}

// ============ LCD COMMAND  ===========
void lcd_cmd(unsigned char cmd) {
    RS = 0;        // Command mode
    RW = 0;        // Write mode
    P0 = cmd;      // Send command on port
    EN = 1;        // High pulse
    delay(1);
    EN = 0;
}

// =========== LCD DATA  ==============
void lcd_data(unsigned char dat) {
    RS = 1;        // Data mode
    RW = 0;
    P0 = dat;      // Send character
    EN = 1;
    delay(1);
    EN = 0;
}

//=============== LCD INITIALIZATION ======
void lcd_init() {
    lcd_cmd(0x38);  // 8-bit mode, 2 lines
    lcd_cmd(0x0C);  // Display ON, Cursor OFF
    lcd_cmd(0x06);  // Auto increment
    lcd_cmd(0x01);  // Clear display
    delay(2);
}

//========== SEND STRING TO LCD =====
void lcd_string(char *s) {
    while(*s)
        lcd_data(*s++);
}

//=========== ADC0804 READ FUNCTION ========
unsigned char read_adc() {
    ale = 1;       // Latch address
    start = 1;     // Start ADC conversion
    delay(1);

    ale = 0;
    start = 0;

    while(eoc == 0);  // Wait until conversion complete (EOC=1)

    oe = 1;       // Enable ADC output
    delay(1);
    oe = 0;

    return adc_data;  // Return 8-bit ADC result
}

//========= MAIN PROGRAM ==========
void main() {
    unsigned char adc_value;
    unsigned int temp_c;

    lcd_init();                 // Initialize LCD
    lcd_string("TEMP SENSOR:"); // LCD Line1 text
    lcd_cmd(0xC0);              // Move to second line

    while(1) {
        adc_value = read_adc();  // Read ADC value (0–255)

        /// Convert ADC value to temperature (LM35: 10mV/°C)
         //ADC input range = 0–5V
         Temperature (°C) = (adc_value * 500) / 255
        temp_c = (adc_value * 500) / 255;
				
			
        lcd_cmd(0xC0);          // Move to Line 2
        lcd_string("Temp: ");

        lcd_data((temp_c/100) + '0');       // Hundreds digit
        lcd_data(((temp_c/10)%10) + '0');   // Tens digit
        lcd_data((temp_c%10) + '0');        // Ones digit

        lcd_data(0xDF);  // Degree symbol
        lcd_data('C');   // Display C

        delay(300);
    }
}
