#include <REGX52.H>
#include <intrins.h>
unsigned char NumTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void Delay1ms(unsigned char xms)		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	while(xms)
	{
			i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
  }
}
void Nixie(unsigned char location,Num)
{
	switch(location)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;//还可以可以用if   else if   else if...else
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
	  case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
	  case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	//P2=~(location-1);不行，串脚乱了
	P0=NumTable[Num];//下标找元素
	Delay1ms(1);//太短的话数码管会立刻清零，会比较暗
	P0=0x00;//消影(消段选)（不消的话可能显示有点乱，因为变化太快会影响到下一个位选）
}
void main()
{
	while(1)
	{
			Nixie(1,1);
		//Delay1ms(0.1);
		Nixie(2,2);
		//Delay1ms(0.1);
		Nixie(3,3);
		//Delay1ms(0.1);不行，速度太快会有残影，要消影
	}
}
//位选》段选》清零》位选》段选》清零...