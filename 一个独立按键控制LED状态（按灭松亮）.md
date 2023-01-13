```c
#include <REGX52.H>
#include <intrins.H>
void Delay1ms(unsigned int xms)		//@11.0592MHz
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
	}
}
void main()
{
	while(1)
	{
		if(P3_1==0)
		{
			Delay1ms(20);//消去按时按键抖动
			while(P3_1==0);//循环空语句，让按下时一直处于前面状态
			Delay1ms(20);//消去松时按键抖动
			P2_0=~P2_0;//取反（反复横跳）
		}
	}
}//P2_0开始没设置就是1没亮
//按下>消抖>不亮>松开>跳出循环>消抖>P2_0的1取反变成0>亮
//1.若不按进不去循环一直亮为0
//2.若按下>消抖>亮>松开>跳出循环>消抖>P2_0的0取反变成1>不亮
```

