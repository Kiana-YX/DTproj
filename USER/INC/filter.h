/*** 
 * @LastEditTime: 2021-02-22 19:20:08
 * @Description: 
 * @欲戴王冠,必承其重
 */
#ifndef _FILTER_H
#define _FILTER_H



/*一阶低通滤波器*/
typedef struct
{
	float distance[3];  //0为上一次实际值,1为本次测量值,2为滤波处理值
	float a;           //低通滤波系数
}IIR_struct;


/*************************************************/
extern IIR_struct my_IIR;
extern void IIR_init(IIR_struct *IIR_flt);
/*************************************************/
#endif
