#ifndef _KALMAN_H
#define _KALMAN_H

#include "SPI.h"
#include "param.h"
#include "visual_scope.h"
#define my_double 0;

//kalman���ݴ洢�ṹ��
typedef struct 
{
	int length;
	int data[50];
}Kalman_DataTypeDef;

typedef struct
{
	double kalmaninput;				//averaging data through ADC
	double temp;						//temporary data in kalman fliter
	double real;						//real distance in the ground
	u32 send;							//��can���͵���������
}Distance_Data;

/******�˲����ṹ��********/
typedef struct
{
	double Q;	   					//Ԥ���������СЭ����
	double R;     					//������������СЭ����
	double x_last,x_mid,x_now;  	//�ϴε�����ֵ�����β���ֵ
	double p_last,p_mid,p_now;  	//�ϴ�Э�������Ԥ��Э����
	double kg;            			//����
	double A;             			//x(n)=Ax(n-1)+u(n)  ϵͳת�ƾ���
	double B;						//���ƾ��� 
	double H;             			//z(n)=Hx(n)+v(n),z(n)Ϊ����ʵ��ֵ��x��n��ΪԤ��ֵ��HΪ�۲�ת�ƾ���	
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
