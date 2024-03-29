#include <p18f4550.h>

#pragma config FOSC = HS //Oscillator Selection
#pragma config WDT = OFF //Disable Watchdog timer
#pragma config LVP = OFF //Disable Low Voltage Programming
#pragma config PBADEN = OFF //Disable PORTB Analog inputs

void myMsDelay (unsigned int time)  // Definition of delay subroutine
{
    unsigned int i, j;
    for (i = 0; i < time; i++)      // Loop for itime
        for (j = 0; j < 710; j++);  // Calibrated for a 1 ms delay in MPLAB
}

void main()
{ 
    TRISCbits.TRISC2 = 0 ;  // Set PORTC, RC2 as output (CCP1)
    TRISCbits.TRISC6 = 0 ;  // Set PORTC, RC6 as output (DCM IN3)
    TRISCbits.TRISC7 = 0 ;  // Set PORTC, RC6 as output (DCM IN4)
    PR2 = 0x4E;             // set PWM Frequency 4KHz  
    CCP1CON = 0x0C;         // Configure CCP1CON as PWM mode.
    T2CON = 0x07;       //Start timer 2 with prescaler 1:16
    PORTCbits.RC6 = 1;  // Turn ON the Motor
    PORTCbits.RC7 = 0;
  while(1)  // Endless Loop
    {
    
        
        
        // -----------------------------------
        // ----------Duty Cycle 80%-----------
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 1;
        CCPR1L = 0x3E;
        myMsDelay(2000);
        // -----------------------------------
        // -----------------------------------
        // ----------Duty Cycle 60%-----------
        CCP1CONbits.DC1B0 = 1;
        CCP1CONbits.DC1B1 = 1;
        CCPR1L = 0x2E;
        myMsDelay(2000);
        // -----------------------------------
        // ----------Duty Cycle 40%-----------
        CCP1CONbits.DC1B0 = 1;
        CCP1CONbits.DC1B1 = 0;
        CCPR1L = 0x1F;
        myMsDelay(2000);
        // ----------Duty Cycle 20%-----------
        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 1;
        CCPR1L = 0x0F;
        myMsDelay(2000);
    }   
 
}

