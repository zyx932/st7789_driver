#include "tft_lib.h"

void main(void)
{
   
  // 配置引脚为推挽输出
    P3M0 = (1<<1) | (1<<2) | (1<<3);
    P3M1 = 0x00;
    P5M0 = (1<<4) | (1<<5);
    P5M1 = 0x00;
    // 2. 初始化屏幕
    LCD_Init();

    // 3. 清屏为白色
    LCD_Fill(RGB565_WHITE);

    // 4. 显示黑色文字
    LCD_ShowString8x16(80, 100, "hello,everyone", RGB565_BLACK, RGB565_WHITE);

    while (1) {}
}