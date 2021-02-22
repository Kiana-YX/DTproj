/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-02-22 14:30:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \F4DT最简版\USER\SRC\main.c
 */
#include "main.h"

int main(void)
{
	SystemInit();									//系统初始化
	NVIC_SetPriorityGrouping(NVIC_PriorityGroup_3); //中断优先级分组3
	RCC->AHB1ENR |= 3 << 0;							//使能PORTA，PORTB时钟
	LED_Configuration();
	Beep_Configuration();
	paramInit();			//此处默认为模式mode=1定时发送；默认未使能
	//USART1_Configuration(); //虚拟示波器需要配置串口
	SPI1_Configuration();
	SPI2_Configuration();
	CAN1_Configuration();
	TIM3_Configuration();

	OSInit(); //任务创建
	OSTaskCreate(TaskStart, (void *)0, &start_task_stk[START_TASK_STK_SIZE - 1], START_TASK_PRIO);
	OSTaskCreate(Task_Lcd, (void *)0, (OS_STK *)&LCD_TASK_STK[LCD_STK_SIZE - 1],LCD_TASK_PRIO);
	OSStart();

	return 0;
}

/*起始任务*/ //基本的创建函数OSTaskCreate
static void TaskStart(void *pdata)
{
	OS_CPU_SR cpu_sr = 0;
	pdata = pdata;
	OS_CPU_SysTickInit();
	OS_ENTER_CRITICAL(); //进入临界区（无法被中断打断）
	RUN = OSSemCreate(0);
	Beep_Show(2); //上电提醒
	Led_Show();
	OSTaskCreate(TaskCurveFit, (void *)0, &CurveFit_task_stk[CurveFit_STK_SIZE - 1], CurveFit_TASK_PRIO);
	OSTaskCreate(Task_Lcd, (void *)0, (OS_STK *)&LCD_TASK_STK[LCD_STK_SIZE - 1],LCD_TASK_PRIO);
	OSTaskSuspend(START_TASK_PRIO); //挂起起始任务
	OS_EXIT_CRITICAL();				//退出临界区
}

/*曲线拟合任务*/
//从DT读取数据存入distanceU1.real中
static void TaskCurveFit(void *pdata)
{
	pdata = pdata;

	for (;;)
	{
		Linear_Fitting(SPI1);
		Linear_Fitting(SPI2);
		OSTimeDly(2); //2ms一次
	}
}
