#include <avr/io.h>
#include <util/delay.h>
#include "alfabet.h"
#include "I2C.h"
#include <stdlib.h>

#define DS3231_ADDR 0xD0
#define REF_VCC (1<<REFS0)
#define REF_256 (1<<REFS1)|(1<<REFS0)
#define PRE_128 (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)

typedef union {
	uint8_t bytes[7];
	struct {
		uint8_t ss;
		uint8_t mm;
		uint8_t hh;
		uint8_t dayofwek;
		uint8_t day;
		uint8_t month;
		uint8_t year;
	};
} TDATETIME;

uint16_t pomiar (uint8_t kanal);
void DS3231_init();
uint8_t dec2bcd(uint8_t dec);
uint8_t bcd2dec(uint8_t bcd);
void DS3231_get_datetime( TDATETIME * dt );
void show_time( TDATETIME * dt );
void DS3231_set_time( uint8_t hh, uint8_t mm, uint8_t ss ) ;

TDATETIME time;

int main(void){

	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);

	DDRD |= (1<<PD0);
	DDRD |= (1<<PD1);
	DDRC |= (1<<PC4);
	DDRD |= (1<<PD3);
	DDRD |= (1<<PD4);
	DDRD |= (1<<PD5);
	DDRD |= (1<<PD6);
	DDRD |= (1<<PD7);
	DDRC |= (1<<PC2);
	DDRC |= (1<<PC3);

	PORTD &= ~(1<<PD0);
	PORTD &= ~(1<<PD1);
	PORTD &= ~(1<<PD3);
	PORTD &= ~(1<<PD4);
	PORTD &= ~(1<<PD5);
	PORTD &= ~(1<<PD6);
	PORTD &= ~(1<<PD7);
	PORTC &= ~(1<<PC2);
	PORTC &= ~(1<<PC3);
	PORTC &= ~(1<<PC4);

	//inicjalzizacja adc
	ADCSRA |= (1<<ADEN); //w³¹cza ADC
	ADCSRA |= PRE_128; //preskaler = 128
	ADMUX |= REF_VCC; //wewnetrzne zrodlo odniesienia 2,56V

	i2cSetBitrate(100); // konfiguracja magistrali
	DS3231_init(); //ustawienie 1Hz na wyjsciu DS3231
	//DS3231_set_time(17,13,0);

	PORTD |= (1<<PD2); // konfiguracja wejœcia INT0
	MCUCR |= (1<<ISC01)|(1<<ISC00); // zbocze narastaj¹ce

	uint16_t wynik=0;

	//test
	//time.hh=1;
	//time.mm=9;
	//time.ss=5;

	while(1){
		//PORTD ^= D1;
		//_delay_ms(100);
		if(GIFR & (1<<INTF0)){
			wynik = pomiar(PA0);
			if(wynik<800){
				DS3231_get_datetime(&time);
				show_time(&time);
			}
			//PORTD ^= D1;
		GIFR |= (1<<INTF0);
		}
			/*wynik = pomiar(PA0);
			if(wynik<800){
				DS3231_get_datetime(&time);
				show_time(&time);
			}
			GIFR |= (1<<INTF0);
			}
*/
	}
}

uint16_t pomiar (uint8_t kanal){
	ADMUX = (ADMUX & 0b11111000) | kanal; //przypisanie nozki odpowiedzialnej za pomiar
	ADCSRA |= (1<<ADSC); //start konwersji
	while (ADCSRA & (1<<ADSC)); // oczekiwanie az pomar zostanie zakonczony
	return ADCW; //makro ktore zwrace pare rejsetrow jako zmienna
}

void DS3231_init(){ //przypisujemy pod wszystkie bity same 0
	uint8_t ctrl = 24;
	TWI_write_buf(DS3231_ADDR, 0x0e, 1, &ctrl);
}
// konwersja liczby dziesiêtnej na BCD
uint8_t dec2bcd(uint8_t dec) {
return ((dec / 10)<<4) | (dec % 10);
}
// konwersja liczby BCD na dziesiêtn¹
uint8_t bcd2dec(uint8_t bcd) {
    return ((((bcd) >> 4) & 0x0F) * 10) + ((bcd) & 0x0F);
}
void DS3231_get_datetime( TDATETIME * dt ) {
	uint8_t i;
	uint8_t buf[7];
	TWI_read_buf( DS3231_ADDR, 0x00, 7, buf );
	for( i=0; i<7; i++ ) dt->bytes[i] = bcd2dec( buf[i] );
}

void DS3231_set_time( uint8_t hh, uint8_t mm, uint8_t ss ) {
	uint8_t buf[3];
	buf[0]=dec2bcd(ss);
	buf[1]=dec2bcd(mm);
	buf[2]=dec2bcd(hh);
	TWI_write_buf( DS3231_ADDR, 0x00, 3, buf );
}

void show_time( TDATETIME * dt ){
	char string[6];
	char tmp[2];
	if( dt->hh < 10 ){
		string[0]='0';
		itoa(dt->hh,tmp,10);
		string[1]=tmp[0];
	}
	else{
		itoa(dt->hh,tmp,10);
		string[0]=tmp[0];
		string[1]=tmp[1];
	}
	if( dt->mm < 10 ){
		string[2]='0';
		itoa(dt->mm,tmp,10);
		string[3]=tmp[0];
	}
	else{
		itoa(dt->mm,tmp,10);
		string[2]=tmp[0];
		string[3]=tmp[1];
	}
	if( dt->ss < 10 ){
		string[4]='0';
		itoa(dt->ss,tmp,10);
		string[5]=tmp[0];
	}
	else{
		itoa(dt->ss,tmp,10);
		string[4]=tmp[0];
		string[5]=tmp[1];
	}
	int i = 0;
	_delay_us(1400);
	while(i<6){
		switch(string[i]){
		case '0':
			_0();
			break;
		case '1':
			_1();
			break;
		case '2':
			_2();
			break;
		case '3':
			_3();
			break;
		case '4':
			_4();
			break;
		case '5':
			_5();
			break;
		case '6':
			_6();
			break;
		case '7':
			_7();
			break;
		case '8':
			_8();
			break;
		case '9':
			_9();
			break;
		}
		if(i>0 && i<5){
			if(i%2!=0){
				_delay_us(300);
				_colon();
				_delay_us(300);
			}
			else{
				_delay_us(300);
			}
		}
		if(i==0) _delay_us(300);
		i++;

	}
}
