#include <avr/io.h>
#define F_CPU 16000000UL
 
 
 
int main(){
    UCSR1C = (1 << UCSZ11) | (1 << UCSZ10) | (1<<USBS1);
    UBRR1 = 51;
    UCSR1B = (1 << RXEN1)| (1 << TXEN1);
     
    char letter = 'a';
    while (1){
        UDR1 = letter;
        letter++;
         
        while(!(UCSR1A & (1 << TXC1)));
        UDR1 = '\r';
        while(!(UCSR1A & (1 << TXC1)));
        UDR1 = '\n';
        while(!(UCSR1A & (1 << TXC1)));
         
        if(letter == 'z'){
            letter = 'a';
        }
         
    }
    return 0;
}
