/*
 * InputInterrupt.c
 *
 * Created: 03/12/2022 13:37:37
 * Author : julian.lemmerich
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

ISR(INT0_vect){
	cli(); // global alle interrupts abschalten, damit es keine verschachtelung geben kann
	PORTB = (1 << PORTB5);
	sli(); // interrupts wieder anschalten
}
ISR(INT1_vect){
	PORTB = 0;
}


int main(void)
{
	// PB5 als Ausgang
	DDRB = (1 << DDB5);
	// PD2 und PD3 als Eingang (Ales auf Port D)
	DDRD = 0;
		
	// Pull auf D2 und D3
	PORTD = (1 << PORTD2) | (1 << PORTD3);
	
	EICRA = (1 << ISC11) | (1 << ISC01); // verhalten (rising oder falling. ISC1 ist der interruptor und dann entweder 1 für falling und 0 für rising)
	EIMSK = (1 << INT0) | (1 << INT1); // aktivieren der interrupts
	
	sei(); // globale aktivierung aller interrupts
	
    /* Replace with your application code */
    while (1) 
    {
		// die schleife darf nicht weg, auch wenn sie leer ist, damit das Programm nicht terminiert
    }
}

