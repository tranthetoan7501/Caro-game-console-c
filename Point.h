#pragma once
#pragma once
#include "Common.h"
class Point {
private:
	int x;
	int y;
	int check;
public:
	Point();
	Point(int, int);
	~Point();
	bool setCheck(int);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	int getCheck();

};