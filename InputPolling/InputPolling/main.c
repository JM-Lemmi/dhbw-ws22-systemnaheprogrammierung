/*
 * InputPolling.c
 *
 * Created: 03/12/2022 12:00:42
 * Author : julian.lemmerich
 */ 

#define F_CPU 16000000UL // aktuelle Prozessorfrequenz setzen
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	// PB5 als Ausgang
	DDRB = (1 << DDB5);
	// PD2 und PD3 als Eingang (Ales auf Port D)
	DDRD = 0;
	
	// Pull auf D2 und D3
	PORTD = (1 << PORTD2) | (1 << PORTD3);
	
    /* Replace with your application code */
    while (1) 
    {
		// messen ob D2 gesetzt ist
		if((PIND & (1 << PIND2)) == 0) {
			PORTB = (1 << PORTB5);
		}
		
		// messen ob D3 gesetzt ist
		if((PIND & (1 << PIND3)) == 0) {
			PORTB = 0;
		}
    }
}

