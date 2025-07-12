#include "stm32h7xx_hal.h"
#include "key.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_KEY_CLK_ENABLE;						// ����ʱ��

	GPIO_InitStruct.Pin 	= KEY_PIN;				// ��������
	GPIO_InitStruct.Mode  	= GPIO_MODE_INPUT;	// ����ģʽ	
	GPIO_InitStruct.Pull 	= GPIO_PULLUP;			// ����
	
	HAL_GPIO_Init(KEY_PORT, &GPIO_InitStruct);	
}


uint8_t	KEY_Scan(void)
{
	if( HAL_GPIO_ReadPin ( KEY_PORT,KEY_PIN) == 0 )	//��ⰴ���Ƿ񱻰���
	{	
		HAL_Delay(10);	//��ʱ����
		if( HAL_GPIO_ReadPin ( KEY_PORT,KEY_PIN) == 0)	//�ٴμ���Ƿ�Ϊ�͵�ƽ
		{
			while(  HAL_GPIO_ReadPin ( KEY_PORT,KEY_PIN) == 0);	//�ȴ������ſ�
			return KEY_ON;	//���ذ������±�־
		}
	}
	return KEY_OFF;	
}


uint8_t KEY_Scan1(void) {
    static uint8_t keyPressCount = 0; // ��¼�������µĴ���
    static uint8_t keyPreviousState = KEY_OFF; // ���水������ǰ״̬

    if (HAL_GPIO_ReadPin(KEY_PORT, KEY_PIN) == GPIO_PIN_RESET) {
        HAL_Delay(10);	//��ʱ����
        if (HAL_GPIO_ReadPin(KEY_PORT, KEY_PIN) == GPIO_PIN_RESET && keyPreviousState == KEY_OFF) {
            while (HAL_GPIO_ReadPin(KEY_PORT, KEY_PIN) == GPIO_PIN_RESET); // �ȴ������ͷ�
            keyPressCount++; // �������´�����һ
            keyPreviousState = KEY_ON; // ������ǰ״̬
        }
    } else {
        keyPreviousState = KEY_OFF; // ����ťδ������ʱ������ǰ״̬
    }

    return keyPressCount; // ���ذ������´���
}








