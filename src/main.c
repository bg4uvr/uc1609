#include "led.h"
#include "delay.h"
#include "sys.h"
#include "oled.h"
#include "stdlib.h"

int main(void)
{
	delay_init();	    	//延时函数初始化
	LED_Init();		  		//初始化与LED连接的硬件接口
	OLED_Init();			//初始化OLED
	OLED_Clear(1);
	delay_ms(1000);
	OLED_Clear(0);

	display_list_816(rand()%192,rand()%7,"OLED TEST",0);


/*
	u8 j=31;

	while(1)
	{
		for(u8 i=0;i<192;i++)
		{
			glcd_line(i,0,i,63,0);
			u8 k=rand()%3;
			if(k==0)
			{
				j++;
				if(j>=64)	j=0;
			}
			else if(k==1)
			{
				j--;
				if(j==0)	j=63;
			}

			GUI_Point(i,j,1);
			delay_ms(5);
		}
	}
*/

	u8 i,j;
	while (1)
	{
		switch(i)
		{
			case 0:
			display_816_char(rand()%192/8*8,rand()%8/2*2,rand()%96+0x20,rand()%2);
			delay_ms(10);
			break;

			case 1:
			glcd_line(rand()%192,rand()%64,rand()%128,rand()%64,rand()%3);
			delay_ms(10);
			break;

			case 2:
			glcd_circle(rand()%192,rand()%64,rand()%90,rand()%3);
			delay_ms(10);
			break;

			case 3:
			GUI_Point(rand()%192,rand()%64,rand()%3);
			delay_ms(10);
			break;
		}
		if(++j==250)
		{
			j=0;
			OLED_Clear(0);
			if(++i==4)
				i=0;
		}
	}
}
