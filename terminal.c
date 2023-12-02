/*
 * terminal.c
 *
 *  Created on: May 5, 2022
 *      Author: pujak
 */
#include "terminal.h"
#include "tinysh/tinysh.h"
#include <stdio.h>

/* Private variables
 * ---------------------------------------------------------------------------*/
static uint8_t u8_buf[256];

/* Private function declarations
 * ---------------------------------------------------------------------------*/
static void term_in(unsigned char *ucp_buf, uint16_t u16_size);

/* Public function definitions
 * ---------------------------------------------------------------------------*/
void term_init(UART_HandleTypeDef *p_uart, stdout_locker_t locker)
{
    /* setup serial */
    serial_init(p_uart, locker);
    serial_start(term_in, u8_buf, sizeof(u8_buf));

    /* setup tiny-shell */
    tinysh_set_prompt("STM32F4> ");

#if 0
    /* add tiny-shell commands */
    tinysh_add_command(&foo);
#endif
}

void term_irq(term_irq_t irq)
{
    if (TERM_IRQ_UART == irq)
    {
        serial_irq_uart();
    }
    else
    {
        serial_irq_dma();
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

/* Private function definitions
 * ---------------------------------------------------------------------------*/
static void term_in(unsigned char *ucp_buf, uint16_t u16_size)
{
    while (u16_size--)
    {
        tinysh_char_in(*ucp_buf++);
    }
}

