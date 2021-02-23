#include "kalman.h"

Kalman_DataTypeDef kalman_data1, kalman_data2; //数据存储结构体
Kalman_Filter kalman_fliter1, kalman_fliter2;
Distance_Data distance1, distance2; //读取SPI1,SPI2值
Distance_Data distance;

/*
 * kalman一阶滤波器初始化
 * 目前使用的其实是一维变量x
 * 状态矩阵和观测矩阵选1就好了,,,
 */
//!预测Q结合测量R来估计当前系统的状态
void Kalman_Init(void)
{
	//TODO:尝试修改卡尔曼滤波参数
	kalman_fliter1.x_last = getAveragingData(&kalman_data1);
	kalman_fliter1.p_last = 1; //上次的协方差
	kalman_fliter1.Q = 0.009;  //过程噪声0.001
	kalman_fliter1.R = 0.18;   //观测噪声，ad采样原始数据的方差为0.27
	kalman_fliter1.A = 1;	   //*状态转移矩阵，根据运动学方程确定，比如测量值是温度、湿度，一般认为下一个时刻该温度或者湿度维持不变，这种情况下状态转移矩阵通常就是标量1
	kalman_fliter1.H = 1;	   //*观测矩阵

	kalman_fliter2.x_last = getAveragingData(&kalman_data2); //上次最优值
	kalman_fliter2.p_last = 1;								 //上次的协方差
	kalman_fliter2.Q = 0.009;								 //预测的最小协方差      过程噪声0.001
	kalman_fliter2.R = 0.18;								 //测量的最小协方差      观测噪声，ad采样原始数据的方差为0.27
	kalman_fliter2.A = 1;									 //一般均取1，简化模型
	kalman_fliter2.H = 1;
}
/****获得去除最大最小值后的均值****/
double getAveragingData(Kalman_DataTypeDef *kalman) //kalman数据存储结构体，int length;int data[50];
{
	long sum = 0;
	float max = kalman->data[0], min = kalman->data[0]; //NOTICE:初始化时别都赋值为0

	for (int i = 0; i < kalman->length; i++)
	{
		sum += kalman->data[i];
		if (max < kalman->data[i])
			max = kalman->data[i];
		if (min > kalman->data[i])
			min = kalman->data[i];
	}

	return (sum - max - min) / (kalman->length - 2);
}

/****一阶kalman滤波处理****/
double kalman_filter(Kalman_Filter *kalman, double input)
{
	kalman->x_mid = kalman->A * kalman->x_last;				  //由上次最优值预测的下次的x[n]，x_mid=A*x_last
	kalman->p_mid = kalman->p_last + kalman->Q;				  //由上次最小均方差预测的下次均方差
	
	kalman->kg = kalman->p_mid / (kalman->p_mid + kalman->R); //计算增益kg
	kalman->x_now = kalman->x_mid + (kalman->kg * (input - (kalman->H * kalman->x_mid)));
	kalman->p_now = (1 - kalman->kg) * kalman->p_mid;
	kalman->p_last = kalman->p_now;
	kalman->x_last = kalman->x_now;
	kalman->best = kalman->x_now;
	return kalman->best;
}

float iir_test;
/****对数据进行线性拟合****/
short Linear_Fitting(SPI_TypeDef *SPIx) //SPI1为1号DT35，SPI2为2号DT35
{
#if DT_SELECT == 0x01 //不稳定，暂时没板子
#endif

#if DT_SELECT == 0x02 //C2，QA2
	if (SPIx == SPI2)
	{
		distance2.kalmaninput = getAveragingData(&kalman_data2);
		distance2.temp = kalman_filter(&kalman_fliter2, distance2.kalmaninput);
		distance2.real = (0.1952540183 * distance2.temp - 2405.5946488263) * 1.00161384; //1.24系数，新二号板，QA2
		distance.send = (u32)(distance2.real + 0.5);
	}
	return 0;
#endif

#if DT_SELECT == 0x03 //L0
	/** x 
	distance1.real=0.4442445868*distance1.temp - 2240.8006575493 ;						//L0号板，已测试，1.24
	distance2.real=(0.2202024141*distance2.temp - 2239.2398101223)/1.002246357;			//L2板，已测试1.24
	**/

	//	if(SPIx==SPI2)
	//	{
	//		distance2.kalmaninput=getAveragingData(&kalman_data2);
	//		distance2.temp=kalman_filter(&kalman_fliter2,distance2.kalmaninput);
	//		distance2.real=(0.2202024141*distance2.temp - 2239.2398101223)/1.002246357;//整体乘系数，效果还行
	//		distance.send=(u16)(distance2.real+0.5);
	////		if(distance2.temp>30000)distance2.temp-=30000;
	//		VS4Channal_Send(adc_value2,distance2.kalmaninput,distance2.temp,distance.send);
	//	}
	if (SPIx == SPI1)
	{
		distance1.kalmaninput = getAveragingData(&kalman_data1);
		distance1.temp = kalman_filter(&kalman_fliter1, distance1.kalmaninput);
		distance1.real = 0.4442445868 * distance1.temp - 2240.8006575493;
		distance.send = (u16)(distance1.real + 0.5);
	}
	return 0;
#endif

#if DT_SELECT == 0x04 //F4，C1号板，QA2
	if (SPIx == SPI2)
	{
		distance2.kalmaninput = getAveragingData(&kalman_data2);
		//distance2.temp=kalman_filter(&kalman_fliter2,distance2.kalmaninput);
		distance2.temp = distance2.kalmaninput;
		distance2.real = 0.1962073951 * distance2.temp - 2428.2976700373 + 16.25;
		distance.send = (u16)(distance2.real + 0.5);
	}
	return 0;
#endif

#if DT_SELECT == 0x05 //F1板
	if (SPIx == SPI2)
	{
		distance2.kalmaninput = getAveragingData(&kalman_data2);
		distance2.temp = kalman_filter(&kalman_fliter2, distance2.kalmaninput);
		distance2.real = (0.2373532 * distance2.temp - 2404.46733589) * 1.004847376 distance.send = (u16)(distance2.real + 0.5);
	}
	return 0;
#endif

#if DT_SELECT == 0x50 //L2 DT50
	if (SPIx == SPI2)
	{
		distance2.kalmaninput = getAveragingData(&kalman_data2);
		distance2.temp = kalman_filter(&kalman_fliter2, distance2.kalmaninput);
		iir_test=IIR_filter(distance2.kalmaninput);
		distance2.real = 0.7058208778 * distance2.temp - 7205.7917274784;
		distance.send = (u16)(distance2.real + 0.5);
	}
	return 0;
#endif

#if DT_SELECT == 0x00 //测试用

	if (SPIx == SPI1)
	{
		distance1.kalmaninput = getAveragingData(&kalman_data1); //用平均值滤波获得卡尔曼滤波的原始值
		distance1.temp = kalman_filter(&kalman_fliter1, distance1.kalmaninput);
		distance1.real = (3.394e-07) * distance1.temp * distance1.temp + 0.4368 * distance1.temp - 2207;
		distance1.send = (u16)(distance1.real + 0.5);
	}
	else if (SPIx == SPI2)
	{
		distance2.kalmaninput = getAveragingData(&kalman_data2);
		distance2.temp = kalman_filter(&kalman_fliter2, distance2.kalmaninput);
		//	distance2.real=DT35Coe_2.k*distance2.temp+DT35Coe_2.b;
		distance2.real = 0.1962073951 * distance2.temp - 2428.2976700373;
		distance2.send = (u16)(distance2.real + 0.5);
		//	float sum;
		//	distance_temp[i_kalman++]=distance2.real;
		//	if(i_kalman==5) i_kalman=0;
		//	for(int count=0;count<5;count++)
		//		sum+=distance_temp[i_kalman];
		//	distance2.send=(u16)(sum/5+0.5);
	}
	VS4Channal_Send(adc_value1, adc_value2, distance1.temp, distance2.temp);

	return 0;
#endif
}
