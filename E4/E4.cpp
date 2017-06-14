///////////////////////////////////////////////////////////////////////////////////////
//�������ƣ�E4 ��άͼ�α任
//������ͼ���仯˳��1���Ŵ� 2����С 3��˳ʱ����ת 4����ʱ����ת 5������ƽ�� 6�����ֶԳ� 7������ƽ�� 8�����ִ���
//p����Ϊ�����Ƕ������꣬���ǵ��������ɶ����������ɣ����һ�������ε��������������һ��3*3�ľ��󣬹�16�������Σ�
//����һ����16������

//���뻷����Microsoft Visual Studio Ultimate 2013 EasyX_2014������
//���ߣ���۲�<1206020120>
//����޸�:2015-10-27
#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;


class Matrix{
public:
	float unit[3][3];
	Matrix(int p[6])//���������ε�3*3����
	{
		int t = 0, i, j;
		for (i = 0; i<3; i++)
		{
			for (j = 0; j<2; j++)
			{
				unit[i][j] = p[t++];
			}
			unit[i][j] = 1;
		}
	};
	Matrix(int i)//���ɶԽǾ��󣬻��������
	{
		if (i == 1)
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
				if (i == j)
					unit[i][j] = 1;
				else
					unit[i][j] = 0;
				}
		}
		else
		{
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					unit[i][j] = 0;
				}
		}
	}
	void reset()//����Ϊ�ԽǾ���
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
			if (i == j)
				unit[i][j] = 1;
			else
				unit[i][j] = 0;
			}
	}
	void set(float a, float b, int type)//type�����任���ͣ������������þ���
	{
		switch (type)
		{
			//ƽ��
			case 0:
			{
				unit[2][0] = a;
				unit[2][1] = b;
				break;
			}
				//��ת
			case 1:
			{
				unit[0][0] = cos(a / 3.14);
				unit[0][1] = sin(a / 3.14);
				unit[1][0] = -sin(a / 3.14);
				unit[1][1] = cos(a / 3.14);
				break;
			}
				//����
			case 2:
			{
				unit[0][0] = a;
				unit[1][1] = b;
				break;
			}
				//����
			case 3:
			{
				unit[1][0] = a;
				unit[0][1] = b;
				break;
			}
				//�Գ�
			case 4:
			{
				unit[0][0] = a;
				unit[1][1] = b;
			}
		}
	}
	Matrix operator *(Matrix a)//���������
	{
		int i, j, k;
		Matrix t(0);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				for (k = 0; k < 3; k++)
				{
					t.unit[i][j] += (unit[i][k] * a.unit[k][j]);
				}
				
			}
		}
		return t;
	}
};
Matrix* m;//�����ξ������飨��ʼ����main�����е��ã�

//�����Ƕ�������
int p[16][6] = { { 0, 0, 50, 10, 100, 0 }, { 0, 0, 80, 60, 50, 10 }, { 0, 0, 25, 50, 80, 60 }, { 0, 0, 0, 100, 25, 50 },
{ 0, 0, -0, 100, -25, 50 }, { 0, 0, -25, 50, -80, 60 }, { 0, 0, -80, 60, -50, 10 }, { 0, 0, -50, 10, -100, 0 },
{ 0, 0, -50, -10, -100, 0 }, { 0, 0, -80, -60, -50, -10 }, { 0, 0, -25, -50, -80, -60 }, { 0, 0, 0, -100, -25, -50 },
{ 0, 0, 0, -100, 25, -50 }, { 0, 0, 25, -50, 80, -60 }, { 0, 0, 80, -60, 50, -10 }, { 0, 0, 50, -10, 100, 0 } };

void initMatrix()//�����ξ��������ʼ������
{
	int i;
	m = (Matrix *)malloc(sizeof(Matrix) * 16);
	for (i = 0; i<16; i++)	//���������ζ������
		m[i] = Matrix(p[i]);
}

//���ݾ���r���б任
void transform(int c,int time,Matrix r)
{
	int i;
	for (int count = 1; count <= c; count++)//�任
	{
		for (i = 0; i < 16; i++)
		{
			m[i] = m[i] * r;	//����任
			//����任
			p[i][0] = m[i].unit[0][0];
			p[i][1] = m[i].unit[0][1];
			p[i][2] = m[i].unit[1][0];
			p[i][3] = m[i].unit[1][1];
			p[i][4] = m[i].unit[2][0];
			p[i][5] = m[i].unit[2][1];
		}
		cleardevice();//�����Ļ
		for (i = 0; i<16; i += 2)	//���������ǵ�ͼ��
		{
			fillpolygon((POINT*)p[i], 3);
			polygon((POINT*)p[i + 1], 3);
		}
		Sleep(time); //��ʱ
	}
}
int main()
{
	
	int i;
	initMatrix();//�����ξ��������ʼ��
	initgraph(640, 480);
	setorigin(320, 240);//����ԭ������Ϊ��Ļ����
	setbkcolor(0xFC5454);//��������Ϊ��ɫ
	cleardevice();
	setlinecolor(0x0000A8);//��������Ϊ��ɫ
	setfillcolor(0x0000A8);//�������Ϊ��ɫ

	for (i = 0; i<16; i += 2)	//���������ǵ�ͼ��
	{
		fillpolygon((POINT*)p[i], 3);
		polygon((POINT*)p[i + 1], 3);
	}
	Matrix r(1);
	//�����任
	r.set(1.01, 1.01, 2);
	transform(50, 50, r);//�Ŵ�
	r.reset();
	Sleep(500);
	r.set(0.99, 0.99, 2);//��С
	transform(50, 50, r);
	r.reset();
	Sleep(500);

	//��ת
	r.set(1, 0, 1);
	transform(25, 100, r);//˳ʱ��
	r.reset();
	Sleep(500);
	r.set(-1, 0, 1);//��ʱ��
	transform(25, 100, r);
	r.reset();
	Sleep(500);

	//ƽ��
	r.set(1.5, 1, 0);//����
	transform(100,25, r);
	r.reset();	
	Sleep(500);

	//�Գ�
	r.set(-1, 1, 4);//����y��Գ�
	transform(2, 1000, r);
	r.reset();
	Sleep(500);
	r.set(1, -1, 4);//����x��Գ�
	transform(2, 1000, r);
	r.reset();
	Sleep(500);
	r.set(-1, -1, 4);//����ԭ��Գ�
	transform(2, 1000, r);
	r.reset();
	Sleep(500);

	//ƽ��
	r.set(-1.5, -1, 0);//����
	transform(100, 25, r);
	r.reset();
	Sleep(500);

	//����
	r.set(0.05, 0, 3);
	transform(20,50, r);
	r.reset();
	Sleep(500);
	r.set(-0.05, 0, 3);
	transform(20, 50, r);
	r.reset();
	Sleep(500);
	r.set(0, 0.05, 3);
	transform(20, 50, r);
	r.reset();
	Sleep(500);
	r.set(0, -0.05, 3);
	transform(20, 50, r);

	_getch();
	closegraph();
	free(m);
	return 0;
}