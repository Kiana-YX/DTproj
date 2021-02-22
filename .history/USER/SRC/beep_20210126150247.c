/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-01-26 15:02:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \F4DT最简版\USER\SRC\beep.c
 */
#include "beep.h"

void Beep_Configuration(void)
{
	GPIO_Set(GPIOA,1<<8,GPIO_MODE_OUT,GPIO_OTYPE_PP,GPIO_SPEED_2M,GPIO_PUPD_NONE);	//PA8
}

void Beep_Show(u8 num)
{
	for(int i=0; i<num; i++)
	{
		BEEP_ON;
		Delay_ms(100);
		BEEP_OFF;
		Delay_ms(100);
	}
}
