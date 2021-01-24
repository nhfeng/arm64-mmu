#include "io.h"

#define PL011_BASE     0x09000000

#define R_UART_TX      (PL011_BASE + 0x0)
#define R_UART_LCR     (PL011_BASE + 0x2c)
#define LCR_DATA_LEN_8 (3 << 5)
#define LCR_FIFO_EN    (1 << 4)
#define R_UART_CR      (PL011_BASE + 0x30)
#define CR_UART_EN     1
#define CR_UART_TXE    (1 << 8)
#define CR_UART_RXE    (1 << 9)

int uart_putchar(int c)
{
	* (volatile unsigned int *) R_UART_TX = c;
	return c;
}

void uart_init(void)
{
	write_32(R_UART_LCR, LCR_DATA_LEN_8 | LCR_FIFO_EN);
	write_32(R_UART_CR, CR_UART_RXE | CR_UART_TXE | CR_UART_EN);
}
