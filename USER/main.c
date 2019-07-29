#include "sys.h"
#include "delay.h"
#include "usart.h"
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
		u8 len = 0;
	  u16 times = 0;

    HAL_Init();                         //��ʼ��HAL��
    SystemClock_Config();	            //��ʼ��ϵͳʱ��Ϊ80M
    delay_init(80);                		//��ʼ����ʱ����
    uart_init(115200);
	
	  LED_Init();				//��ʼ��LED
	  KEY_Init();       // init key
    
	

    while(1)
    {
        if (USART_RX_STA & 0x8000)
				{
				    len = USART_RX_STA & 0x3fff;
					  printf("\r\nyour send message is:\r\n");
					  HAL_UART_Transmit(&UART1_Handler, (uint8_t*)USART_RX_BUF, len, 1000);
					  
					  while(__HAL_UART_GET_FLAG(&UART1_Handler, UART_FLAG_TC) != SET);
					
					  printf("\r\n\r\n");
					  USART_RX_STA = 0;
				}
				else
				{
				    times++;
					
					  if (times % 5000 == 0)
						{
						    printf("\r\n ALIENTEK STM32L475 USART TEST\r\n");
						}
						
						if (times % 200 == 0) printf("Please input content, enter to finish\r\n");
						if (times % 30 == 0) LED_B_TogglePin;
						
						delay_ms(10);
				}
    }
}


