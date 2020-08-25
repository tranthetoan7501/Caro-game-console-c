#pragma once
#include "Point.h"
Point::Point()
{
	x = 0;
	y = 0;
	check = 0;
}
Point::Point(int a, int b)
{
	x = a; y = b;
}
Point::~Point()
{

}
bool Point::setCheck(int n)
{
	if (n == -1 || n == 1 || n == 0)
	{
		check = n;
		return true;
	}
	return false;
}
void Point::setX(int n)
{
	x = n;
}
void Point::setY(int n)
{
	y = n;
}
int Point::getX()
{
	return x;
}
int Point::getY()
{
	return y;
}
int Point::getCheck()
{
	return check;
}