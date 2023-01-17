#include <REGX52.H>
#include <intrins.H>
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
	unsigned char LEDNuw=0;//因为寄存器也是和unsigned一样八位所以用char比int好
	while(1)
	{
		if(P3_1==0)
		{
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			LEDNuw++;
			P2=~LEDNuw;//P2=~(LEDNuw++);
		}
	}
}
		//P2--?不行，亮的顺序不对
//P2=0x00++;P2=~P2?
	