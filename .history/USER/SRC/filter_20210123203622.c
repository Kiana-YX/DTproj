/*
 * @Author: your name
 * @Date: 2021-01-23 20:27:39
 * @LastEditTime: 2021-01-23 20:36:22
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \F4DT集合版\USER\SRC\filter.c
 */
#include "filter.h"

void low_filter_init(low_filter *v){
	
     v->Kr = v->FilterTs*1024/(v->FilterTs + v->FilterTf);
     v->Ky = v->FilterTf*1024/(v->FilterTs + v->FilterTf);
}

int16_t low_filter_calc(low_filter *v){

	int32_t tmp = 0;

	tmp = ((int32_t)v->Kr * v->Input + v->Ky * v->Output[1])/1024;
	
	if(tmp>32767){
		tmp = 32767;
	}
	
	if( tmp < -32768){
		tmp = -32768;
	}
	
    v->Output[0] = (int16_t)tmp;
    v->Output[1] = v->Output[0];
	return v->Output[0];
}
