#include "adc.h"
#include <avr/io.h>






void init_adc() {
   //skal sette opp nødvendige registre
   
    ADCSRA |= 0b0000111; //prescaling, division factor 128
    ADCSRA |= (1 << ADEN);//enable adc
    DIDR0 = 0b00000000;

    //port f 


}

int adc_read(char axis) {
 //skal ta inn axis som bestemmer om vi skal lese av X-aksen eller Y-aksen til den analoge spaken; denne verdien skal returneres
 //0 X og 1 Y
if (axis == 'X') {
    ADMUX = 0b00000000; //read from bit 0
}
else if (axis == 'Y') {
    ADMUX = 0b00000001; //read from bit 1
}
ADCSRA |= (1 << ADSC); //started convertion, high
while (ADCSRA & (1<<ADSC)) {
}
return ADC;

}

