/*
 * 01-HelloWorld.c
 *
 * Created: 25/11/2022 11:10:22
 * Author : Julian Lemmerich
 */ 

#define F_CPU 16000000UL // aktuelle Prozessorfrequenz setzen
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Data Direction Register
	DDRB = (1 << DDB5); // gesetztes Bit ist Ausgang. DDB5 ist eine Konstante für den Ausgang, das könnte man auch durch "5" ersetzen, aber später wird das sinnvoll.
	PORTB = (1 << PORTB5); // B5 wird jetzt auf high gesetzt.

	// Application
    while (1) 
    {
		// &= ist einfach ein abgekürzter operator für PORTB & was auch immer danach kommt
		// c = c + a ist das gleiche wie c+= a
		// wir erstellen hier mit 1 << PORTB5 eine Bitmaske, die wird dann negiert und mit dem aktuellen Port verundet
		// es wird hier also ausgeschaltet, weil das Bit im endeffekt auf 0 gesetzt wird.
		PORTB &= ~(1 << PORTB5);
		_delay_ms(500);
		
		PORTB |= (1 << PORTB5);
		_delay_ms(500);
    }
}

