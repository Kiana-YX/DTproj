/*** 
 * @LastEditTime: 2021-02-22 15:41:19
 * @Description: 
 * @欲戴王冠,必承其重
 */
#ifndef _FILTER_H
#define _FILTER_H

/*一阶低通滤波器*/
typedef struct IIR
{
	float last;        //上一时刻滤波后的值
	float now;         //这一时刻滤波后的值
	float a;           //低通滤波系数
}IIR_struct;

#endif