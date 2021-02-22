#ifndef _BEEP_H
#define _BEEP_H

#include "delay.h"
#include "sys.h"

#define BEEP_ON     	 GPIOA->BSRRL = PIN8	//32 位置位/复位寄存器 (GPIOx_BSRR)
#define BEEP_OFF     	 GPIOA->BSRRH = PIN8
#define BEEP_TOGGLE	   GPIOA->ODR ^= PIN8
//BSRR 只写寄存器
//对寄存器高 16bit写1对应管脚为低电平，
//对寄存器低16bit写1对应管脚为高电平
//写 0 ,无动作
void Beep_Show(u8 num);
void Beep_Configuration(void);

#endif
