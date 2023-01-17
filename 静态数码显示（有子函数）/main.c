#include <REGX52.H>
unsigned char NumTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
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
}
void main()
{
	Nixie(6,5);
	while(1)
	{
		
	}
}