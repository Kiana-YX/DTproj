/*** 
 * @LastEditTime: 2021-02-22 19:03:24
 * @Description: 
 * @欲戴王冠,必承其重
 */
#ifndef _FILTER_H
#define _FILTER_H

/*************************************************/
extern IIR_struct my_IIR;
/*************************************************/

/*一阶低通滤波器*/
typedef struct
{
	float distance[3];  //0为上一次实际值,1为本次测量值,2为滤波处理值
	float a;           //低通滤波系数
}IIR_struct;

#endif
