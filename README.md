# STM32F4xx serial module with tiny-shell

#### **`main.c`**
```c
#include "stm32f4xx-terminal/terminal.h"

/* Private function definitions */
static void stdin_reader(uint8_t *u8p_buffer, uint16_t u16_size)
{
    /* do something with received data */
    terminal_in(u8p_buffer, u16_size);
}

/* Public function definitions */
int main(void)
{
    /* Initialize peripherals */
    MX_GPIO_Init();
    MX_DMA_Init();
    MX_USART1_UART_Init();

    /* Initialize terminal */  
    terminal_init(stdin_reader);

    /* simulate in-direct stdout */
    printf("Hello World\n");

    /* Super loop */
    while(1) {
        /* do other concurrent task */

        HAL_Delay(1);
    }
}
```

#### **`stm32f4xx_it.c`**
```c
/* USER CODE BEGIN Includes */
#include "stm32f4xx-terminal/terminal.h"
/* USER CODE END Includes */

/**
  * @brief This function handles DMA1 stream5 global interrupt.
  */
void DMA1_Stream5_IRQHandler(void)
{
    HAL_DMA_IRQHandler(&hdma_usart1_rx);
    /* USER CODE BEGIN DMA1_Stream5_IRQn 1 */
    terminal_irq(1);
    /* USER CODE END DMA1_Stream5_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
    HAL_UART_IRQHandler(&huart1);
    /* USER CODE BEGIN USART1_IRQn 1 */
    terminal_irq(0);
    /* USER CODE END USART1_IRQn 1 */
}

```
