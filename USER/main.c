#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"


/*********************************************************************************
			  ___   _     _____  _____  _   _  _____  _____  _   __
			 / _ \ | |   |_   _||  ___|| \ | ||_   _||  ___|| | / /
			/ /_\ \| |     | |  | |__  |  \| |  | |  | |__  | |/ /
			|  _  || |     | |  |  __| | . ` |  | |  |  __| |    \
			| | | || |_____| |_ | |___ | |\  |  | |  | |___ | |\  \
			\_| |_/\_____/\___/ \____/ \_| \_/  \_/  \____/ \_| \_/

 *	******************************************************************************
 *	����ԭ�� Pandora STM32L475 IoT������	ʵ��0-1
 *	Template����ģ��-�����½�ʹ��
 *	����֧�֣�www.openedv.com
 *	�Ա����̣�http://openedv.taobao.com
 *	��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 *	������������ӿƼ����޹�˾
 *	���ߣ�����ԭ�� @ALIENTEK
 *	******************************************************************************/


int main(void)
{
		u8 time = 0;
    u8 speed = 1;				//�ٶȿ���		0:����		1������
    u8 dir = 1;					//����ת��־	0:�����ת	1�������ת
    u16 pwmval = 500;			//Ĭ��ֵ

    HAL_Init();                         //��ʼ��HAL��
    SystemClock_Config();	            //��ʼ��ϵͳʱ��Ϊ80M
    delay_init(80);                		//��ʼ����ʱ����
    uart_init(115200);
	
	  LED_Init();				//��ʼ��LED
	  
	  PWM_Init(1000 - 1, 80 - 1); 	//TIM2ʱ��Ƶ�� 80M/80=1M   ����Ƶ��1M/1000=1KHZ     Ĭ��ռ�ձ�Ϊ50%
    while(1)
    {
			  if (speed)
				{
					  pwmval += 5;
				}
				else
				{
				    pwmval -= 5;
				}
				if (pwmval >= 1000) speed = 0;
				if (pwmval <= 500) {
				    speed = 1;
					  dir = dir ^ 0x01;
				}
				
				if (dir)
				{
				    TIM_SetTIM2Compare1(pwmval);
					  TIM_SetTIM2Compare2(0);
				}
				else
				{
				    TIM_SetTIM2Compare1(0);
					  TIM_SetTIM2Compare2(pwmval);
				}
				
				time++;
				if (time % 20 == 0)
				{
				    LED_B_TogglePin;
					  delay_ms(15);
				}
    }

}


