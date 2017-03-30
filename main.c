#include <avr/io.h>
#include <stdio.h>
#include "usart.h"
#include "adc.h"


void init_led() {
   //sett io-registre
  DDRB |= ((1 << PB0) | (1 << PB2) | (1 << PB4) | (1 << PB6));
}

void init_switch(){
  DDRB &= ~((1 << PB1) | (1 << PB3) | (1 << PB5) | (1 << PB7));
}

//n tall mellom 0 og 3 (hvilket lys er det snakk om)
//v enten 0 eller 1 (skal det lyse eller ikke)
void set_led(int n, int v) {
    if (v) {
    switch(n) {
        case 0:
          PORTB |= (1 << PB0);
            break;
        case 1:
          PORTB |= (1 << PB2);
       break;
        case 2:
          PORTB |= (1 << PB4);
        break;
        case 3:
          PORTB |= (1 << PB6);
           break;    
    }
    }
    else if (!v) {
        switch(n) {
            case 0:
                PORTB &= ~(1 << PB0);
            break;
            case 1:
                PORTB &= ~(1 << PB2);
            break;
            case 2:
                PORTB &= ~(1 << PB4);
            break;
            case 3:
                PORTB &= ~(1 << PB6);
                break;
        }
    }


}
int read_switch(int n) {
    switch(n) {
        case 0:
            return PINB & (1<<PB1);
        case 1:
            return PINB & (1<<PB3);
        case 2:
            return PINB & (1<<PB5);
        case 3:
            return PINB & (1<<PB7);

    }
}

int main(){
    
    init_led();
    init_switch();
    init_usart(51);
    
    //DDRB |= (1 << PB0);
    set_led(3,0);
    set_led(1,1);
    set_led(0,1);
    init_adc();
    while(1) { 
        int n = read_switch(2);
        if (n) {
            set_led(2,0);
        }
        else { set_led(2,1);}
        //printf("lys 2: %d",n);
        usart_putchar('p');
        usart_putchar('\r');
        usart_putchar('\n');
        usart_putchar('x');    
    
        int ycoord = adc_read('Y');
        int xcoord = adc_read('X');
        ycoord = (ycoord - 512)/5.12;
        xcoord = (xcoord - 512)/5.12;
        printf("xcoord: %d, ycoord: %d \r \n", xcoord, ycoord);
        usart_putchar('v');
    }
    return 0;
}
