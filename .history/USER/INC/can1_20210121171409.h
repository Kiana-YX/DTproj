/*
 * @Author: your name
 * @Date: 2021-01-11 14:04:15
 * @LastEditTime: 2021-01-21 17:14:08
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \F4DT集合版\USER\INC\can1.h
 */
#ifndef __CAN1_H
#define __CAN1_H

#include "sys.h"
#include "param.h"
#include "switch_param.h"	//光电开关相关系数
#include "stm32f4xx_can.h"
#include "stm32f4xx_rcc.h"

#define ID_GD_SELF 0x00010600	//光电开关按默认的来
#define ID_GD_BACK 0x00060101

#if Direct_SELECT == 40	//hu，x方向
	#define ID_SELF 0X01314153
	#define ID_BACK 0X05141313
	#define BROADCAST_ID 0x00010000
	#define GyroScope_ID_RX 0x00020101
#endif

#if Direct_SELECT == 41	//hu，y方向
	#define ID_SELF 0X01314154
	#define ID_BACK 0X05141314
	#define BROADCAST_ID 0x00010000
	#define GyroScope_ID_RX 0x00020101
#endif

#if Direct_SELECT == 01	//廖，x方向
	#define ID_SELF 0x00010300
	#define ID_BACK 0x00030101-0x20
	#define BROADCAST_ID 0x00010000
	#define GyroScope_ID_RX 0x00020101
#endif

#if Direct_SELECT == 11	//廖，y方向
	#define ID_SELF 0x00010300
	#define ID_BACK 0x00030101-0x20
	#define BROADCAST_ID 0x00010000
	#define GyroScope_ID_RX 0x00020101
#endif

void CAN1_Configuration(void);
void canSend_DT35(void);
void canSend_GD(void);
void CAN1_RX0_IRQHandler(void);
static void answer_master(const CanRxMsg *rx_message);
#endif
