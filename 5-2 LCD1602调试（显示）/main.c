#include <REGX52.H>
#include "LCD1602.H"
//�ӱ�ĵط��õ�����Ҫ�ȵ����Ϸ�����Ŀ�ļ���Ȼ��Ѵ����ļ����Ƶ����棡����
//Ȼ���group1����all����ļ�,��Ȼ�Ҽ�include���޷��鿴��
void main()
{
	LCD_Init();//��ʼ��
	LCD_ShowChar(1,1,'A');//�У��У�����
	LCD_ShowString(1,3,"hello");
	LCD_ShowNum(1,9,123,3);//���һ������ʾ���ȣ�2��23��4��0123
	LCD_ShowSignedNum(1,13,-66,2);
	LCD_ShowHexNum(2,1,0xA8,2);//��λʮ��������
	LCD_ShowBinNum(2,4,0xAA,8);//�����Ƶ���ʮ�����Ʊ�ʾ
	while(1)
	{
		
	}
}