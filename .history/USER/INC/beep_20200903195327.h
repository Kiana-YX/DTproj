#ifndef _BEEP_H
#define _BEEP_H

#include "delay.h"
#include "sys.h"

#define BEEP_ON     	 GPIOA->BSRRL = PIN8	//32 λ��λ/��λ�Ĵ��� (GPIOx_BSRR)
#define BEEP_OFF     	 GPIOA->BSRRH = PIN8
#define BEEP_TOGGLE	   GPIOA->ODR ^= PIN8
//BSRR ֻд�Ĵ���
//�ԼĴ����� 16bitд1��Ӧ�ܽ�Ϊ�͵�ƽ��
//�ԼĴ�����16bitд1��Ӧ�ܽ�Ϊ�ߵ�ƽ
//д 0 ,�޶���
void Beep_Show(u8 num);
void Beep_Configuration(void);

#endif
