/*
 * @Author: your name
 * @Date: 2021-01-23 20:28:00
 * @LastEditTime: 2021-01-23 20:33:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \F4DT集合版\USER\INC\filter.h
 */
#ifndef _FILTER_H
#define _FILTER_H

//低通滤波器
typedef struct
{
     int16_t  Input;
     int16_t  Output[2];
     int32_t  FilterTf;	//RC时间常数
     int32_t  FilterTs;//采样时间
     int32_t  Kr;
     int32_t  Ky;
	
} low_filter;


void low_filter_init(low_filter *v);
int16_t low_filter_calc(low_filter *v);


#endif
