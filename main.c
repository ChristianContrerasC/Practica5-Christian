/// ARCHIVO MAIN
#include "lib/include.h"
int i;
int main(void)
{
    
    //Configurar_PLL(_50MHZ);  //Configuracion de velocidad de reloj
    //Configurar_GPIO();
    //UART_2_CONFIG();
    //PWM_CONFIGURATION(0, 0, 10000, 50000000, 50); 
    volatile uint16_t freq;
     freq=1250;

    uint16_t Result[3];
    uint16_t duty[3];
    Configurar_PLL(_20MHZ);  
    Configurar_PWM(50); // PWM a 10 KHz
    ADC_CONFIG();
    SEQ_CONFIG();
    ADCS1INTERRUPCION();
    unsigned int LECTURAADC;   
    // extern void PWM_CONFIGURATION(int module, int divisor,  int freq, int f_clk, int duty_cycle)
    
    // CICLO WHILE CON LECTURA DEL ADC Y COMPARACION PARA EL PWM ASI COMO UN DELAY de 10 ms
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
        SEQ_CONFIG(Result,duty);
        PWM0->_1_CMPA = duty[1];
        // PEQUEÑO DELAY
        delayms(10);
    } 
}
