///////////////////////////////////////////////////////////////////////////////////////
//�������ƣ�E5 �����ͶӰ+����ͼ+�����ͶӰ��ת
//���к���ʾ����ͼ�������ͶӰ������������������������ͶӰ��ʼ��ת
//���뻷����Microsoft Visual Studio Ultimate 2013 EasyX_2014������
//���ߣ���۲�<1206020120>
//����޸�:2015-11-6

#include <graphics.h>      
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
const int MATRIX_SIZE = 4; 
class Matrix{
public:
	float unit[MATRIX_SIZE][MATRIX_SIZE];
	Matrix(int i)//���ɶԽǾ��󣬻��������
	{
		if (i == 1)
		{
			for (int i = 0; i < MATRIX_SIZE; i++)
				for (int j = 0; j < MATRIX_SIZE; j++)
				{
				if (i == j)
					unit[i][j] = 1;
				else
					unit[i][j] = 0;
				}
		}
		else
		{
			for (int i = 0; i < MATRIX_SIZE; i++)
				for (int j = 0; j < MATRIX_SIZE; j++)
				{
				unit[i][j] = 0;
				}
		}
	}
	void reset()//����Ϊ�ԽǾ���
	{
		for (int i = 0; i < MATRIX_SIZE; i++)
			for (int j = 0; j < MATRIX_SIZE; j++)
			{
			if (i == j)
				unit[i][j] = 1;
			else
				unit[i][j] = 0;
			}
	}
	Matrix operator *(Matrix a)//���������
	{
		int i, j, k;
		Matrix t(0);
		for (i = 0; i < MATRIX_SIZE; i++)
		{
			for (j = 0; j < MATRIX_SIZE; j++)
			{
				for (k = 0; k < MATRIX_SIZE; k++)
				{
					t.unit[i][j] += (unit[i][k] * a.unit[k][j]);
				}

			}
		}
		return t;
	}
};
class Point{
public:
	float p[4];
	Point(){}	
	Point(float a, float b, float c,float d)
	{
		p[0] = a ;
		p[1] = b ;
		p[2] = c ;
		p[3] = d ;
	}
	Point operator *(const Matrix &m)
	{
		int i, j;
		Point t(0,0,0,0);
		for (i = 0; i < MATRIX_SIZE; i++) 
		{
			for (j = 0; j < MATRIX_SIZE; j++)
			{
				t.p[i] += (p[j] * m.unit[j][i]);
			}
		}
		if (t.p[3] != 1) //��λ�
		{
			t.p[0] /= t.p[3];
			t.p[1] /= t.p[3];
			t.p[2] /= t.p[3];
		}
		return t;
	}
};
//����ͼ��
void draw(const Point point[], const int edge[][2])
{
	for (int i = 0; i < 27; i++)
		line(point[edge[i][0] - 1].p[0], point[edge[i][0] - 1].p[2], point[edge[i][1] - 1].p[0], point[edge[i][1] - 1].p[2]);
}
Point point[19] = { Point(0, 0, 42, 1), Point(55, 0, 42, 1), Point(55, 0, 10, 1), Point(70, 0, 10, 1), 
Point(70, 0, 0, 1), Point(70, 40, 0, 1), Point(0, 40, 0, 1), Point(0, 40, 27, 1), Point(0, 30, 27, 1), 
Point(0, 30, 42, 1), Point(10, 30, 42, 1), Point(10, 10, 42, 1), Point(55, 10, 42, 1), Point(55, 10, 10, 1), 
Point(30, 10, 10, 1), Point(30, 40, 10, 1), Point(20, 40, 27, 1), Point(20, 30, 27, 1), Point(70, 40, 10, 1) };
int edge[27][2] = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 5, 6 }, { 6, 7 }, { 7, 8 },
{ 8, 9 }, { 9, 10 }, { 10, 11 }, { 11, 12 }, { 12, 13 }, { 13, 14 }, { 14, 15 },
{ 15, 16 }, { 16, 17 }, { 17, 18 }, { 1, 10 }, { 2, 13 }, { 3, 14 }, { 4, 19 },
{ 6, 19 }, { 8, 17 }, { 9, 18 }, { 11, 18 }, { 12, 15 }, { 16, 19 } };

//�����ͶӰ
void projection()
{
	Point temp[19];
	for (int i = 0; i < 19; i++)
	{
		temp[i] = point[i];
	}
	Matrix m(1),t(1);
	//��z����ת
	m.unit[0][0] = 0.707;
	m.unit[0][1] = 0.707;
	m.unit[1][0] = -0.707;
	m.unit[1][1] = 0.707;
	//��x����ת
	t.unit[1][1] = 0.816;
	t.unit[1][2] = -0.577;
	t.unit[2][1] = 0.577;
	t.unit[2][2] = 0.816;
	m = m*t;
	t.reset();
	//ͶӰ��XOZƽ��
	t.unit[1][1] = 0;
	m = m*t;
	t.reset();

	//ƽ��
	t.unit[3][2] = -50;
	t.unit[3][0] = -70;
	m = m*t;
	t.reset();

	//�Ŵ�
	t.unit[0][0] = 2;
	t.unit[1][1] = 2;
	t.unit[2][2] = 2;
	m = m*t;
	t.reset();

	//��ת180��
	t.unit[0][0] = t.unit[2][2] = -1;
	m = m*t;	

	for (int i = 0; i < 19; i++)
		temp[i] = temp[i] * m;
	draw(temp, edge);
}
void front()
{
	Point temp[19];
	for (int i = 0; i < 19; i++)
	{
		temp[i] = point[i];
	}
	Matrix m(1),t(1);

	//ͶӰ��XOZƽ��
	t.unit[1][1] = 0;
	m = m*t;
	t.reset();

	//�Ŵ�
	t.unit[0][0] = 3;
	t.unit[1][1] = 3;
	t.unit[2][2] = 3;
	m = m*t;
	t.reset();

	//��ת180��
	t.unit[0][0] = t.unit[2][2] = -1;
	m = m*t;

	for (int i = 0; i < 19; i++)
		temp[i] = temp[i] * m;
	draw(temp, edge);
}
void vertical()
{
	Matrix m(1), t(1);
	Point temp[19];
	for (int i = 0; i < 19; i++)
	{
		temp[i] = point[i];
	}
	
	//ͶӰ��XOYƽ��
	t.unit[2][2] = 0;
	m = m*t;
	t.reset();

	//��X�Ḻ����ת90��
	t.unit[1][1] = 0;
	t.unit[1][2] = -1;
	t.unit[2][1] = 1;
	t.unit[2][2] = 0;
	m = m*t;
	t.reset();

	//ƽ��
	t.unit[3][2] = -10;
	m = m*t;

	//�Ŵ�
	t.unit[0][0] = 3;
	t.unit[1][1] = 3;
	t.unit[2][2] = 3;
	m = m*t;
	t.reset();

	//��ת180��
	t.unit[0][0] = t.unit[2][2] = -1;
	m = m*t;

	for (int i = 0; i < 19; i++)
		temp[i] = temp[i] * m;
	draw(temp, edge);
}
void side()
{
	Matrix m(1), t(1);
	Point temp[19];
	for (int i = 0; i < 19; i++)
	{
		temp[i] = point[i];
	}
	//ͶӰ��YOZƽ��
	t.unit[0][0] = 0;
	m = m*t;
	t.reset();

	//��Z��������ת90��
	t.unit[0][0] = 0;
	t.unit[0][1] = 1;
	t.unit[1][0] = -1;
	t.unit[1][1] = 0;
	m = m*t;
	t.reset();
	
	//ƽ��
	t.unit[3][0] = -10;
	m = m*t;

	//�Ŵ�
	t.unit[0][0] = 3;
	t.unit[1][1] = 3;
	t.unit[2][2] = 3;
	m = m*t;
	t.reset();

	//��ת180��
	t.unit[0][0] = t.unit[2][2] = -1;
	m = m*t;

	for (int i = 0; i < 19; i++)
		temp[i] = temp[i] * m;
	draw(temp, edge);
}
void rotate()
{
	Point temp[19],temp2[19];
	for (int i = 0; i < 19; i++)
	{
		temp[i] = point[i];
	}
	for (int i = 0; i < 19; i++)
	{
		temp2[i] = point[i];
	}
	Matrix m(1), t(1);

	//��z����ת
	m.unit[0][0] = 0.707;
	m.unit[0][1] = 0.707;
	m.unit[1][0] = -0.707;
	m.unit[1][1] = 0.707;

	//��x����ת
	t.unit[1][1] = 0.816;
	t.unit[1][2] = -0.577;
	t.unit[2][1] = 0.577;
	t.unit[2][2] = 0.816;
	m = m*t;
	t.reset();

	//ͶӰ��XOZƽ��
	t.unit[1][1] = 0;
	m = m*t;
	t.reset();

	//�Ŵ�
	t.unit[0][0] = 2;
	t.unit[1][1] = 2;
	t.unit[2][2] = 2;
	m = m*t;
	t.reset();

	//��ת180��
	t.unit[0][0] = t.unit[2][2] = -1;
	m = m*t;

	Matrix r(1);
	r.unit[0][1] = cos(0.03);
	r.unit[0][1] = sin(0.03);
	r.unit[1][0] = -sin(0.03);
	r.unit[1][1] = cos(0.03);
	//mΪ�����ͶӰ�任����rΪ��ת����
	while (1)
	{
		cleardevice();
		for (int i = 0; i < 19; i++)
			temp[i] = temp[i] * r;	//ԭʼͼ����ת
		for (int i = 0; i < 19; i++)
			temp2[i] = temp[i] * m ; //�������ͶӰ
		draw(temp2, edge);
		Sleep(50);
	}		
}

int main()
{
	initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);
	setorigin(320, 240);//����ԭ������Ϊ��Ļ����
	projection();//�����ͶӰ
	front();//����ͼ
	vertical();//����ͼ
	side();//����ͼ
	_getch();

	rotate();//�����ͶӰ��ת

	_getch();
	closegraph();
	system("pause");
	return 0;
}