#ifndef __TFT_LIB_H__
#define __TFT_LIB_H__

#include "reg51.h"
#include "intrins.h"

//-----------------------------------------------
//  STC8G 特殊功能寄存器定义 (如果 reg51.h 未包含)
//-----------------------------------------------
sfr AUXR   = 0x8E;
sfr P3M0   = 0xB2;
sfr P3M1   = 0xB1;
sfr P5M0   = 0xCA;
sfr P5M1   = 0xC9;
sfr P5     = 0xC8;

//-----------------------------------------------
//  用户需根据实际硬件修改以下引脚定义！
//-----------------------------------------------
sbit LCD_LED = P5^5;   // 背光控制 (高电平点亮)
sbit LCD_SCL = P5^4;   // SPI 时钟
sbit LCD_SDA = P3^3;   // SPI 数据
sbit LCD_CS  = P3^2;   // 片选 (低有效)
sbit LCD_DC  = P3^1;   // 数据/命令 (低:命令, 高:数据)

//-----------------------------------------------
//  常用颜色 (RGB565)
//-----------------------------------------------
#define RGB565_BLACK    0x0000
#define RGB565_WHITE    0xFFFF
#define RGB565_RED      0xF800
#define RGB565_GREEN    0x07E0
#define RGB565_BLUE     0x001F
#define RGB565_YELLOW   0xFFE0
#define RGB565_CYAN     0x07FF
#define RGB565_MAGENTA  0xF81F
#define RGB565_ORANGE   0xFC00

//-----------------------------------------------
//  函数声明
//-----------------------------------------------
void LCD_WriteCmd(unsigned char cmd);
void LCD_WriteData(unsigned char dat);
void LCD_WriteData16(unsigned int color);
void LCD_SetWindow(unsigned int xs, unsigned int ys, unsigned int xe, unsigned int ye);
void LCD_Init(void);
void LCD_Fill(unsigned int color);
void LCD_FillRect(unsigned int xs, unsigned int ys, unsigned int xe, unsigned int ye, unsigned int color);
void LCD_DrawPixel(unsigned int x, unsigned int y, unsigned int color);
void LCD_ShowChar8x16(unsigned int x, unsigned int y, char ch, unsigned int fg_color, unsigned int bg_color);
void LCD_ShowString8x16(unsigned int x, unsigned int y, const char *str, unsigned int fg_color, unsigned int bg_color);
void LCD_ShowPicture(unsigned int x, unsigned int y, unsigned int w, unsigned int h, const unsigned char *pic);
void delay_ms(unsigned int ms);

#endif