/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-01-26 18:44:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \F4DT集合版\USER\INC\param.h
 */
#ifndef _PARAM_H_
#define _PARAM_H_

#include "kalman.h"
#include "filter.h"
#include "stdbool.h"
#include "stm32f4xx.h"

//hu  2号（李茂QA1），号
#define DT_SELECT 	0x50		//00保留测试
								//0x01壹号DT
								//0x02 贰号DT
								//0x03 叁号DT
								//0x04 肆号DT
								//0x05 伍号DT
								//0x50 DT50
#define Direct_SELECT 0x41		//第一位4表示胡凯鹏，5表示廖建斌
								//第二位0表示x轴，1表示y轴方向
								
#define TEST 0X01								

/****主控数据传输结构体体****/
typedef struct{
  bool enable;            //数据传输使能
  u8 mode;                //传输模式  1：间隔一段时间发送一次数据 2：收到查询后反馈数据
  u8 cnt;                 //数据传输次数
  u8 time;                //传输时间间隔，接收主控数据后修改
  u8 loop;                //传输间隔时间循环
}TransimitTypeDef;

extern TransimitTypeDef DT_transmit;

void paramInit(void);
  
#endif

