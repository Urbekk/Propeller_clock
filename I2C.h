/*
 * I2C.h
 *
 *  Created on: 13 gru 2019
 *      Author: Adrian
 */

#ifndef I2C_H_
#define I2C_H_

#define ACK 1
#define NACK 0



// funkcje

// ustawiamy prêdkoœæ na I2C w kHz (standardowa prêdkoœæ to 100 kHz)  i2cSetBitrate( 100 );
void i2cSetBitrate(uint16_t bitrateKHz);


void TWI_start(void);
void TWI_stop(void);
void TWI_write(uint8_t bajt);
uint8_t TWI_read(uint8_t ack);

void TWI_write_buf( uint8_t SLA, uint8_t adr, uint8_t len, uint8_t *buf );
void TWI_read_buf(uint8_t SLA, uint8_t adr, uint8_t len, uint8_t *buf);


#endif /* I2C_H_ */
