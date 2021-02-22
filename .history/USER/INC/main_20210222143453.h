#ifndef _MAIN_H
#define _MAIN_H

#include "can1.h"
#include "led.h"
#include "beep.h"
#include "timer.h"
#include "kalman.h"
#include "usart1.h"
#include "visual_scope.h"

//START任务
#define START_TASK_PRIO            5
#define START_TASK_STK_SIZE        256
__align(8) OS_STK start_task_stk[START_TASK_STK_SIZE];
static void TaskStart(void *pdata);

//线性拟合任务
#define CurveFit_TASK_PRIO         10
#define CurveFit_STK_SIZE          256
__align(8) OS_STK CurveFit_task_stk[CurveFit_STK_SIZE];
static void TaskCurveFit(void *pdata);

//LCD任务
#define LCD_TASK_PRIO       	   25
#define LCD_STK_SIZE     		   512
__align(8) OS_STK LCD_TASK_STK[LCD_STK_SIZE];
static void Task_Lcd(void *pdata);

OS_EVENT *RUN;

#endif
