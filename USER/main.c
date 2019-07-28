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
		u8 key;

    HAL_Init();                         //初始化HAL库
    SystemClock_Config();	            //初始化系统时钟为80M
    delay_init(80);                		//初始化延时函数
   
	  LED_Init();				//初始化LED
    BEEP_Init();			//初始化蜂鸣器
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


