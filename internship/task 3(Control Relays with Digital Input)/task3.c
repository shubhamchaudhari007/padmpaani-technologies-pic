#include <p18f4550.h>

// Configuration bits
#pragma config FOSC = HS    // High-Speed Crystal Oscillator
#pragma config WDT = OFF    // Watchdog Timer OFF

// Define switch and relay pin assignments
#define SWITCH1_PIN   PORTBbits.RB0
#define SWITCH2_PIN   PORTBbits.RB1
#define RELAY1_PIN    PORTCbits.RC0
#define RELAY2_PIN    PORTCbits.RC1
void main(){

	unsigned char val=0;        //Variable to latch the switch condition
    INTCON2bits.RBPU=0;         //To Activate the internal pull on PORTB
    ADCON1 = 0x0F;              //To disable the all analog inputs  


    TRISBbits.RB0 = 1; // Configure RB0 as input
    TRISBbits.RB1 = 1; // Configure RB1 as input
    TRISCbits.RC0 = 0; // Configure RC0 as output
    TRISCbits.RC1 = 0; // Configure RC1 as output
    
    
    RELAY1_PIN = 0;  // relay1 off
    RELAY2_PIN = 0;  // relay2 off

	while(1){
	

    if (!(SWITCH1_PIN))  //if switch1 is not pressed
        val = 1;         // val is equal to 1

    if (!(SWITCH2_PIN))  // if switch 2 is not pressed
        val = 2;         // val is 2
    
	if(val == 1){        
	RELAY1_PIN = 1;
	}
	if(val == 2){
	RELAY2_PIN = 1;
	}
}


}
