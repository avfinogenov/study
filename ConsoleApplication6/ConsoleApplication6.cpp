#include "Circle.h"
#include "Vec2.h"
#include <algorithm>
#include <conio.h>

using namespace std;
Circle c[4];
Circle sattelite;
void InitCircles();
//void DrawLine(HDC& hdc, Vec2 pos, int length, float angleHor, float angleDepth, int abs);
//void DrawSquare(HDC& hdc, Vec2 pos, int length, float angleHor, float angleD, int abs);
//void RotateSquare(HDC& hdc, Vec2 pos, int length, float angleHor, float angleD, int abs);
void DrawLine(HDC& hdc, Vec2 startpos, Vec2 endpos);
float FindMax(float x1, float x2);
float FindMin(float x1, float x2);
float GetLength(float x1, float x2);
Vec2 RotateV(Vec2 startpos, float radius, float angle);
void DrawSquare(HDC& hdc);
int Sum(int* p, int w);
void Reverse(int* p, int size);
void Print(char* p);
void read(char* buff, int size);
int Str2int(char* s);
int fibon(int n);
void int2str(int n, char* buff, int size);
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	InitCircles();
	//Circle c1 = Circle(100, 30);
	
	int* p;
	int x = 10;
	p = &x;
	(*p)--;
	std::cout << *p;
	std::cout << std::endl;

	Circle* pc;
	pc = &c[1];
	pc->ro = 10;
	std::cout << pc->ro;


	_getch();
	_putch('s');


	char msg[] = "somethig to print!";
	Print(msg);
	char cbuf[69];
	read(cbuf, 69);
	Print(cbuf);
	int tmp = Str2int(cbuf);
	cout << tmp << endl;

	cout << endl;
	cout << "vvedite chislo fibbonachi";
	read(cbuf, 69);
	tmp = Str2int(cbuf);
	tmp = fibon(tmp);
	char cbuf2[69];
	int2str(tmp, cbuf2, 69);
	Print(cbuf2);
	//cout << fibon(tmp);









	Sleep(100000);














	//c1.Xpos = 100;
	//c1.Ypos = 100;
	//c1.r = 30;
	//c1.angle = 0.10;
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	std::cout << Sum(arr, sizeof(arr));
	Reverse(arr, 10);
	//int  tmp = 0;
	//int x = 0;
	//for (float i = 0; i < 3.14 * 10; i += 0.05)
	//{
	//	SetPixel(hdc, x, 50 + 25 * cos(i), RGB(255, 255, 255));
	//	x += 1;
	//}

	//Circle* pc;
	//pc = &c1;

	Vec2 startpos = Vec2(150, 150);
	float r = 50;
	float alpha = 0;
	//float delta=0;
	while (true)
	{
		//DrawLine(hdc, startpos, RotateV(startpos,r,alpha));
		//DrawLine(hdc, Vec2(500, 50),30, 0,0);
		//DrawSquare(hdc);
		//DrawSquare(hdc);
		
		//RotateSquare(hdc, Vec2(500, 50), 30, 0,alpha, 50);
		alpha += 0.1;
		
			//for (int i = 0; i < 4; i++)
			//{
			//	c[i].DrawCircle(hdc);
			//	c[i].DrawInsideCircle(hdc);
			//	c[i].Update();
			//}
			//sattelite.PlaceCenter(c[3]);
			//sattelite.DrawCircle(hdc);
			//sattelite.DrawInsideCircle(hdc);
			//sattelite.Update();
		Sleep(100);
		//system("cls");
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


/*
void DrawLine(HDC& hdc, Vec2 pos,int length, float angleHor, float angleDepth, int abs)
{
	
	//float xstartpos = 0;
	//float ystartpos = 0;
	//length = 10;
	//int j = 0;
	//alpha = 0;//угол к горизонтали
	float caH = cos(angleHor);
	float caD = cos(angleDepth);
	float saH = sin(angleHor);
	if (length > 0)
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < abs; j++) {
				//float tmpI = i * caH * caD;
				//float tmpJ = j * saH * caD;
				SetPixel(hdc, pos.x + i * caH * caD, pos.y + j * saH, RGB(255, 255, 255));
			}
		}
	}
	else
	{
		for (int i = 0; i > -length; i--)
		{
			for (int j = 0; j < abs; j++) {
				//float tmpI = i * caH * caD;
				//float tmpJ = j * saH * caD;
				SetPixel(hdc, pos.x + i * caH * caD, pos.y + j * saH, RGB(255, 255, 255));
			}
		}
	}
}
void DrawSquare(HDC& hdc, Vec2 pos, int length, float angleHor, float angleD, int abs)
{
	float tmp = 3.14 / 2;
	//float length = 50;
	//Vec2 pos = Vec2(500, 50);
	DrawLine(hdc, pos, length, angleHor, angleD, abs);
	DrawLine(hdc, pos, length, angleHor+tmp, angleD, abs);
	pos.x += length;
	DrawLine(hdc, pos, length, angleHor+tmp, angleD, abs);
	pos.x -= length;
	pos.y += length;
	DrawLine(hdc, pos, length, angleHor, angleD, abs);
	//DrawLine(hdc, pos, length, tmp, 0);

}
void RotateSquare(HDC& hdc, Vec2 pos, int length,float angleHor, float angleD, int abs)
{
	//angleHor +=0.01;
	angleD += 0.1;
	float tmplength = length * cos(angleD);
	DrawSquare(hdc, pos, tmplength, angleHor, angleD, abs);

}
*/

void DrawLine(HDC& hdc,Vec2 startpos, Vec2 endpos)
{
	float lx = GetLength(endpos.x, startpos.x);
	float ly = GetLength(endpos.y, startpos.x);
	float length = FindMax(lx, ly);
	int signx = (endpos.x - startpos.x) / abs(endpos.x - startpos.x);
	int signy = (endpos.y - startpos.y) / abs(endpos.y - startpos.y);
	if (lx > ly)
	{

		float yi = ly / lx;
		for (int i = 0; i < length; i++)
		{
			SetPixel(hdc, startpos.x + i * signx, startpos.y + i * yi * signy, RGB(255, 255, 255));
		}
	}
	else
	{
		float xi = lx / ly;
		for (int i = 0; i < length; i++)
		{
			SetPixel(hdc, startpos.x + i * xi * signx, startpos.y + i * signy, RGB(255, 255, 255));
		}
	}

	
	
	
}
Vec2 RotateV(Vec2 startpos, float radius, float angle)
{
	Vec2 endpos;
	float tmp = 3.14 / 2;
	endpos.x = startpos.x + radius * cos(angle);
	endpos.y = startpos.y + radius * cos(tmp+angle);
	return endpos;
	//центр, радиус орбиты
	

}
void DrawSquare(HDC& hdc)
{
	Vec2 a[2][2];
	a[0][0] = Vec2(50, 50);
	a[0][1] = Vec2(50, 100);
	a[1][0] = Vec2(100, 50);
	a[1][1] = Vec2(100, 100);
	DrawLine(hdc, a[0][0], a[0][1]);
	DrawLine(hdc, a[0][0], a[1][0]);
	DrawLine(hdc, a[1][0], a[1][1]);
	DrawLine(hdc, a[0][1], a[1][1]);
}
float FindMax(float x1, float x2)
{
	if (x1 > x2)
	{
		return x1;

	}
	else
	{
		return x2;
	}
}
float FindMin(float x1, float x2)
{
	if (x1 < x2)
	{
		return x1;

	}
	else
	{
		return x2;
	}
}
float GetLength(float x1, float x2)
{
	return abs(x2 - x1);
}



void Print(char* p)
{
	for (; *p != 0; p++)
	{
		_putch(*p);
	}
}

void read(char* buff, int size)
{
	char* bufend = buff + size - 1;
	for (char c=_getch(); (buff < bufend) && (c!=13); c=_getch(), buff++)
	{
		_putch(c);
		*buff = c;
		//buff++;
	}
	*buff = 0;

}
int Str2int(char* s)
{
	char* p = s;
	for (; (*p >= 48 && *p <= 57) && (*p != 0); p++);
	p--;
	int val = 0;
	int place = 1;
	for (; p >= s; p--)
	{
		val += (*p - '0') * place;
		place *= 10;
	}
	return val;
}
void int2str(int n, char* buff, int size)
{
	char val[69];
	val[68] = 0;
	int tmp = 67;
	int count = 0;
	while (n != 0 && tmp>0)
	{
		val[tmp] = n % 10 + 48;
		n /= 10;
		tmp--;
		count++;
	}
	char* bufend =buff+count;
	for (; (buff < bufend); buff++)
	{
		
		*buff =val[tmp+1];
		tmp++;
		//buff++;
	}
	*buff = 0;
	
}

int fibon(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
		if (n == 2)
		{
			return 1;
		}else

			{
				return fibon(n - 1) + fibon(n - 2);
			}
}

int Sum(int* p, int w)
{
	int s = 0;
	w = w / 4;
	int* e = p+w;
	//int tmp = sizeof(p);
	for (; p <e; p++)
	{
		s +=*p;
	}
	return s;
}
void Reverse(int* p, int size)
{
	int tmp;
	int* e = p + size;
	for (; p <  e;p++)
	{
		e--;
		tmp = *p;
		*p =*e ;
		*e = tmp;
		
	}
}