#include "param.h"

TransimitTypeDef DT_transmit;

void paramInit(void)
{
	Kalman_Init();
	
  {//DT标志位初始化
    DT_transmit.mode = 1;
	DT_transmit.enable = 0;
	DT_transmit.loop = 1;
  }
}


