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
		if(KeyNum)//!=0,��û��ʱ������unsigned char KeyNum=0;��ʼ�����Ӷ��ﵽû��0,û�еĻ���ܿ�ˢ��Ϊ0,���Լ����������ͣס
			LCD_ShowNum(1,2,KeyNum,2);
	}
}
