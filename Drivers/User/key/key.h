#ifndef _KEY_H
#define _KEY_H


#include "main.h"

#define	KEY_ON	 1		//��������
#define	KEY_OFF	 0		//�����ſ�

/*------------------------------------------ IO�����ú� ----------------------------------*/


#define KEY_PIN           					GPIO_PIN_1        				 // KEY ����      
#define	KEY_PORT          					GPIOC                			 // KEY GPIO�˿�     
#define __HAL_RCC_KEY_CLK_ENABLE            __HAL_RCC_GPIOC_CLK_ENABLE()	 // KEY GPIO�˿�ʱ��

/*------------------------------------------ �������� ------------------------------------*/

void 	KEY_Init(void);	//����IO�ڳ�ʼ������
uint8_t	KEY_Scan(void);   //����ɨ��
uint8_t	KEY_Scan1(void);   //����ɨ��

#endif
