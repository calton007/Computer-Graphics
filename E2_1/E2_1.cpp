///////////////////////////////////////////////////////////////////////////////////////
//�������ƣ�E2_1 ��ֱ��  �������
//���뻷����Microsoft Visual Studio Ultimate 2013 EasyX_2014������
//���ߣ���۲�<1206020120>
//����޸�:2015-09-29
#include <graphics.h>      
#include <conio.h>
#include <stdio.h>
void drawline(int x0, int y0, int x1, int y1, int color)
{
	int a, b, d, deltax, deltay;
	double k;
	a = y1 - y0;
	b = x1 - x0;
	deltax = 2 * b;
	deltay = 2 * a;	
	k = 1.0 * a / b;
	putpixel(x0, y0, color);
	if (b == 0)	//k�����ڵ�ʱ��ֱ��ƽ����y�ᣩ
	{
		if (y0 > y1)
		{
			int t;
			t = y0;
			y0 = y1;
			y1 = t;
		}
		while (y0 < y1)
		{
			y0++;
			putpixel(x0, y0, color);			
		}
	}
	else
	{
		if (0 <= k && k <= 1)	//0<=k<=1
		{
			d = -b;
			while (y0 != y1)
			{
				d += deltay;
				if (d > 0)
				{
					y0++;
					d -= deltax;
				}
				x0++;
				putpixel(x0, y0, color);
			}
		}
		else if (k > 1)		//k>1
		{
			d = -a;
			while (y0 != y1)
			{
				d += deltax;
				if (d > 0)
				{
					x0++;
					d -= deltay;
				}
				y0++;
				putpixel(x0, y0, color);
			}
		}
		else if (k < 0 && k >= -1)	//-1<=k<0
		{
			d = -b;
			while (x0 != x1)
			{
				d -= deltay;
				if (d > 0)
				{
					y0--;
					d -= deltax;
				}
				x0++;
				putpixel(x0, y0, color);
			}
		}
		else if (k < -1)		//k<-1;
		{
			d = -a;
			while (y0 != y1)
			{
				d -= deltax;
				if (d < 0)
				{
					x0++;
					d -= deltay;
				}
				y0--;
				putpixel(x0, y0, color);
			}
		}
	}
}
int main()
{
	// ��ʼ��ͼ�δ���
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLUE);
	MOUSEMSG m;		// ���������Ϣ
	int x0, y0, x1, y1, flag = 1;
	while(true)
	{
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();
		//��¼�������
		if (flag==1 && m.uMsg == WM_LBUTTONDOWN)
		{
			x0 = m.x;
			y0 = m.y;
			flag = 2; 
			rectangle(x0 - 3, y0 - 3, x0 + 3, y0 + 3);
		}
		//��¼�յ�����
		else if (flag == 2 && m.uMsg == WM_LBUTTONDOWN)
		{
			x1 = m.x;
			y1 = m.y;
			flag = 0;
			rectangle(x1 - 3, y1 - 3, x1 + 3, y1 + 3);			
		}
		if (flag == 0)
		{
			//���������յ�
			if (x0 > x1)
			{

				int t;
				t = x0;
				x0 = x1;
				x1 = t;
				t = y0;
				y0 = y1;
				y1 = t;
			}
			drawline(x0, y0, x1, y1, RED);
			flag = 1;
		}
	}
	

	// �ر�ͼ�δ���
	_getch();
	closegraph();	
	return 0;
}