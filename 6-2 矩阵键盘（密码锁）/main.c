#include <REGX52.H>
#include "Delay1ms.h"
#include "LCD1602.H"
#include "MatrixKey.h"
unsigned char KeyNum;
unsigned int password，count;//全局变量，不赋初值为0
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)//!=0,当没按时，不让unsigned char KeyNum=0;初始化，从而达到没有0,没有的话会很快刷新为0,所以加了这个让他停住
		{
			if(KeyNum<=10)//如果s1到s10按下
			{
				if(count<4)//限制次数，按4次
				{
					password*=10;//往左移动一位
					password+=KeyNum%10;//%10是让10变成0，获取一位密码
				  count++;//计次加一
				}
			LCD_ShowNum(1,2,password,4);//更新显示
			}	
			if(KeyNum=11)
			{
				//Delay1ms(20);while(KeyNum=11);Delay1ms(20);模块化编程消抖了，不用
				
				if(passward==1234)//如果密码为正确密码
				{
					LCD_ShowString(1,14,"OK ");//ok后面加空格，和err对应，不然err到ok最后一个r没变换，变成okr
					password=0;//密码清零
					count=0;//计次清零
					LCD_ShowNum(1,2,password,4);//更新显示
				}
				else//否则显示错误
				{
					LCD_ShowString(1,14,"ERR");
					password=0;//密码清零
					count=0;//计次清零
					LCD_ShowNum(1,2,password,4);//更新显示，边写边调试，不然没显示
				}
	    }
			if(KeyNum==12)//12键按下，取消
			{
				password=0;//密码清零
					count=0;//计次清零
					LCD_ShowNum(1,2,password,4);//更新显示
	    }
		}
	}
}
//只删除一位可以LCD_ShowNum(1,2,password=password/10,4);
//%循环，/删除