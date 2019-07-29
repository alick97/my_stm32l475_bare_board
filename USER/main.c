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
 *	正点原子 Pandora STM32L475 IoT开发板	实验0-1
 *	Template工程模板-调试章节使用
 *	技术支持：www.openedv.com
 *	淘宝店铺：http://openedv.taobao.com
 *	关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 *	广州市星翼电子科技有限公司
 *	作者：正点原子 @ALIENTEK
 *	******************************************************************************/


/*注意：本工程和教程3.4小节程序下载调试工程对应*/

int main(void)
{
		u8 len = 0;
	  u16 times = 0;

    HAL_Init();                         //初始化HAL库
    SystemClock_Config();	            //初始化系统时钟为80M
    delay_init(80);                		//初始化延时函数
    uart_init(115200);
	
	  LED_Init();				//初始化LED
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


