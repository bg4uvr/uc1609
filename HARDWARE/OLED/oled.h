#ifndef __OLED_H
#define __OLED_H

#include "sys.h"

//定义OLED借口
//RST脚直接接在MCU的复位脚上
//CS直接接地
//SCK接PA5
//SDA接PA7
#define	OLED_DC		PAout(6)

//声明功能函数
void OLED_Init(void);
void OLED_Clear(unsigned char rev);
void display_one_char(unsigned char x,unsigned char y,char char_data,unsigned char rev);
void display_list_char(unsigned char x,unsigned char y,char *data_s,unsigned char rev);
void display_816_char(unsigned char x,unsigned char y,char char_data, unsigned char rev);
void display_list_816(unsigned char x,unsigned char y,char *data_s, unsigned char rev);

void GUI_Point(unsigned char X,unsigned char Y,unsigned char draw_mode);
void glcd_line(int x1, int y1, int x2, int y2, unsigned char show) ;
void glcd_circle(int x, int y, int radius, unsigned char show);

#endif
