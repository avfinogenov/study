#include "Circle.h"

Circle::Circle(float x_in, float y_in, int ro_in, int rs_in, float delta_in)
{
	xorbit_center = x_in;
	yorbit_center = y_in;
	Xpos = xorbit_center + ro * sin(angle);
	Ypos = yorbit_center + ro * cos(angle);
	rs = rs_in;
	delta = delta_in;
	ro = ro_in;
}

Circle::Circle(int ro_in, int rs_in, float delta_in)
{
	ro = ro_in;
	rs = rs_in;
	Xpos = xorbit_center + ro * sin(angle);
	Ypos = yorbit_center + ro * cos(angle);
	delta = delta_in;
}

void Circle::DrawCircle(HDC& hdc)
{

	for (float i = 0; i < 3.14 * 2; i += 0.05)
	{

		float xresult = Xpos + rs * sin(i);
		float yresult = Ypos + rs * cos(i);
		SetPixel(hdc, xresult, yresult, RGB(255, 255, 255));

	}


}

void Circle::DrawInsideCircle(HDC& hdc)
{

	for (float i = -(rs); i < rs; i++)
	{

		float xresult = Xpos + i * cos(angle);
		float yresult = Ypos + i * sin(angle);
		SetPixel(hdc, xresult, yresult, RGB(255, 255, 255));

	}

	for (float i = -(rs); i < rs; i++)
	{
		SetPixel(hdc, Xpos + i * cos(angle + tmp), Ypos + i * sin(angle + tmp), RGB(255, 255, 255));

	}
}

void Circle::Update()
{

	Xpos = xorbit_center + ro * sin(deltax);
	Ypos = yorbit_center + ro * cos(deltax);
	angle += delta;
	deltax += delta;
}

void Circle::PlaceCenter(Circle c_in)
{
	xorbit_center = c_in.Xpos;
	yorbit_center = c_in.Ypos;
}

