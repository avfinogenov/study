#include "Circle.h"


Circle c[4];
Circle sattelite;
void InitCircles();

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
		Sleep(100);
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