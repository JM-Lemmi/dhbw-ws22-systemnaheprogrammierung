/*
 * Ampel.c
 *
 * Created: 03/12/2022 10:18:16
 * Author : julian.lemmerich
 */ 

#define F_CPU 16000000UL // aktuelle Prozessorfrequenz setzen
#include <avr/io.h>
#include <util/delay.h>

#define ROT PORTB3
#define GELB PORTB4
#define GRUN PORTB5

// gelb (2000) -> rot (2000) -> rotgelb (2000) -> gr�n (2000)


int main(void)
{
	// Data Direction Register
	DDRB = (1 << DDB5) | (1 << DDB4) | (1 << DDB3); // gesetztes Bit ist Ausgang. DDB5 ist eine Konstante f�r den Ausgang, das k�nnte man auch durch "5" ersetzen, aber sp�ter wird das sinnvoll.
	
    /* Replace with your application code */
    while (1) 
    {
		// gelb
		PORTB = (1 << GELB);
		_delay_ms(500);
		
		// rot
		PORTB = (1 << ROT);
		_delay_ms(2000);
		
		// rotgelb
		PORTB = (1 << GELB) | (1 << ROT);
		_delay_ms(500);
		
		// gr�n
		PORTB = (1 << GRUN);
		_delay_ms(2000);
    }
}

