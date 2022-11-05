/*
 * terminal.h
 *
 *  Created on: May 5, 2022
 *      Author: pujak
 */

#ifndef STM32F4XX_TINYSH_TERMINAL_H_
#define STM32F4XX_TINYSH_TERMINAL_H_

#include "stm32f4xx-serial/serial.h"

/* Public function declarations */
void terminal_init(serial_reader_t reader);
void terminal_irq(uint8_t u8_dma);
void terminal_in(unsigned char *str, uint16_t size);

#endif /* STM32F4XX_TINYSH_TERMINAL_H_ */
