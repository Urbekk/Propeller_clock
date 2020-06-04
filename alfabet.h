#ifndef ALFABET_H_
#define ALFABET_H_

#include <avr/io.h>
#include <util/delay.h>

#define D1 (1<<PD0)
#define D2 (1<<PD1)
#define D3 (1<<PC4)
#define D4 (1<<PD3)
#define D5 (1<<PD4)
#define D6 (1<<PD5)
#define D7 (1<<PD6)
#define D8 (1<<PD7)
#define D9 (1<<PC2)
#define D10 (1<<PC3)

void _1(){
	PORTD |= D1|D2|D4|D5|D6|D7|D8;
	PORTC |= D3|D9|D10;
	_delay_us(300);
	PORTD ^= D1|D2|D4|D5|D6|D7|D8;
	PORTC ^= D3|D9|D10;
}
void _2(){
	PORTD |= D1|D5|D6|D7|D8;
	PORTC |= D9|D10;
	_delay_us(300);
	PORTD ^= D6|D7|D8;
	PORTC ^= D9;
	_delay_us(1000);
	PORTD |= D2|D4;
	PORTC |= D3;
	_delay_us(300);
	PORTD ^= D1|D2|D4|D5;
	PORTC ^= D3|D10;
}
void _3(){
	PORTD |= D1|D5;
	PORTC |= D10;
	_delay_us(1250);
	PORTD |= D2|D4|D6|D7|D8;
	PORTC |= D3|D9;
	_delay_us(300);
	PORTD ^= D1|D2|D4|D5|D6|D7|D8;
	PORTC ^= D3|D9|D10;
}
void _4(){
	PORTD |= D1|D2|D4|D5;
	PORTC |= D3;
	_delay_us(300);
	PORTD ^= D1|D2|D4;
	PORTC ^= D3;
	_delay_us(1000);
	PORTD |= D1|D2|D4|D6|D7|D8;
	PORTC |= D3|D9|D10;
	_delay_us(300);
	PORTD ^= D1|D2|D4|D5|D6|D7|D8;
	PORTC ^= D3|D9|D10;
}
void _5(){
	PORTD |= D1|D2|D4|D5;
	PORTC |= D3|D10;
	_delay_us(300);
	PORTD ^= D2|D4;
	PORTC ^= D3;
	_delay_us(1000);
	PORTD |= D6|D7|D8;
	PORTC |= D9;
	_delay_us(300);
	PORTD ^= D1|D5|D6|D7|D8;
	PORTC ^= D9|D10;
}
void _6(){
	PORTD |= D1|D2|D4|D5|D6|D7|D8;
	PORTC |= D3|D9|D10;
	_delay_us(300);
	PORTD ^= D2|D4|D6|D7|D8;
	PORTC ^= D3|D9;
	_delay_us(1000);
	PORTD |= D6|D7|D8;
	PORTC |= D9;
	_delay_us(300);
	PORTD ^= D1|D5|D6|D7|D8;
	PORTC ^= D9|D10;
}
void _7(){
	PORTD |= D1;
	_delay_us(1250);
	PORTD |= D2|D4|D5|D6|D7|D8;
	PORTC |= D3|D9|D10;
	_delay_us(300);
	PORTD ^= D1|D2|D4|D5|D6|D7|D8;
	PORTC ^= D3|D9|D10;
}
void _8(){
	PORTD |= D1|D2|D4|D5|D6|D7|D8;
	PORTC |= D3|D9|D10;
	_delay_us(300);
	PORTD ^= D2|D4|D6|D7|D8;
	PORTC ^= D3|D9;
	_delay_us(1000);
	PORTD |= D2|D4|D6|D7|D8;
	PORTC |= D3|D9;
	_delay_us(300);
	PORTD ^= D1|D2|D4|D5|D6|D7|D8;
	PORTC ^= D3|D9|D10;
}
void _9(){
	PORTD |= D1|D2|D4|D5;
	PORTC |= D3|D10;
	_delay_us(300);
	PORTD ^= D2|D4;
	PORTC ^= D3;
	_delay_us(1000);
	PORTD |= D2|D4|D6|D7|D8;
	PORTC |= D3|D9;
	_delay_us(300);
	PORTD ^= D1|D2|D4|D5|D6|D7|D8;
	PORTC ^= D3|D9|D10;
}
void _0(){
	PORTD |= D1|D2|D4|D5|D6|D7|D8;
	PORTC |= D3|D9|D10;
	_delay_us(300);
	PORTD ^= D2|D4|D5|D6|D7|D8;
	PORTC ^= D3|D9;
	_delay_us(1000);
	PORTD |= D2|D4|D5|D6|D7|D8;
	PORTC |= D3|D9;
	_delay_us(300);
	PORTD ^= D1|D2|D4|D5|D6|D7|D8;
	PORTC ^= D3|D9|D10;
}
void _colon(){
	PORTD |= D4|D7|D8;
	PORTC |= D3;
	_delay_us(300);
	PORTD ^= D4|D7|D8;
	PORTC ^= D3;
}
#endif
