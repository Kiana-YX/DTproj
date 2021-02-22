/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-01-26 18:42:06
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \F4DT最简版\USER\SRC\param.c
 */
#include "param.h"

TransimitTypeDef DT_transmit;

void paramInit(void)
{
	Kalman_Init();
	
  {//DT标志位初始化
  DT_transmit.mode = 1;
	DT_transmit.enable = 0;
	DT_transmit.loop = 1;
  }
}


