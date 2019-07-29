#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "beep.h"
#include "key.h"
#include "exti.h"
#include "iwdg.h"


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


int main(void)
{
    HAL_Init();                         //初始化HAL库
    SystemClock_Config();	            //初始化系统时钟为80M
    delay_init(80);                		//初始化延时函数
    uart_init(115200);
	
	  LED_Init();				//初始化LED
	  KEY_Init();

	  delay_ms(100);
	  IWDG_Init(IWDG_PRESCALER_64, 500); // over time = 1s, (4*2^4*500/32=1000ms)
	  LED_B(0);
	
	  while (1)
		{
		    if (KEY_Scan(0) == WKUP_PRES)
				{
				    IWDG_Feed();
				}
				
				delay_ms(10);
		}

}


