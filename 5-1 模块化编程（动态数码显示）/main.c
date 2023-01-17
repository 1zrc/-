#include <REGX52.H>
#include "Delay1ms.h"
#include "Nixie.h"
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