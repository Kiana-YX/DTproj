/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-01-26 15:21:50
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \F4DT最简版\USER\INC\delay.h
 */
#ifndef _DELAY_H
#define _DELAY_H

#include "stm32f4xx.h"

void Delay_ms(unsigned int t);
void Delay_us(unsigned int t);
void Delay(u16 t);

#endif
