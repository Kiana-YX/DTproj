/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-01-26 16:14:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \F4DT最简版\USER\INC\kalman.h
 */
#ifndef _KALMAN_H
#define _KALMAN_H

#include "SPI.h"
#include "param.h"
#include "visual_scope.h"
#define my_double 0;

//kalman数据存储结构体
typedef struct 
{
	u8 length;		
	u16 data[50];	//test:16位AD转化模块，最高也就2^16
}Kalman_DataTypeDef;

typedef struct
{
	double kalmaninput;					//averaging data through ADC
	double temp;						//temporary data in kalman fliter
	double real;						//real distance in the ground
	u16 send;							//距离最高也就12m(12000mm),16位足以
}Distance_Data;

/******滤波器结构体********/
typedef struct
{
	double Q;	   					//预测的噪声最小协方差
	double R;     					//测量的噪声最小协方差
	double x_last,x_mid,x_now;  	//上次的最优值，本次测量值
	double p_last,p_mid,p_now;  	//上次协方差，本次预测协方差
	double kg;            			//增益
	double A;             			//x(n)=Ax(n-1)+u(n)  系统转移矩阵
	double B;						//控制矩阵 
	double H;             			//z(n)=Hx(n)+v(n),z(n)为采样实测值，x（n）为预测值，H为观测转移矩阵	
	double best;
}Kalman_Filter;

extern float test_ave;
extern float ave_result;
extern float middle_result;
extern float test_middle;

extern Kalman_DataTypeDef kalman_data1,kalman_data2;
extern Kalman_Filter kalman_fliter1,kalman_fliter2;

extern Distance_Data distance1,distance2;
extern Distance_Data distance;

extern float distance_temp[5];
extern char i_kalman;


void Kalman_Init(void);
short Linear_Fitting(SPI_TypeDef *SPIx);
double getAveragingData(Kalman_DataTypeDef* );
double getMiddleData(Kalman_DataTypeDef* kalman);
double kalman_filter(Kalman_Filter *kalman,double input);

#endif
