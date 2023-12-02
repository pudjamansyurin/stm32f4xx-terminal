/*
 * terminal.h
 *
 *  Created on: May 5, 2022
 *      Author: pujak
 */

#ifndef STM32F4XX_TINYSH_TERMINAL_H_
#define STM32F4XX_TINYSH_TERMINAL_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f4xx-serial/serial.h"

/* Exported macros
 * ---------------------------------------------------------------------------*/

/* Exported enum/struct types
 * ---------------------------------------------------------------------------*/
typedef enum
{
    TERM_IRQ_UART,
    TERM_IRQ_DMA,
} term_irq_t;

/* Public function declarations
 * ---------------------------------------------------------------------------*/
void term_init(UART_HandleTypeDef *p_uart, stdout_locker_t locker);
void term_irq(term_irq_t irq);

#ifdef __cplusplus
}
#endif

#endif /* STM32F4XX_TINYSH_TERMINAL_H_ */
