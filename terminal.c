/*
 * terminal.c
 *
 *  Created on: May 5, 2022
 *      Author: pujak
 */
#include "terminal.h"
#include "tinysh/tinysh.h"
#include <stdio.h>

/* External variables */
extern UART_HandleTypeDef huart1;

/* Private variables */
static uint8_t u8_buffer[256];

/* Public function definitions */
void terminal_init(serial_reader_t reader)
{
    serial_init(&huart1);
    serial_start(reader, u8_buffer, sizeof(u8_buffer));
}

void terminal_irq(uint8_t u8_dma)
{
	u8_dma ? serial_irq_dma() : serial_irq_uart();
}

void terminal_in(unsigned char *str, uint16_t size)
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

