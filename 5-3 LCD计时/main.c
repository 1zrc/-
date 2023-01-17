#include <REGX52.H>
#include "Delay1ms.H"
#include "LCD1602.H"
void main()
{
	int result=0;
	while(1)
	{
		result++;
		Delay1ms(1000);
		LCD_ShowNum(1,1,result,3);
		
		
	}
}