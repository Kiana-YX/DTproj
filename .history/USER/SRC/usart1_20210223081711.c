#include "usart1.h"

void USART1_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  //使能GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); //使能USART1时钟
	USART_DeInit(USART1);								   //串口复位

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1); //PA9 复用为 USART1
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10; //GPIOA9 与 GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;			//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//速度 50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;			//推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;			//上拉
	GPIO_Init(GPIOA, &GPIO_InitStructure);					//初始化 PA9，PA10

	//串口参数初始化
	USART_InitStruct.USART_BaudRate = 115200;	//								 //波特率设置
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;					 //字长为8位数据格式
	USART_InitStruct.USART_StopBits = USART_StopBits_1;							 //一个停止位
	USART_InitStruct.USART_Parity = USART_Parity_No;							 //奇偶校验位
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //无硬件数据流控制
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;				 //收发模式
	USART_Init(USART1, &USART_InitStruct);

	NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 3; //抢占优先级 3
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;		   //子优先级 3
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;		   //IRQ 通道使能
	NVIC_Init(&NVIC_InitStruct);						   //中断优先级初始化

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //当接收寄存器非空时，开启中断read register not empty(一有数据就开中断，yi)
	USART_Cmd(USART1, ENABLE);
}

void USART1_sendData(u8 *send_array, int num) //串口发送数组
{
	int i = 0;
	while (i < num)
	{
		while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
			; //防止数据被覆盖
		USART_SendData(USART1, send_array[i]);
		i++;
	}
}

void Send_u16Data(u16 data)
{
	while ((USART1->SR & 0X40) == 0)
		; // SR第六位为TC 发送完成时一帧数据为1
	USART1->DR = (u8)(data >> 8);
	while ((USART1->SR & 0X40) == 0)
		;
	USART1->DR = (u8)(data);
}
