﻿#include "Circle.h"
#include "Vec2.h"

#include <conio.h>
#include <fstream>

using namespace std;

class Test
{public:
	char name[100] = { 0 };
	int number;
};
int Sum(int* p, int w);
void Reverse(int* p, int size);
void Print(const char* p);
void read(char* buff, int size);
int Str2int(char* s);
int fibon(int n);
void int2str(int n, char* buff, int size);

void LoadF(const char* pc, Test* t_in, int size);
void SetName(Test* pt, char* buff_in, int size, int number);
int main()
{
	Test t[100];
	char msg[] = "(l)oad (s)ave (a)dd (q)uit or (p)rint";
	char buff[100] = { 0 };
	char menuswitch = 0;
	//read(buff, 100);
	
	int count = 0;
	do
	
	{
		Print("(l)oad (s)ave (a)dd (q)uit or (p)rint");
		switch (menuswitch=_getch())
		{
		case 'l':
		{
			Print("\nEnter file name: ");
			read(buff, 100);
			//LoadF(buff);
			break;
		}
		case 's':
		{
			break;
		}
		case 'a':
		{
			Print("enter name: ");
			read(buff, 100);
			SetName(t, buff, 100, count);
			Print("enter number: ");
			read(buff, 100);
			t[count].number = Str2int(buff);
			count++;
			break;
		}
		case 'q':
		{
			Print("Programm is closing");
			break;
		}
		case 'p':
		{
			break;
		}
		default:
			break;
		}
	} while (menuswitch != 'q');





	Print(t[0].name);
	
	std::cin.ignore();
	return 0;



}

void SetName(Test* pt, char* buff_in, int size, int number)
{
	pt = pt + number;
	char* e = buff_in + size;
	char* tmp = (pt->name);
	for (; (buff_in < e)&&(*buff_in!=0); buff_in++, tmp++)
	{
		*tmp = *buff_in;
	}
	*tmp = 0;
}
void LoadF(const char* pc, Test* t_in, int size)
{
	ifstream inFile(pc);
	if (!inFile)
	{
		Print("error");
	}
	else
	{
		Test* tmp = t_in + size;
		for (; (t_in < tmp)&&(!inFile.eof()); t_in++)
		{
			inFile.read((char*)t_in, sizeof(Test));
		}
	}
}
void SaveF(const char* pc, Test* t_in, int size)
{
	ofstream inFile(pc);
	if (!inFile)
	{
		Print("error");
	}
	else
	{
		Test* tmp = t_in + size;
	//	for (; (t_in < tmp) && ; t_in++)
	//	{
	//		inFile.write((char*)t_in, sizeof(Test));
	//	}
	}
}



void Print(const char* p)
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