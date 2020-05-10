#pragma once
#include <windows.h>
#include <iostream>
#include <cmath>

class Circle
{
public:
	int ro;
	int xorbit_center = 400;
	int yorbit_center = 300;
	int Xpos, Ypos, rs;
	float angle = 0;
	Circle() = default;
	Circle(float x_in, float y_in, int ro_in, int rs_in, float delta_in);
	Circle(int ro_in, int rs_in, float delta_in);
	void DrawCircle(HDC& hdc);
	void DrawInsideCircle(HDC& hdc);
	void Update();
	float tmp = 3.14 / 2;
	void PlaceCenter(Circle c_in);
	float delta;
	float deltax = 0;
};

