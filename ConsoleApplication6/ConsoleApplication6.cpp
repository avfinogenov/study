#include "Circle.h"
#include "Vec2.h"

Circle c[4];
Circle sattelite;
void InitCircles();
void DrawLine(HDC& hdc, Vec2 pos, int length, float angleHor, float angleDepth);
void DrawSquare(HDC& hdc);

int main()
{
	InitCircles();
	//Circle c1 = Circle(100, 30);

	//c1.Xpos = 100;
	//c1.Ypos = 100;
	//c1.r = 30;
	//c1.angle = 0.10;
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	//int x = 0;
	//for (float i = 0; i < 3.14 * 10; i += 0.05)
	//{
	//	SetPixel(hdc, x, 50 + 25 * cos(i), RGB(255, 255, 255));
	//	x += 1;
	//}

	//Circle* pc;
	//pc = &c1;



	//float delta=0;
	while (true)
	{	
		//DrawLine(hdc, Vec2(500, 50),30, 0,0);
		DrawSquare(hdc);
		for (int i = 0; i < 4; i++)
		{
			c[i].DrawCircle(hdc);
			c[i].DrawInsideCircle(hdc);
			c[i].Update();
		}
		sattelite.PlaceCenter(c[3]);
		sattelite.DrawCircle(hdc);
		sattelite.DrawInsideCircle(hdc);
		sattelite.Update();
		Sleep(1000);
		system("cls");
		//delta += 0.30;
	}



	//Sleep(1000);
	//system("cls");
	//std::cin.ignore();
	//DrawCircle(100, 100, 10, hdc);
	ReleaseDC(hwnd, hdc);
	//std::cin.ignore();
	return 0;



}


void InitCircles()
{
	c[0] = Circle(0, 50, 0.040);
	c[1] = Circle(100, 10, 0.050);
	c[2] = Circle(150, 20, 0.030);
	c[3] = Circle(250, 30, 0.020);
	sattelite = Circle(c[3].Xpos, c[3].Ypos, 50, 10, 0.1);
}

void DrawSquare(HDC& hdc)
{
	float tmp = 3.14 / 2;
	float length = 50;
	Vec2 pos = Vec2(500, 50);
	DrawLine(hdc, pos, length, 0, 0);
	DrawLine(hdc, pos, length, tmp, 0);
	pos.x += length;
	DrawLine(hdc, pos, length, tmp, 0);
	pos.x -= length;
	pos.y += length;
	DrawLine(hdc, pos, length, 0, 0);
	//DrawLine(hdc, pos, length, tmp, 0);

}

void DrawLine(HDC& hdc, Vec2 pos,int length, float angleHor, float angleDepth)
{
	
	//float xstartpos = 0;
	//float ystartpos = 0;
	//length = 10;
	//int j = 0;
	//alpha = 0;//угол к горизонтали
	float caH = cos(angleHor);
	float caD = cos(angleDepth);
	float saH = sin(angleHor);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++) {
			//float tmpI = i * caH * caD;
			//float tmpJ = j * saH * caD;
			SetPixel(hdc, pos.x + i * caH * caD, pos.y + j * saH * caD, RGB(255, 255, 255));
		}
	}
}