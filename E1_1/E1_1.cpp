///////////////////////////////////////////////////////////////////////////////////////
//�������ƣ�E1_1 һ�ʻ�
//���뻷����Microsoft Visual Studio Ultimate 2013 EasyX_2014������
//���ߣ���۲�<1206020120>
//����޸�:2015-09-22
#include <graphics.h>   
#include <conio.h>
int main()
{
	int pointAx = 160, pointAy = 240, pointBx = 480, pointBy = 240, x;	//A,BΪ��������
	initgraph(640, 480);
	setbkcolor(BLUE);
	cleardevice();
	moveto(pointAx, pointAy);
	for (x = 0; x <= 320; x += 20)
	{
		lineto(pointAx + x, pointAy - 120);
		lineto(pointBx, pointBy);
		lineto(pointBx - x, pointBy + 120);
		lineto(pointAx, pointAy);
		//line(pointAx, pointAy, pointAx + x, pointAy - 120);
		//line(pointAx + x, pointAy - 120, pointBx, pointBy);
		//line(pointBx, pointBy, pointBx - x, pointBy + 120);
		//line(pointBx - x, pointBy + 120, pointAx, pointAy);
	}
	_getch();
	closegraph();
	return 0;
}