/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-01-26 17:30:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \F4DT最简版\USER\SRC\led.c
 */
#include "led.h"

void LED_Configuration()
{
	GPIO_Set(GPIOA,PIN4|PIN5|PIN6|PIN7,GPIO_MODE_OUT,GPIO_OTYPE_PP,GPIO_SPEED_2M,GPIO_PUPD_NONE);
	LED_BLUE_OFF;LED_GREEN_OFF;LED_YELLOW_OFF;LED_RED_OFF;
}

void Led_Show(void)
{
	LED_RED_ON;OSTimeDly(2000);
	LED_YELLOW_ON;OSTimeDly(2000);
	LED_BLUE_ON;OSTimeDly(2000);
	LED_GREEN_ON;OSTimeDly(2000);
	
	LED_RED_OFF;OSTimeDly(2000);
	LED_YELLOW_OFF;OSTimeDly(2000);
	LED_BLUE_OFF;OSTimeDly(2000);
	LED_GREEN_OFF;OSTimeDly(2000);
}

void LED_OFF(void)
{
	LED_RED_OFF;
	LED_YELLOW_OFF;
	LED_BLUE_OFF;
	LED_GREEN_OFF;
}

