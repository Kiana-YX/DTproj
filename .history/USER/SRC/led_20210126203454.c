/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-01-26 20:34:54
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
	LED_RED_ON; Delay_ms(200);
	LED_YELLOW_ON; Delay_ms(200);
	LED_BLUE_ON; Delay_ms(200);
	LED_GREEN_ON;Delay_ms(200);
	LED_RED_OFF; Delay_ms(200);
	LED_YELLOW_OFF; Delay_ms(200);
	LED_BLUE_OFF; Delay_ms(200);
	LED_GREEN_OFF; Delay_ms(200);
}

void LED_OFF(void)
{
	LED_RED_OFF;
	LED_YELLOW_OFF;
	LED_BLUE_OFF;
	LED_GREEN_OFF;
}

void LED_ON(void)
{
	LED_RED_ON;
	LED_YELLOW_ON;
	LED_BLUE_ON;
	LED_GREEN_ON;
}

