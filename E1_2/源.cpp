///////////////////////////////////////////////////////////////////////////////////////
//�������ƣ�E1_2 ����n����ȫͼһ�ʻ�
//���뻷����Microsoft Visual Studio Ultimate 2013 EasyX_2014������
//���ߣ���۲�<1206020120>
//����޸�:2015-09-22
//�ο����ף�������,����.�涥����ȫͼ��ŷ����·�������ʵ��.�˱�ѧԺѧ��,2003��6��:98-103
#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
#define R 200
#define PI 3.1415926
int gcd(int a, int b)
{
	int r;
	r = a%b;
	while (r)
	{
		a = b;
		b = r;
		r = a%b;
	}
	return b;
}
int main()
{
	int d, flag, i, j, k, p, *x, *y,n;
	float t;
	printf("���������α���:");
	scanf_s("%d", &n);	//nΪ����εı���
	x = new int[n];
	y = new int[n];
	t = 2 * PI / n;
	for (i = 0; i < n; i++)		//���ɶ�������
	{
		x[i] = R * (1.1 + cos(i * t));
		y[i] = R * (1.1 + sin(i * t));
	}
	initgraph(640, 480);	
	moveto(x[0], y[0]);
	flag = 1;
	p = 0;
	for (i = 1; i <= (n - 1) / 2; i++)
	{
		if (gcd(i, n) == 1)		//�ж�i��n�Ƿ���
		{
			if (flag == 1)
				for (j = 1; j <= n; j++)
				{
					p = (p + i) % n;
					lineto(x[p], y[p]);
				}
					
			else
				while (p)
				{
					p = (p + i) % n;
					lineto(x[p], y[p]);
				}
		}
		else
		{
			if (flag == 1)
			{
				d = gcd(n, i);
				for (j = 1; j <= d; j++)
				{
					for (k = 1; k <= n / d; k++)
					{
						p = (p + i) % n;
						lineto(x[p], y[p]);
					}
						p = (p + i + 1) % n;
						lineto(x[p], y[p]);
				}
				while (p)
				{
					p = (p + i + 1) % n;
					lineto(x[p], y[p]);
				}
				flag = 0;
			}
			else
			{
				d = gcd(n, i);
				for (j = 1; j < d; j++)
				{
					p = (p + i + 1) % n;
					lineto(x[p], y[p]);
					for (k = 1; k <= n / d; k++)
					{
						p = (p + i) % n;
						lineto(x[p], y[p]);
					}
				}
				while (p)
				{
					p = (p + i + 1) % n;
					lineto(x[p], y[p]);
				}				
			}
		}
	}
	_getch();
	closegraph();	
	delete[] x;
	delete[] y;
	return 0;
}


