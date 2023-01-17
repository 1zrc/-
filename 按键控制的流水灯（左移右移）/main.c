#include <REGX52.H>
#include <intrins.h>
char Num;//全局变量自动初始化为0
void Delay1ms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}
void main()
{
	unsigned char flag=0;//第二部分转第一部分
	unsigned char flag2=0;//第一部分转第二部分
	while(1)
	{
		if(P3_1==0)
		{
			flag2=1;
			if(flag==1)
			{
				Num++;
			 flag=0;
			}
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			
			//如果把Num++;放这里会导致提前加，使第一个灯不亮
			//但是不放的话左右键切换要按两次
			//这时可以把Num初始成-1或者P2=~（0x01）,但后者不用按第一个灯就亮了
			if(Num>=8)//从D1到D8
			{
				Num=0;
			}
			P2=~(0x01<<Num);			//P2=~(0x01<<Num%8);这样不用if
			Num++;
		}
		
			if(P3_0==0)//从D8到D1
		{
			flag=1;
			Delay1ms(20);
			while(P3_0==0);
			Delay1ms(20);
			
			if(flag2==1&&Num!=0)
			{
				Num--;
				flag2=0;
			}
			if(Num==0)
			{
				Num=7;
			}//有8位，但是从0起，所以最高7位，后面--就变7了
			else
			{
				Num--;
			}
			
				P2=~(0x01<<Num);
	 }
 }
}
