#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "usmart.h"


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

/**
 * @brief	LED状态设置函数
 *
 * @param   sta		状态
 *
 * @return  void
 */
void led_set(u8 sta)
{
	LED_R(sta);
}
/**
 * @brief	函数参数调用测试函数
 *
 * @param   ledset		函数指针
 * @param   sta			灯的状态
 *
 * @return  void
 */
void test_fun(void(*ledset)(u8),u8 sta)
{
	ledset(sta);
}

int main(void)
{
		u8 color = 0;

    HAL_Init();                         //初始化HAL库
    SystemClock_Config();	            //初始化系统时钟为80M
    delay_init(80);                		//初始化延时函数
    uart_init(115200);
    usmart_dev.init(80);	//初始化USMART		80M系统时钟	
	
	  LED_Init();				//初始化LED
	  
	  LCD_Init();				//初始化LCD

		POINT_COLOR = RED;
		Display_ALIENTEK_LOGO(0, 0);
    LCD_ShowString(30, 95, 200, 16, 16, "Pandora STM32L4 IOT");
    LCD_ShowString(30, 115, 200, 16, 16, "USMART TEST");
    LCD_ShowString(30, 135, 200, 16, 16, "ATOM@ALIENTEK");
    LCD_ShowString(30, 155, 200, 16, 16, "2018/10/27");
	
	
		while(1)
    {
        LED_B_TogglePin;	//指示运行状态
        delay_ms(300);
    }
//	  while(1)
//    {
//			  switch(color % 12)
//        {
//            case 0:
//                LCD_Clear(WHITE);
//                break;
//            case 1:
//                LCD_Clear(BLACK);
//                break;
//            case 2:
//                LCD_Clear(BLUE);
//                break;
//            case 3:
//                LCD_Clear(RED);
//                break;
//            case 4:
//                LCD_Clear(MAGENTA);
//                break;
//            case 5:
//                LCD_Clear(GREEN);
//                break;
//            case 6:
//                LCD_Clear(CYAN);
//                break;
//            case 7:
//                LCD_Clear(YELLOW);
//                break;
//            case 8:
//                LCD_Clear(BRRED);
//                break;
//            case 9:
//                LCD_Clear(GRAY);
//                break;
//            case 10:
//                LCD_Clear(LGRAY);
//                break;
//            case 11:
//                LCD_Clear(BROWN);
//                break;
//            default :
//                color = 0;
//                break;
//        }

//        Display_ALIENTEK_LOGO(0, 0);
//        POINT_COLOR = RED;
//        BACK_COLOR = WHITE;
//        LCD_ShowString(0, 100, 240, 32, 32, "Pandora STM32L4");
//        LCD_ShowString(0, 140, 240, 24, 24, "TFTLCD TEST 240*240");

//        POINT_COLOR = WHITE;
//        BACK_COLOR = BLUE;
//        LCD_ShowString(0, 170, 240, 16, 16, "ATOM@ALIENTEK");
//        LCD_ShowString(0, 200, 240, 12, 12, "2018/10/28");
//				LCD_ShowString(0, 220, 240, 12, 12, "-- alick --");
//        color++;
//        LED_B_TogglePin;
//        delay_ms(1000);
//    }

}


