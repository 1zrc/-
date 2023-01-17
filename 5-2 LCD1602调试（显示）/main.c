#include <REGX52.H>
#include "LCD1602.H"
//从别的地方拿到代码要先点左上方打开项目文件，然后把代码文件复制到里面！！！
//然后点group1，打开all添加文件,不然右键include是无法查看的
void main()
{
	LCD_Init();//初始化
	LCD_ShowChar(1,1,'A');//行，列，内容
	LCD_ShowString(1,3,"hello");
	LCD_ShowNum(1,9,123,3);//最后一个是显示长度，2是23，4是0123
	LCD_ShowSignedNum(1,13,-66,2);
	LCD_ShowHexNum(2,1,0xA8,2);//两位十六进制数
	LCD_ShowBinNum(2,4,0xAA,8);//二进制但是十六进制表示
	while(1)
	{
		
	}
}