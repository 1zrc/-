#include <REGX52.H>
#include <intrins.h>
char Num;//ȫ�ֱ����Զ���ʼ��Ϊ0
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
	unsigned char flag=0;//�ڶ�����ת��һ����
	unsigned char flag2=0;//��һ����ת�ڶ�����
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
			
			//�����Num++;������ᵼ����ǰ�ӣ�ʹ��һ���Ʋ���
			//���ǲ��ŵĻ����Ҽ��л�Ҫ������
			//��ʱ���԰�Num��ʼ��-1����P2=~��0x01��,�����߲��ð���һ���ƾ�����
			if(Num>=8)//��D1��D8
			{
				Num=0;
			}
			P2=~(0x01<<Num);			//P2=~(0x01<<Num%8);��������if
			Num++;
		}
		
			if(P3_0==0)//��D8��D1
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
			}//��8λ�����Ǵ�0���������7λ������--�ͱ�7��
			else
			{
				Num--;
			}
			
				P2=~(0x01<<Num);
	 }
 }
}
