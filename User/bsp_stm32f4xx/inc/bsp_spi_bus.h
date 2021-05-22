/*
*********************************************************************************************************
*
*	ģ������ : SPI��������
*	�ļ����� : bsp_spi_bus.h
*	��    �� : V1.0
*	˵    �� : ͷ�ļ�
*
*	Copyright (C), 2014-2015, ���������� www.armfly.com
*
*********************************************************************************************************
*/

#ifndef __BSP_SPI_BUS_H
#define __BSP_SPI_BUS_H

#define SOFT_SPI		/* ������б�ʾʹ��GPIOģ��SPI�ӿ� */
//#define HARD_SPI		/* ������б�ʾʹ��CPU��Ӳ��SPI�ӿ� */

#ifdef SOFT_SPI		/* ���SPI */
	/* ����GPIO�˿� */
	#define RCC_SCK 	RCC_AHB1Periph_GPIOB
	#define PORT_SCK	GPIOB
	#define PIN_SCK		GPIO_Pin_7

	#define RCC_MOSI 	RCC_AHB1Periph_GPIOB
	#define PORT_MOSI	GPIOB
	#define PIN_MOSI	GPIO_Pin_5

	#define RCC_MISO 	RCC_AHB1Periph_GPIOB
	#define PORT_MISO	GPIOB
	#define PIN_MISO	GPIO_Pin_8

	#define SCK_0()		GPIO_ResetBits(PORT_SCK, PIN_SCK)
	#define SCK_1()		GPIO_SetBits(PORT_SCK, PIN_SCK)

	#define MOSI_0()	GPIO_ResetBits(PORT_MOSI, PIN_MOSI)
	#define MOSI_1()	GPIO_SetBits(PORT_MOSI, PIN_MOSI)

	#define MISO_IS_HIGH()	(GPIO_ReadInputDataBit(PORT_MISO, PIN_MISO) == Bit_SET)
#endif


#define CH_NUM			8				/* �ɼ�2ͨ�� */

/*
	��SPIʱ�������2��Ƶ����֧�ֲ���Ƶ��
	�����SPI1��2��ƵʱSCKʱ�� = 42M��4��ƵʱSCKʱ�� = 21M
	�����SPI3, 2��ƵʱSCKʱ�� = 21M
*/
#define SPI_SPEED_42M		SPI_BaudRatePrescaler_2
#define SPI_SPEED_21M		SPI_BaudRatePrescaler_4
#define SPI_SPEED_5_2M		SPI_BaudRatePrescaler_8
#define SPI_SPEED_2_6M		SPI_BaudRatePrescaler_16
#define SPI_SPEED_1_3M		SPI_BaudRatePrescaler_32
#define SPI_SPEED_0_6M		SPI_BaudRatePrescaler_64

void bsp_InitSPIBus(void);

void bsp_spiWrite0(uint8_t _ucByte);
uint8_t bsp_spiRead0(void);

void bsp_spiWrite1(uint8_t _ucByte);
uint8_t bsp_spiRead1(void);

uint8_t bsp_SpiBusBusy(void);

void bsp_SPI_Init(uint16_t _cr1);

void bsp_SpiBusEnter(void);
void bsp_SpiBusExit(void);
uint8_t bsp_SpiBusBusy(void);
void bsp_SetSpiSck(uint8_t _data);

#endif

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
