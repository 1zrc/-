#include <REGX52.H>
#include "Delay1ms.h"
#include "LCD1602.H"
#include "MatrixKey.h"
unsigned char KeyNum=0;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"MatrixKey:")
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)//!=0,当没按时，不让unsigned char KeyNum=0;初始化，从而达到没有0,没有的话会很快刷新为0,所以加了这个让他停住
			LCD_ShowNum(1,2,KeyNum,2);
	}
}
