#ifndef __CAN1_H
#define __CAN1_H

#include "sys.h"
#include "param.h"
#include "switch_param.h"
#include "stm32f4xx_can.h"
#include "stm32f4xx_rcc.h"

#define ID_GD_SELF 0x00010600
#define ID_GD_BACK 0x00060101

#if Direct_SELECT == 1	//y方向
	#define ID_SELF 0X01314154
	#define ID_BACK 0X05141314
#endif

#if DT_SELECT == 0x00
	#define ID_SELF 0x00010300
	#define ID_BACK 0x00030101
	#define BROADCAST_ID 0x00010000
	#define GyroScope_ID_RX 0x00020101
#endif

#if DT_SELECT == 0x01
	#define ID_SELF 0x00010300
	#define ID_BACK 0x00030101
	#define BROADCAST_ID 0x00010000
	#define GyroScope_ID_RX 0x00020101
#endif

#if DT_SELECT == 0x02
	#define ID_SELF 0X01314154
	#define ID_BACK 0X05141314
	#define BROADCAST_ID 0x00010000
	#define GyroScope_ID_RX 0x00020101
#endif
//hu，y方向
#if DT_SELECT == 0x03
	#define ID_SELF 0X01314154
	#define ID_BACK 0X05141314
	#define BROADCAST_ID 0x00010000
	#define GyroScope_ID_RX 0x00020101
#endif
//hu，x方向
#if DT_SELECT == 0x04
	#define ID_SELF 0X01314153
	#define ID_BACK 0X05141313
	#define BROADCAST_ID 0x00010000
	#define GyroScope_ID_RX 0x00020101
#endif

#if DT_SELECT == 0x05
	#define ID_SELF 0x00010300
	#define ID_BACK 0x00030101
	#define BROADCAST_ID 0x00010000
	#define GyroScope_ID_RX 0x00020101
#endif

void CAN1_Configuration(void);
void canSend_DT35(void);
void canSend_GD(void);
void CAN1_RX0_IRQHandler(void);
static void answer_master(const CanRxMsg *rx_message);
#endif
