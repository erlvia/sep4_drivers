#include "pir.h"
#include "includes.h"


//signal
#define DDR_sig DDRD
#define P_sig PD2
#define PORT_sig PORTD
#define PIN_sig PIND




static pir_callback_t pir_callback = NULL;

#ifndef WINDOWS_TEST
ISR(INT2_vect) {
    
    
    pir_callback();

    /*
    // Check if PK4 changed state
    if (PIN_sig & (1 << P_sig)) {
        // High: Motion detected
        if (pir_callback) {
            
        }
    } else {
        // Low: No motion
        // You can also call a different callback here if needed
    }*/
}
#endif

void pir_init(pir_callback_t callback) {



//Set PK4 as input and enable pullupresistor
    DDR_sig &= ~(1 << P_sig);
    PORT_sig |= (1 << P_sig);

    // Enable pin change interrupt on PCINT20 (PK4)
    EICRA |= (1 << ISC20) | (1 << ISC21);  // Set INT2 to trigger on rising edge
    EIMSK |= (1 << INT2);  // Enable external interrupt INT2

    // Set the callback
    pir_callback = callback;

    // Enable global interrupts
    sei();
}