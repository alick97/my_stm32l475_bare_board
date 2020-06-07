#include "key_sample.h"

/* 定义 LED 亮灭电平 */
#define LED_ON PIN_LOW
#define LED_OFF PIN_HIGH

/* 定义 KEY 按压电平 */
#define KEY_PRESS PIN_LOW
#define KEY_POP PIN_HIGH

#define PIN_LED_G  GET_PIN(E, 8)  // PE8 :  LED_B  --> LED
#define PIN_KEY0 GET_PIN(D, 10)  // PD10:  KEY0  --> KEY

void key_sample() {
    unsigned int count = 1;
    /* 设 置 RGB 灯 引 脚 的 模 式 为 输 出 模 式 */
    rt_pin_mode(PIN_LED_G , PIN_MODE_OUTPUT);
    /* 设 置 KEY0 引 脚 的 模 式 为 输 入 模 式 */
    rt_pin_mode(PIN_KEY0 , PIN_MODE_INPUT);
    while (count > 0) {
        /* 读 取 PIN_KEY0 引 脚 状 态 */
        if (rt_pin_read(PIN_KEY0) == KEY_PRESS) {
            rt_thread_mdelay(50);
            if (rt_pin_read(PIN_KEY0) == KEY_PRESS) {
                rt_kprintf("KEY0 pressed!\n");
                rt_pin_write(PIN_LED_G , LED_ON);
            }
        } else {
            rt_pin_write(PIN_LED_G, LED_OFF);
        }
        rt_thread_mdelay(10);
        count++;
    }
}
