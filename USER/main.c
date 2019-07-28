#include "sys.h"
#include "delay.h"
// #include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"

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


/*ע�⣺�����̺ͽ̳�3.4С�ڳ������ص��Թ��̶�Ӧ*/

int main(void)
{
		u8 key;

    HAL_Init();                         //��ʼ��HAL��
    SystemClock_Config();	            //��ʼ��ϵͳʱ��Ϊ80M
    delay_init(80);                		//��ʼ����ʱ����
   
	  LED_Init();				//��ʼ��LED
    BEEP_Init();			//��ʼ��������
	  KEY_Init();       // init key
	

    while(1)
    {
				key = KEY_Scan(0); // not support press in series
			
			  switch(key)
				{
					case WKUP_PRES:
						BEEP_TogglePin;
					  break;
					
					case KEY2_PRES:
						LED_B_TogglePin;
					  break;
					
					case KEY1_PRES:
						LED_G_TogglePin;
						break;
					
					case KEY0_PRES:
						LED_R_TogglePin;
						break;
					
					default:
						break;
				}
			
				delay_ms(10);
    }
}


