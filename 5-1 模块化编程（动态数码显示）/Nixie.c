#include <REGX52.H>//�⹤����Ҳ������������
#include "Delay1ms.H"//""�����ù������ļ����Զ��壩
unsigned char NumTable[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void Nixie(unsigned char location,Num)
{
	switch(location)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;//�����Կ�����if   else if   else if...else
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
	  case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
	  case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	//P2=~(location-1);���У���������
	P0=NumTable[Num];//�±���Ԫ��
	Delay1ms(1);//̫�̵Ļ�����ܻ��������㣬��Ƚϰ�
	P0=0x00;//��Ӱ(����ѡ)�������Ļ�������ʾ�е��ң���Ϊ�仯̫���Ӱ�쵽��һ��λѡ��
}