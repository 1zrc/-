#include <REGX52.H>
#include "Delay1ms.h"
#include "LCD1602.H"
#include "MatrixKey.h"
unsigned char KeyNum;
unsigned int password��count;//ȫ�ֱ�����������ֵΪ0
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)//!=0,��û��ʱ������unsigned char KeyNum=0;��ʼ�����Ӷ��ﵽû��0,û�еĻ���ܿ�ˢ��Ϊ0,���Լ����������ͣס
		{
			if(KeyNum<=10)//���s1��s10����
			{
				if(count<4)//���ƴ�������4��
				{
					password*=10;//�����ƶ�һλ
					password+=KeyNum%10;//%10����10���0����ȡһλ����
				  count++;//�ƴμ�һ
				}
			LCD_ShowNum(1,2,password,4);//������ʾ
			}	
			if(KeyNum=11)
			{
				//Delay1ms(20);while(KeyNum=11);Delay1ms(20);ģ�黯��������ˣ�����
				
				if(passward==1234)//�������Ϊ��ȷ����
				{
					LCD_ShowString(1,14,"OK ");//ok����ӿո񣬺�err��Ӧ����Ȼerr��ok���һ��rû�任�����okr
					password=0;//��������
					count=0;//�ƴ�����
					LCD_ShowNum(1,2,password,4);//������ʾ
				}
				else//������ʾ����
				{
					LCD_ShowString(1,14,"ERR");
					password=0;//��������
					count=0;//�ƴ�����
					LCD_ShowNum(1,2,password,4);//������ʾ����д�ߵ��ԣ���Ȼû��ʾ
				}
	    }
			if(KeyNum==12)//12�����£�ȡ��
			{
				password=0;//��������
					count=0;//�ƴ�����
					LCD_ShowNum(1,2,password,4);//������ʾ
	    }
		}
	}
}
//ֻɾ��һλ����LCD_ShowNum(1,2,password=password/10,4);
//%ѭ����/ɾ��