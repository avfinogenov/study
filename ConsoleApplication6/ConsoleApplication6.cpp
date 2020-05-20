#include "Circle.h"
#include "Vec2.h"
#include <algorithm>
#include <conio.h>

using namespace std;

int Sum(int* p, int w);
void Reverse(int* p, int size);
void Print(char* p);
void read(char* buff, int size);
int Str2int(char* s);
int fibon(int n);
void int2str(int n, char* buff, int size);
int main()
{
	









	Sleep(100000);













	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	
	

	



	//Sleep(1000);
	//system("cls");
	//std::cin.ignore();
	//DrawCircle(100, 100, 10, hdc);
	ReleaseDC(hwnd, hdc);
	//std::cin.ignore();
	return 0;



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