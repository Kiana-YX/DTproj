/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-01-26 18:48:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \F4DT最简版\USER\SRC\timer.c
 */
#include "timer.h"

void TIM3_Configuration(void)
{
	RCC->APB1ENR|=1<<1;//TIM3时钟使能
	TIM3->ARR=1999;//自动重载值2000
	TIM3->PSC=83;//预分频器值84
  /*  Tout=(2000*84)/84M=2ms  */
	TIM3->CR1 |= 1<<8;//预装载
	TIM3->SR &= ~(1<<0);//清除标志位
 	TIM3->DIER |= 1<<0;//允许更新中断
	TIM3->CR1 |= 0x01;//使能TIM3
	MY_NVIC_Init(1,0,TIM3_IRQn,3);//中断优先级1,0；分组3
}

void TIM3_IRQHandler(void)
{
  if(TIM3->SR&0x0001)//溢出中断
  {
    kalman_data1.length=0;
    kalman_data2.length=0;
    for(int i=0;i<50;i++)
    {
      kalman_data1.data[kalman_data1.length++]=Read_ADC1_Value();
      kalman_data2.data[kalman_data2.length++]=Read_ADC2_Value();
    }
	
	//在主控发送定时发送指令后，定时发送
	if(DT_transmit.loop < DT_transmit.time) 
    {
      DT_transmit.loop++;//继续计时，等待下一次定时器中断判断
    }
    else if(DT_transmit.loop >= DT_transmit.time)
    {
		if(DT_transmit.enable)//由主控命令是否允许使用CAN发送
      {
        if(DT_transmit.mode == 1) 
			canSend_DT35();
        else if(DT_transmit.mode == 2)
        {
          if((DT_transmit.cnt)>0)  
          {
            canSend_DT35();
            DT_transmit.cnt--;
            LED_YELLOW_TOGGLE;
          }
        }
      }
      DT_transmit.loop = 1;
    }
  }
  TIM3->SR &= ~(1<<0);//清除中断标志位
}
