#ifndef __USART1_H
#define __USART1_H

#include "sys.h"
#include "time.h"
#include "stm32f4xx.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_rcc.h"


void USART1_Configuration(void);
void USART1_sendData(u8 *send_array,int num);
void Send_u16Data (u16 data);

#endif
