#ifndef _PARAM_H_
#define _PARAM_H_

#include "kalman.h"
#include "stdbool.h"
#include "stm32f4xx.h"

//hu  2号（李茂QA1），号
#define DT_SELECT 	0x04		//壹号DT
								//0x02 贰号DT
								//0x03 叁号DT
								//0x04 肆号DT
								//0x05 伍号DT

#if	DT_SELECT == 0x01

#endif

/****主控数据传输结构体体****/
typedef struct{
  bool enable;            //数据传输使能
  u8 mode;                //传输模式  1：间隔一段时间发送一次数据 2：收到查询后反馈数据
  u8 cnt;                 //数据传输次数
  u8 time;                //传输时间间隔，接收主控数据后修改
  u8 loop;                //传输间隔时间循环
}TransimitTypeDef;

//线性拟合系数
typedef struct
{
	double k1;
	double b1;
	double A1;
	double B1;
	double C1;
	
	double k2;
	double b2;
	double A2;
	double B2;
	double C2;
}CoefficientTypeDef;

//实际使用系数
typedef struct
{
	double k;
	double b;
	double A;
	double B;
	double C;
}UseTypeDef;

extern UseTypeDef DT35Coe_1,DT35Coe_2;
extern CoefficientTypeDef coeTemp[5];
extern TransimitTypeDef DT_transmit;

void paramInit(void);
  
#endif
