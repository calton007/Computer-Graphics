///////////////////////////////////////////////////////////////////////////////////////
//�������ƣ�E1_3 ���������β����
//���뻷����Microsoft Visual Studio Ultimate 2013 EasyX_2014������
//���ߣ���۲�<1206020120>
//����޸�:2015-09-22
#include <graphics.h>      
#include <conio.h>
int main()
{
	POINT pts1[] = { 100, 0, 128, 0, 48, 80, 150, 80, 170, 100, 0, 100, 100, 0 };
	POINT pts2[] = { 0, 100, 20, 120, 220, 120, 128, 28, 113, 43, 170, 100, 0, 100 };
	POINT pts3[] = { 76, 80, 128, 28, 220, 120, 228, 100, 128, 0, 48, 80, 76, 80 };
	initgraph(640, 480);
	setbkcolor(WHITE);		//���ñ���ɫΪ��ɫ
	cleardevice();			//����ɫˢ����Ļ
	setorigin(100, 100);	//����ԭ������
	setaspectratio(2, 2);	//������������
	setlinecolor(RED);		//�߿���ɫ���óɺ�ɫ
	setfillcolor(RED);		//�����ɫ���óɺ�ɫ	
	fillpolygon(pts1, 7);
	setfillcolor(YELLOW);	//�����ɫ���óɻ�ɫ
	fillpolygon(pts2, 7);
	setfillcolor(BLUE);		//�����ɫ���ó���ɫ
	fillpolygon(pts3, 7);
	_getch();
	closegraph();
	return 0;
}