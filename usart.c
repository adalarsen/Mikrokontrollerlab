#include "usart.h"
#include <avr/io.h>
#include <stdio.h>
#define F_CPU_16000000UL

static FILE usart_stdout = FDEV_SETUP_STREAM(usart_putchar, NULL, _FDEV_SETUP_WRITE);



int init_usart(int baudrate) {
    UBRR1H = (unsigned char) (baudrate >> 8);
    UBRR1L = (unsigned char) (baudrate);
    UCSR1B = (1 << RXEN1) | (1 << TXEN1);
    UCSR1C = (1 << USBS1) | (3 << UCSZ10);
    //    DDRD |= (1 << PD0);
  //  DDRD |= (1 << PD1);
   // DDRD |= (1 << PD2);
   //DDRD |= (1 << PD3);
    stdout = &usart_stdout;
    return 1;
}

int usart_putchar(char c) {
        while ( !(UCSR1A & (1 << UDRE1))) {}
            UDR1 = c;
}

