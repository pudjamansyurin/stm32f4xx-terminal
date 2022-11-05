/*
 * terminal.c
 *
 *  Created on: May 5, 2022
 *      Author: pujak
 */
#include "terminal.h"
#include "tinysh/tinysh.h"
#include <stdio.h>

/* Private variables */
static uint8_t u8_buffer[256];

/* Public function definitions */
void term_init(UART_HandleTypeDef *p_uart, stdin_reader_t reader,
	stdout_locker_t locker)
{
	/* setup serial */
	serial_init(p_uart, locker);
	serial_start(reader, u8_buffer, sizeof(u8_buffer));

	/* setup tiny-shell */
	tinysh_set_prompt("STM32F4> ");

	/* add tiny-shell commands */
	// tinysh_add_command(&foo);
}

void term_irq(uint8_t u8_dma)
{
	u8_dma ? serial_irq_dma() : serial_irq_uart();
}

void term_in(unsigned char *str, uint16_t size)
{
	while (size--)
	{
		tinysh_char_in(*str++);
	}
}

/* we must provide this function to use tinysh  */
void tinysh_puts(char *s)
{
	printf("%s", s);
}

void tinysh_putchar(unsigned char c)
{
	putchar((int) c);
}

