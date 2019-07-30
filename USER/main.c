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
 *	����ԭ�� Pandora STM32L475 IoT������	ʵ��0-1
 *	Template����ģ��-�����½�ʹ��
 *	����֧�֣�www.openedv.com
 *	�Ա����̣�http://openedv.taobao.com
 *	��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 *	������������ӿƼ����޹�˾
 *	���ߣ�����ԭ�� @ALIENTEK
 *	******************************************************************************/

/**
 * @brief	LED״̬���ú���
 *
 * @param   sta		״̬
 *
 * @return  void
 */
void led_set(u8 sta)
{
	LED_R(sta);
}
/**
 * @brief	�����������ò��Ժ���
 *
 * @param   ledset		����ָ��
 * @param   sta			�Ƶ�״̬
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

    HAL_Init();                         //��ʼ��HAL��
    SystemClock_Config();	            //��ʼ��ϵͳʱ��Ϊ80M
    delay_init(80);                		//��ʼ����ʱ����
    uart_init(115200);
    usmart_dev.init(80);	//��ʼ��USMART		80Mϵͳʱ��	
	
	  LED_Init();				//��ʼ��LED
	  
	  LCD_Init();				//��ʼ��LCD

		POINT_COLOR = RED;
		Display_ALIENTEK_LOGO(0, 0);
    LCD_ShowString(30, 95, 200, 16, 16, "Pandora STM32L4 IOT");
    LCD_ShowString(30, 115, 200, 16, 16, "USMART TEST");
    LCD_ShowString(30, 135, 200, 16, 16, "ATOM@ALIENTEK");
    LCD_ShowString(30, 155, 200, 16, 16, "2018/10/27");
	
	
		while(1)
    {
        LED_B_TogglePin;	//ָʾ����״̬
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


