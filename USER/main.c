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
		u8 time = 0;
    u8 speed = 1;				//速度控制		0:加速		1：减速
    u8 dir = 1;					//正反转标志	0:电机正转	1：电机反转
    u16 pwmval = 500;			//默认值

    HAL_Init();                         //初始化HAL库
    SystemClock_Config();	            //初始化系统时钟为80M
    delay_init(80);                		//初始化延时函数
    uart_init(115200);
	
	  LED_Init();				//初始化LED
	  
	  PWM_Init(1000 - 1, 80 - 1); 	//TIM2时钟频率 80M/80=1M   计数频率1M/1000=1KHZ     默认占空比为50%
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


