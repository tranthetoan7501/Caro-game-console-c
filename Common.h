#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <conio.h>
#include <mmsystem.h>
#include <vector>
using namespace std;

class Common
{
public:
	static void fixConsoleWindow();

	static void gotoXY(int, int);

	static void setConsoleWindow(int w, int h);

public:
	Common();
	~Common();
};
