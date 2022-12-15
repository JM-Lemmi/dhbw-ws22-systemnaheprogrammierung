/*
 * FadeLED.c
 *
 * Created: 15/12/2022 09:48:41
 * Author : julian.lemmerich
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


static uint8_t direction = 1;

void move(uint8_t speed) {
	OCR0A += direction * speed;
	if(255 - OCR0A <= speed || OCR0A < speed) {
		direction *= -1;
	}
}

int main(){
	DDRD |= (1 << DDD6);
	
	// 256 * duty / 100
	OCR0A = 256.0 * 0.75; // 75% duty cycle
	// set non-inverting mode
	TCCR0A |= (1 << COM0A1);
	
	// set fast PWP mode
	TCCR0A |= (1 << WGM01) | (1 << WGM00);
	
	// set prescaler to 8 and start PWM
	TCCR0B |= (1 << CS01);
	
	while(1) {
		_delay_ms(10);
		move(1);
	}
}