#include "sys.h"
#include "delay.h"
#include "usart.h"

/*********************************************************************************
			  ___   _     _____  _____  _   _  _____  _____  _   __
			 / _ \ | |   |_   _||  ___|| \ | ||_   _||  ___|| | / /
			/ /_\ \| |     | |  | |__  |  \| |  | |  | |__  | |/ /
			|  _  || |     | |  |  __| | . ` |  | |  |  __| |    \
			| | | || |_____| |_ | |___ | |\  |  | |  | |___ | |\  \
			\_| |_/\_____/\___/ \____/ \_| \_/  \_/  \____/ \_| \_/

 *	******************************************************************************
 *	???? Pandora STM32L475 IoT???	??0-1
 *	Template????????????
 *	????:www.openedv.com
 *	????:http://openedv.taobao.com
 *	???????????:"????",????STM32???
 *	?????????????
 *	??:???? @ALIENTEK
 *	******************************************************************************/


void Delay(__IO uint32_t nCount);
void Delay(__IO uint32_t nCount)
{
    while(nCount--) {};
}

int main(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    HAL_Init();                         //???HAL?
    SystemClock_Config();	            //????????80M
	
    __HAL_RCC_GPIOE_CLK_ENABLE();       //??GPIOE??

    GPIO_InitStruct.Pin = GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; 	//????
    GPIO_InitStruct.Pull = GPIO_PULLUP;				//??
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;	//??
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    while(1)
    {
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET); 	//PE7 ?1
        Delay(0x7FFFFF);
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_RESET);	//PE7 ?0
        Delay(0x7FFFFF);
    }
}
