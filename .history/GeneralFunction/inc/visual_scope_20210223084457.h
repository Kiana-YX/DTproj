#ifndef _VISUAL_SCOPE_H_
#define _VISUAL_SCOPE_H_

#include "stm32f4xx.h"
#include "usart1.h"
#include "includes.h"


extern u8 flag_scope;

void VS4Channal_Send(int16_t n_dataCH1, int16_t n_dataCH2, int16_t n_dataCH3, int16_t n_dataCH4);

#endif 
