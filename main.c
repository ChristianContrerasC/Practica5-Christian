/// ARCHIVO MAIN
#include "lib/include.h"

int main(void)
{
    
    //Configurar_PLL(_50MHZ);  //Configuracion de velocidad de reloj
    //Configurar_GPIO();
    //UART_2_CONFIG();
    //PWM_CONFIGURATION(0, 0, 10000, 50000000, 50); 
    ADC_CONFIG();
    ADC0_InSeqs();
    unsigned int LECTURAADC;   
    // extern void PWM_CONFIGURATION(int module, int divisor,  int freq, int f_clk, int duty_cycle)
    while (1){
        ADC0 -> PSSI |= (1 << 3);
        while ((ADC0 -> RIS & 8) == 0);
        LECTURAADC = ADC0 -> SSFIFO2&0xFFF; //ENTRADA SALIDA
        ADC0 -> ISC = 8; 
        if (LECTURAADC >= 2048){
            GPIOC -> DATA |= (1 << 1); 
        }
        else if (LECTURAADC < 2048){
            GPIOC -> DATA &= ~(1 << 1); 
        }
    } 
}
