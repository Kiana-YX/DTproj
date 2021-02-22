/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-01-26 20:25:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \F4DT最简版\USER\INC\led.h
 */
#ifndef _LED_H
#define _LED_H

#include "sys.h"
#include "delay.h"
#include "includes.h"

#define LED_RED_OFF  			GPIOA->BSRRL = PIN4
#define LED_YELLOW_OFF  		GPIOA->BSRRL = PIN5
#define LED_BLUE_OFF    	    GPIOA->BSRRL = PIN6
#define LED_GREEN_OFF  			GPIOA->BSRRL = PIN7

#define LED_RED_ON   			GPIOA->BSRRH = PIN4
#define LED_YELLOW_ON   		GPIOA->BSRRH = PIN5
#define LED_BLUE_ON   			GPIOA->BSRRH = PIN6
#define LED_GREEN_ON   			GPIOA->BSRRH = PIN7

#define LED_RED_TOGGLE			GPIOA->ODR ^= PIN4
#define LED_YELLOW_TOGGLE 	    GPIOA->ODR ^= PIN5
#define LED_BLUE_TOGGLE			GPIOA->ODR ^= PIN6
#define LED_GREEN_TOGGLE		GPIOA->ODR ^= PIN7

void LED_Configuration(void);
void Led_Show(void);
void LED_OFF(void);
void LED_ON(void);

#endif
