#ifndef __SPI_H
#define __SPI_H

#include "sys.h"
#include "stm32f4xx_spi.h"
#include "param.h"

int Read_ADC1_Value(void);
int Read_ADC2_Value(void);
void SPI1_Configuration(void);
void SPI2_Configuration(void);

extern int adc_value1;
extern int adc_value2;

#endif
