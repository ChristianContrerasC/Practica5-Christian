/*
 * PWM.h
 *
 *  Created on: 9 nov. 2020
 *      Author: root
 */

#ifndef PWM_PWM_H_
#define PWM_PWM_H_

extern void Configurar_PWM(int module, int divisor, int freq, int f_clk, int duty_cycle);
extern void delayms();

#endif /* PWM_PWM_H_ */
