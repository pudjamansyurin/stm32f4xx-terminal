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
void term_init(UART_HandleTypeDef *p_uart, stdin_reader_t reader,
	stdout_locker_t locker);
void term_irq(uint8_t u8_dma);
void term_in(unsigned char *str, uint16_t size);

#endif /* STM32F4XX_TINYSH_TERMINAL_H_ */
