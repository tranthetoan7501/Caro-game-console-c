#include "Play.h"
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
#include <iostream>
using namespace std;
struct Name {
	char data[30];
};
vector <Name> ch;

int ReadChedo(char a[30])
{
	int d1, d2, chedo;
	system("cls");
	ifstream f;
	f.open(a, ios::in);
	if (!f) {
		Common::gotoXY(80, 46);
		cout << "\n FILE KHONG TON TAI!" << endl;
		Sleep(1000);
		ScreenStartGame(99);
	}
	else
		f >> d1 >> d2 >> chedo;
	f.close();
	return chedo;
}

void ReadNameFile()
{
	TextColor(Cyan);
	Common::gotoXY(90, 28);
	cout << "LIST FILE NAME";
	int i = 19;
	ifstream f;
	f.open("Name.txt", ios::in);
	while (!f.eof())
	{
		char s[30];
		f >> s;
		Common::gotoXY(90, i+10);
		cout << s;
		i++;
	}
	f.close();
}

void LogoGame1()
{

	srand(time(0));
	int x = 22, y = 5;
	TextColor(4);
	Common::gotoXY(x + 4, y + 4);       cout << "x           x";
	Common::gotoXY(x + 2, y + 5);     cout << "xxxxx       xxxxx";
	Common::gotoXY(x, y + 6);     cout << "xxxxxxxxx   xxxxxxxxx";
	Common::gotoXY(x + 2, y + 7);     cout << "xxxxxxxxxxxxxxxxx";
	Common::gotoXY(x + 4, y + 8);      cout << "xxxxxxxxxxxxx";
	Common::gotoXY(x + 6, y + 9);        cout << "xxxxxxxxx";
	Common::gotoXY(x + 4, y + 10);      cout << "xxxxxxxxxxxxx";
	Common::gotoXY(x + 2, y + 11);    cout << "xxxxxxxxxxxxxxxxx";
	Common::gotoXY(x, y + 12);    cout << "xxxxxxxxx   xxxxxxxxx";
	Common::gotoXY(x + 2, y + 13);   cout << "xxxxx       xxxxx";
	Common::gotoXY(x + 4, y + 14);      cout << "x           x";


	int z = 43;
	TextColor(rand() % 15 + 1);
	Common::gotoXY(x + z, y + 4);			    cout << "ooooooooooo";
	Common::gotoXY(x + z - 2, y + 5);		  cout << "ooooooooooooooo";
	Common::gotoXY(x + z - 3, y + 6);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z - 3, y + 7);		 cout << "oooooooo  ooooooo";
	Common::gotoXY(x + z - 3, y + 8);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 3, y + 9);		 cout << "oooooo     ";
	Common::gotoXY(x + z - 3, y + 10);		 cout << "oooooo     ";
	Common::gotoXY(x + z - 3, y + 11);		 cout << "oooooo    ";
	Common::gotoXY(x + z - 3, y + 12);		 cout << "oooooooo  ooooooo";
	Common::gotoXY(x + z - 3, y + 13);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z - 2, y + 14);		  cout << "ooooooooooooooo";
	Common::gotoXY(x + z, y + 15);				cout << "ooooooooooo";



	TextColor(rand() % 15 + 1);
	Common::gotoXY(x + z - 3 + 22, y + 4);					 cout << "ooooooooo";
	Common::gotoXY(x + z - 4 + 22 - 2, y + 5);		  cout << "ooooooooooooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 6);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 7);	     cout << "ooooooooooooooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 8);	     cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 9);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 10);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 11);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 12);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 13);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 14);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 15);		 cout << "oooooo     oooooo";
	TextColor(rand() % 15 + 1);
	Common::gotoXY(x + z + 33, y + 4);			 cout << "ooooo   ooooooooo";
	Common::gotoXY(x + z + 33, y + 5);			 cout << "oooooooooooooooooo";
	Common::gotoXY(x + z + 33, y + 6);			 cout << "ooooooooooooooooooo";
	Common::gotoXY(x + z + 33, y + 7);			 cout << "oooooooooooooooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 8);		 cout << "ooooooo     ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 9);		 cout << "ooooooo     ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 10);		 cout << "ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 11);		 cout << "ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 12);		 cout << "ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 13);		 cout << "ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 14);		 cout << "ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 15);		 cout << "ooooooo";
	TextColor(rand() % 15 + 1);
	Common::gotoXY(x + z + 57, y + 4);			    cout << "ooooooooooo";
	Common::gotoXY(x + z + 57 - 2, y + 5);	      cout << "ooooooooooooooo";
	Common::gotoXY(x + z + 57 - 3, y + 6);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z + 57 - 3, y + 7);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z + 57 - 3, y + 8);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z + 57 - 3, y + 9);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z + 57 - 3, y + 10);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z + 57 - 3, y + 11);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z + 57 - 3, y + 12);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z + 57 - 3, y + 13);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z + 57 - 2, y + 14);		  cout << "ooooooooooooooo";
	Common::gotoXY(x + z + 57, y + 15);				cout << "ooooooooooo";



	TextColor(7);
	Common::gotoXY(x + 134, y + 4);         cout << "x x x x x x x";
	Common::gotoXY(x + 132, y + 5);       cout << "x x x x x x x x x";
	Common::gotoXY(x + 130, y + 6);       cout << "x x xx         xx x x";
	Common::gotoXY(x + 130, y + 7);     cout << "x x x           x x x";
	Common::gotoXY(x + 130, y + 8);     cout << "x x x           x x x";
	Common::gotoXY(x + 130, y + 9);     cout << "x x x           x x x";
	Common::gotoXY(x + 130, y + 10);    cout << "x x x           x x x";
	Common::gotoXY(x + 130, y + 11);    cout << "x x x           x x x";
	Common::gotoXY(x + 130, y + 12);      cout << "x x xx         xx x x";
	Common::gotoXY(x + 132, y + 13);      cout << "x x x x x x x x x";
	Common::gotoXY(x + 134, y + 14);        cout << "x x x x x x x";

}

void LogoGame2()
{
	int x = 22, y = 5;
	TextColor(4);
	Common::gotoXY(x + 4, y + 4);       cout << "x           x";
	Common::gotoXY(x + 2, y + 5);     cout << "x x x       x x x";
	Common::gotoXY(x, y + 6);     cout << "x x x x x   x x x x x";
	Common::gotoXY(x + 2, y + 7);     cout << "x x x x x x x x x";
	Common::gotoXY(x + 4, y + 8);      cout << "x x x x x x x";
	Common::gotoXY(x + 6, y + 9);        cout << "x x x x x";
	Common::gotoXY(x + 4, y + 10);      cout << "x x x x x x x";
	Common::gotoXY(x + 2, y + 11);    cout << "x x x x x x x x x";
	Common::gotoXY(x, y + 12);    cout << "x x x x x   x x x x x";
	Common::gotoXY(x + 2, y + 13);   cout << "x x x       x x x";
	Common::gotoXY(x + 4, y + 14);      cout << "x           x";

	Sleep(200);
	int z = 43;

	TextColor(6);
	Common::gotoXY(x + z, y + 4);			    cout << "ooooooooooo";
	Common::gotoXY(x + z - 2, y + 5);		  cout << "ooooooooooooooo";
	Common::gotoXY(x + z - 3, y + 6);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z - 3, y + 7);		 cout << "oooooooo  ooooooo";
	Common::gotoXY(x + z - 3, y + 8);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 3, y + 9);		 cout << "oooooo     ";
	Common::gotoXY(x + z - 3, y + 10);		 cout << "oooooo     ";
	Common::gotoXY(x + z - 3, y + 11);		 cout << "oooooo    ";
	Common::gotoXY(x + z - 3, y + 12);		 cout << "oooooooo  ooooooo";
	Common::gotoXY(x + z - 3, y + 13);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z - 2, y + 14);		  cout << "ooooooooooooooo";
	Common::gotoXY(x + z, y + 15);				cout << "ooooooooooo";


	Sleep(200);
	TextColor(9);
	Common::gotoXY(x + z - 3 + 22, y + 4);				 cout << "ooooooooo";
	Common::gotoXY(x + z - 4 + 22 - 2, y + 5);		  cout << "ooooooooooooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 6);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 7);	     cout << "ooooooooooooooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 8);	     cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 9);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 10);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 11);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 12);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 13);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 14);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z - 4 + 22 - 3, y + 15);		 cout << "oooooo     oooooo";
	Sleep(200);
	TextColor(4);
	Common::gotoXY(x + z + 33, y + 4);			 cout << "ooooo   ooooooooo";
	Common::gotoXY(x + z + 33, y + 5);			 cout << "oooooooooooooooooo";
	Common::gotoXY(x + z + 33, y + 6);			 cout << "ooooooooooooooooooo";
	Common::gotoXY(x + z + 33, y + 7);			 cout << "oooooooooooooooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 8);		 cout << "ooooooo     ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 9);		 cout << "ooooooo     ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 10);		 cout << "ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 11);		 cout << "ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 12);		 cout << "ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 13);		 cout << "ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 14);		 cout << "ooooooo";
	Common::gotoXY(x + z + 1 + 33, y + 15);		 cout << "ooooooo";
	Sleep(200);
	TextColor(10);
	Common::gotoXY(x + z + 57, y + 4);			    cout << "ooooooooooo";
	Common::gotoXY(x + z + 57 - 2, y + 5);	      cout << "ooooooooooooooo";
	Common::gotoXY(x + z + 57 - 3, y + 6);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z + 57 - 3, y + 7);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z + 57 - 3, y + 8);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z + 57 - 3, y + 9);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z + 57 - 3, y + 10);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z + 57 - 3, y + 11);		 cout << "oooooo     oooooo";
	Common::gotoXY(x + z + 57 - 3, y + 12);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z + 57 - 3, y + 13);		 cout << "ooooooooooooooooo";
	Common::gotoXY(x + z + 57 - 2, y + 14);		  cout << "ooooooooooooooo";
	Common::gotoXY(x + z + 57, y + 15);				cout << "ooooooooooo";



	TextColor(7);
	Common::gotoXY(x + 134, y + 4);         cout << "x x x x x x x";
	Common::gotoXY(x + 132, y + 5);       cout << "x x x x x x x x x";
	Common::gotoXY(x + 130, y + 6);     cout << "x x xx         xx x x";
	Common::gotoXY(x + 130, y + 7);     cout << "x x x           x x x";
	Common::gotoXY(x + 130, y + 8);     cout << "x x x           x x x";
	Common::gotoXY(x + 130, y + 9);     cout << "x x x           x x x";
	Common::gotoXY(x + 130, y + 10);    cout << "x x x           x x x";
	Common::gotoXY(x + 130, y + 11);    cout << "x x x           x x x";
	Common::gotoXY(x + 130, y + 12);    cout << "x x xx         xx x x";
	Common::gotoXY(x + 132, y + 13);      cout << "x x x x x x x x x";
	Common::gotoXY(x + 134, y + 14);        cout << "x x x x x x x";

}

void PrintP1Win()
{
	AnTroChuot();
	int check = 1;
	int x = 50, y = 18;
	while (check < 30)
	{
		TextColor(rand() % 15 + 1);
		Common::gotoXY(x + 4, y + 4); cout << "xxxxxxxxxxxxxx             xxxxxxxxx                                                xxxx";
		Common::gotoXY(x + 4, y + 5); cout << "xxxxxx   xxxxxx          xxxxxxxxxxx                                                xxxx";
		Common::gotoXY(x + 4, y + 6); cout << "xxxxx     xxxxxx        xxxxx   xxxx";
		Common::gotoXY(x + 4, y + 7); cout << "xxxxx     xxxxxx       xxxxx    xxxx";
		Common::gotoXY(x + 4, y + 8); cout << "xxxxxx   xxxxxx       xxxxx     xxxx          xxxx                            xxxx  xxxx   xxxxxxxxxxxxxxxx";
		Common::gotoXY(x + 4, y + 9); cout << "xxxxxxxxxxxxxx                  xxxx           xxxx                          xxxx   xxxx   xxxxxxxxxxxxxxxx";
		Common::gotoXY(x + 4, y + 10); cout << "xxxx                            xxxx            xxxx         xxxxxxx        xxxx    xxxx   xxxx        xxxx";
		Common::gotoXY(x + 4, y + 11); cout << "xxxx                            xxxx             xxxx      xxxx  xxxx      xxxx     xxxx   xxxx        xxxx";
		Common::gotoXY(x + 4, y + 12); cout << "xxxx                            xxxx              xxxx   xxxx     xxxx    xxxx      xxxx   xxxx        xxxx";
		Common::gotoXY(x + 4, y + 13); cout << "xxxx                            xxxx               xxxx xxxx        xxxx xxxx       xxxx   xxxx        xxxx";
		Common::gotoXY(x + 4, y + 14); cout << "xxxx                            xxxx                xxxxxxx          xxxxxxx        xxxx   xxxx        xxxx";
		Sleep(200);
		check++;
	}
}

void PrintP2Win()
{
	AnTroChuot();
	int check = 1;
	int x = 50, y = 18;
	while (check < 30)
	{
		TextColor(rand() % 15 + 1);
		Common::gotoXY(x + 4, y + 4); cout << "xxxxxxxxxxxxxx       xxxxxxxxxxxxx                                                xxxx";
		Common::gotoXY(x + 4, y + 5); cout << "xxxxxx   xxxxxx      xxxxxxxxxxxxx                                                xxxx";
		Common::gotoXY(x + 4, y + 6); cout << "xxxxx     xxxxxx     xxxx     xxxx";
		Common::gotoXY(x + 4, y + 7); cout << "xxxxx     xxxxxx     xxxx     xxxx";
		Common::gotoXY(x + 4, y + 8); cout << "xxxxxx   xxxxxx               xxxx          xxxx                            xxxx  xxxx   xxxxxxxxxxxxxxxx";
		Common::gotoXY(x + 4, y + 9); cout << "xxxxxxxxxxxxxx       xxxxxxxxxxxxx           xxxx                          xxxx   xxxx   xxxxxxxxxxxxxxxx";
		Common::gotoXY(x + 4, y + 10); cout << "xxxx                 xxxxxxxxxxxxx            xxxx         xxxxxxx        xxxx    xxxx   xxxx        xxxx";
		Common::gotoXY(x + 4, y + 11); cout << "xxxx                 xxxx                      xxxx      xxxx  xxxx      xxxx     xxxx   xxxx        xxxx";
		Common::gotoXY(x + 4, y + 12); cout << "xxxx                 xxxx                       xxxx   xxxx     xxxx    xxxx      xxxx   xxxx        xxxx";
		Common::gotoXY(x + 4, y + 13); cout << "xxxx                 xxxxxxxxxxxxx               xxxx xxxx        xxxx xxxx       xxxx   xxxx        xxxx";
		Common::gotoXY(x + 4, y + 14); cout << "xxxx                 xxxxxxxxxxxxx                xxxxxxx          xxxxxxx        xxxx   xxxx        xxxx";
		Sleep(200);
		check++;
	}
}

void PrintDraw()
{
	AnTroChuot();
	int check = 1;
	int x = 50, y = 18;
	while (check < 30)
	{
		TextColor(rand() % 15 + 1);
		Common::gotoXY(x + 4, y + 4); cout <<  "xxxxxxxxxxxxxx";
		Common::gotoXY(x + 4, y + 5); cout <<  "xxxxx    xxxxxx";
		Common::gotoXY(x + 4, y + 6); cout <<  "xxxxx     xxxxxx";
		Common::gotoXY(x + 4, y + 7); cout <<  "xxxxx      xxxxxx";
		Common::gotoXY(x + 4, y + 8); cout <<  "xxxxx       xxxxxx   xxxxxxxxxxxxx    xxxxxxxxxxxxx        xxxx                            xxxx";
		Common::gotoXY(x + 4, y + 9); cout <<  "xxxxx       xxxxxx   xxxxxxxxxxxxx    xxxxxxxxxxxxx         xxxx                          xxxx";
		Common::gotoXY(x + 4, y + 10); cout << "xxxxx       xxxxxx   xxxx             xxxx     xxxx          xxxx         xxxxxxx        xxxx";
		Common::gotoXY(x + 4, y + 11); cout << "xxxxx      xxxxxx    xxxx             xxxx     xxxx           xxxx      xxxx  xxxx      xxxx";
		Common::gotoXY(x + 4, y + 12); cout << "xxxxx     xxxxxx     xxxx             xxxx     xxxx            xxxx   xxxx     xxxx    xxxx";
		Common::gotoXY(x + 4, y + 13); cout << "xxxxx    xxxxxx      xxxx             xxxxxxxxxxxxxxxxx         xxxx xxxx        xxxx xxxx";
		Common::gotoXY(x + 4, y + 14); cout << "xxxxxxxxxxxxxx       xxxx             xxxxxxxxxxxxxxxxx          xxxxxxx          xxxxxxx";
		
		Sleep(200);
		check++;
	}
}

void TaoKhung(int bottom)
{
	char lr = 186;
	char tb = 205;
	Common::gotoXY(4, 5);
	for (int i = 0; i < 193; i++)
	{
		cout << tb;
	}
	Common::gotoXY(4, 6);
	for (int i = 0; i < 193; i++)
	{
		cout << tb;
	}
	for (int i = 5; i < 50; i++)
	{
		Common::gotoXY(4, i);
		cout << lr << lr;
		Common::gotoXY(195, i);
		cout << lr << lr;

	}
	Common::gotoXY(4, bottom);
	for (int i = 0; i < 193; i++)
	{
		cout << tb;
	}
	Common::gotoXY(4, bottom + 1);
	for (int i = 0; i < 193; i++)
	{
		cout << tb;
	}
}

void Screen()
{
	int check = 1;
	while (check < 20)
	{
		LogoGame1();
		Sleep(100);
		check++;
	}
	LogoGame2();
}

void signTurn(int a)
{
	if (a == 1)
	{
		Common::gotoXY(17, 10); for (int i = 0; i < 12; i++) { cout << char(220); }
		Common::gotoXY(17, 12); for (int i = 0; i < 12; i++) { cout << char(220); }
		for (int i = 0; i < 2; i++)
		{
			Common::gotoXY(17, 11 + i); cout << char(219);
			Common::gotoXY(28, 11 + i); cout << char(219);
		}
	}
	if (a == 2)
	{
		Common::gotoXY(172, 10); for (int i = 0; i < 12; i++) { cout << char(220); }
		Common::gotoXY(172, 12); for (int i = 0; i < 12; i++) { cout << char(220); }
		for (int i = 0; i < 2; i++)
		{
			Common::gotoXY(172, 11 + i); cout << char(219);
			Common::gotoXY(183, 11 + i); cout << char(219);
		}
	}

}

void TextColor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}
void AnTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HienTroChuot()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void ScreenStartGame(int n)
{
	TaoKhung(49);
	AnTroChuot();

	TextColor(78);
	Common::gotoXY(90, 25); cout << "PLAYER VS PLAYER";
	TextColor(11);
	Common::gotoXY(87, 27); cout << "PLAYER WITH COMPUTER (easy)";
	Common::gotoXY(87, 29); cout << "PLAYER WITH COMPUTER (hard)";
	Common::gotoXY(93, 31); cout << "LOAD  GAME";
	Common::gotoXY(93, 33); cout << "ABOUT GAME";
	Common::gotoXY(96, 35); cout << "HELP";
	Common::gotoXY(96, 37); cout << "EXIT";
	if (n == 100)
	{
		PlaySound(TEXT("vaogame.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Screen();
	}
	else
	{
		LogoGame2();
	}
	char s[30] = " ";
	int select = 0;
	int coordinate = 25;
	do
	{
		char a = _getch();
		if (a == 's' || a == 'S') {  select = 1; }
		else if (a == 'w' || a == 'W') { select = 2;  }
		else if (a == 13 || a == 'e' || a == 'e' || a == '5') select = 3;
		if (select == 1 && coordinate < 37) coordinate += 2;
		else if (select == 2 && coordinate > 25) coordinate -= 2;
		if (coordinate == 25)
		{
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			TextColor(78);
			Common::gotoXY(90, 25); cout << "PLAYER VS PLAYER"; TextColor(11);
			Common::gotoXY(87, 27); cout << "PLAYER WITH COMPUTER (easy)";
			Common::gotoXY(87, 29); cout << "PLAYER WITH COMPUTER (hard)";
			Common::gotoXY(93, 31); cout << "LOAD  GAME";
			Common::gotoXY(93, 33); cout << "ABOUT GAME";
			Common::gotoXY(96, 35); cout << "HELP";
			Common::gotoXY(96, 37); cout << "EXIT";
		}
		if (coordinate == 27)
		{
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			TextColor(11);
			Common::gotoXY(90, 25); cout << "PLAYER VS PLAYER"; TextColor(78);
			Common::gotoXY(87, 27); cout << "PLAYER WITH COMPUTER (easy)"; TextColor(11);
			Common::gotoXY(87, 29); cout << "PLAYER WITH COMPUTER (hard)";
			Common::gotoXY(93, 31); cout << "LOAD  GAME";
			Common::gotoXY(93, 33); cout << "ABOUT GAME";
			Common::gotoXY(96, 35); cout << "HELP";
			Common::gotoXY(96, 37); cout << "EXIT";
		}
		if (coordinate == 29)
		{
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			TextColor(11);
			Common::gotoXY(90, 25); cout << "PLAYER VS PLAYER";
			Common::gotoXY(87, 27); cout << "PLAYER WITH COMPUTER (easy)"; TextColor(78);
			Common::gotoXY(87, 29); cout << "PLAYER WITH COMPUTER (hard)"; TextColor(11);
			Common::gotoXY(93, 31); cout << "LOAD  GAME";
			Common::gotoXY(93, 33); cout << "ABOUT GAME";
			Common::gotoXY(96, 35); cout << "HELP";
			Common::gotoXY(96, 37); cout << "EXIT";
		}
		if (coordinate == 31)
		{
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			TextColor(11);
			Common::gotoXY(90, 25); cout << "PLAYER VS PLAYER";
			Common::gotoXY(87, 27); cout << "PLAYER WITH COMPUTER (easy)";
			Common::gotoXY(87, 29); cout << "PLAYER WITH COMPUTER (hard)"; TextColor(78);
			Common::gotoXY(93, 31); cout << "LOAD  GAME"; TextColor(11);
			Common::gotoXY(93, 33); cout << "ABOUT GAME";
			Common::gotoXY(96, 35); cout << "HELP";
			Common::gotoXY(96, 37); cout << "EXIT";
		}
		if (coordinate == 33)
		{
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			TextColor(11);
			Common::gotoXY(90, 25); cout << "PLAYER VS PLAYER";
			Common::gotoXY(87, 27); cout << "PLAYER WITH COMPUTER (easy)";
			Common::gotoXY(87, 29); cout << "PLAYER WITH COMPUTER (hard)";
			Common::gotoXY(93, 31); cout << "LOAD  GAME"; TextColor(78);
			Common::gotoXY(93, 33); cout << "ABOUT GAME"; TextColor(11);
			Common::gotoXY(96, 35); cout << "HELP";
			Common::gotoXY(96, 37); cout << "EXIT";
		}
		if (coordinate == 35)
		{
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			TextColor(11);
			Common::gotoXY(90, 25); cout << "PLAYER VS PLAYER";
			Common::gotoXY(87, 27); cout << "PLAYER WITH COMPUTER (easy)";
			Common::gotoXY(87, 29); cout << "PLAYER WITH COMPUTER (hard)";
			Common::gotoXY(93, 31); cout << "LOAD  GAME";
			Common::gotoXY(93, 33); cout << "ABOUT GAME"; TextColor(78);
			Common::gotoXY(96, 35); cout << "HELP"; TextColor(11);
			Common::gotoXY(96, 37); cout << "EXIT";
		}
		if (coordinate == 37)
		{
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			TextColor(11);
			Common::gotoXY(90, 25); cout << "PLAYER VS PLAYER";
			Common::gotoXY(87, 27); cout << "PLAYER WITH COMPUTER (easy)";
			Common::gotoXY(87, 29); cout << "PLAYER WITH COMPUTER (hard)";
			Common::gotoXY(93, 31); cout << "LOAD  GAME";
			Common::gotoXY(93, 33); cout << "ABOUT GAME";
			Common::gotoXY(96, 35); cout << "HELP"; TextColor(78);
			Common::gotoXY(96, 37); cout << "EXIT";
		}
	} while (select != 3);
	system("cls");
	if (coordinate == 25)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = VsPlayer(a, 0, s);//s là mãng tên lưu để load game
		if (t == 27)
		{
			system("cls");
			ScreenStartGame(99);
		}
	}
	if (coordinate == 27)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = VsComEasy(a, 0, s);
		if (t == 27)
		{
			system("cls");
			ScreenStartGame(99);
		}
	}
	if (coordinate == 29)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = VsComHard(a, 0, s);
		if (t == 27)
		{
			system("cls");
			ScreenStartGame(99);
		}
	}
	if (coordinate == 31)
	{
		LoadLoad();
	}
	if (coordinate == 33)
	{
		About();
		ScreenStartGame(99);
	}
	if (coordinate == 35)
	{
		Help();
		ScreenStartGame(99);
	}
	if (coordinate == 37)
	{
		exit(0);
	}
}

int VsPlayer(Diem& a, int load, char data[30])//struc điểm
{

	int k = 1;
	int n = 99;
	HienTroChuot();
	Game g;
	g.setCountXY();//đém x , y
	if (load == -30)
	// -30 : Chế độ P vs P đang đến lượt O
	{
		g.setTurn();//đảo lượt vì lượt đầu mặt định x đi trước
		g.LoadGame(data);
	}
	else if (load == -31)// -31 : Chế độ P vs P đang đến lượt X
	{
		g.LoadGame(data);
	}
	else
		g.startGame();
	TextColor(Cyan);
	Common::gotoXY(89, 5);
	cout << " PLAYER VS PLAYER ";
	TextColor(Blue);
	Common::gotoXY(33,27);
	cout << a.score1;
	TextColor(Red);
	Common::gotoXY(167,27);
	cout << a.score2;
	Common::gotoXY(42, 9);
	while (g.isContinue())
	{
		g.waitKeyBoard();
		if (g.getCommand() == 27) {
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			return 27;
		}
		else
		{
			
			switch (g.getCommand())
			{
			case 'A':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.moveLeft();
				break;
			case 'D':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.moveRight();
				break;
			case 'W':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.moveUp();
				break;
			case 'S':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.moveDown();
				break;
			case 'L':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (g.getTurn() == 1)
					g.SaveGame(-31);
				else
					g.SaveGame(-30);
				break;
			case 'T':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				LoadLoad();
				break;
			case 13:
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()) {//đánh x, o;
					switch (g.processFinish(x, y)) {//kiểm tra thắng thua, Đổi lượt.
					case -1:
						a.score1++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									load = 0;
									return VsPlayer(a, load, data);
									break;
								case 27:
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									load = 0;
									return VsPlayer(a, load, data);
									break;
								case 27:
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;
					case 0:
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									load = 0;
									return VsPlayer(a, load, data);
									break;
								case 27:
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									system("cls");
									ScreenStartGame(n);
									break;
								}
							}
						}
						break;

					}
				}
			}
		}
	}
}
//tất cả nằm trong vòng lặp while continue

 int VsComEasy(Diem& a, int load, char data[30])
 {
	int k = 1, n = 100;
	HienTroChuot();
	Game g;
	g.setCountXY();
	if (load == -5)
	{
		g.LoadGame(data);
	}
	else
	{
		g.startGame();
		g.setTurn();
	}
	TextColor(Cyan);
	Common::gotoXY(89, 5);
	cout << " PLAYER VS COM (easy) ";
	TextColor(Blue);
	Common::gotoXY(33, 27);
	cout << a.score1;
	TextColor(Red);
	Common::gotoXY(167, 27);
	cout << a.score2;
	Common::gotoXY(42, 9);
	while (g.isContinue())//get biến loop(tiếp tục hay dừng);
	{
		if (!g.getTurn())//lấy gái trị của lượt chơi.
		{
			if (g.DemNuocCoDaDi() == 0)
			{
				g.setX(92);
				g.setY(25);
				Common::gotoXY(92,25);
				g.setCommand(13);
			}
			else
			{
				g.TimKiemNuocDi2();
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				Common::gotoXY(x, y);
				Sleep(300);
				g.setCommand(13);
			}
		}
		else
			g.waitKeyBoard();
		if (g.getCommand() == 27)
		{
			PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			return 27;
		}
		else
		{
			switch (g.getCommand())
			{
			case 'A':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.moveLeft();
				break;
			case 'D':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.moveRight();
				break;
			case 'W':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.moveUp();
				break;
			case 'S':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.moveDown();
				break;
			case 'L':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				g.SaveGame(-5);
				break;
			case 'T':
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				LoadLoad();
				break;
			case 13:
				PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				int x = g.getXatEnter();
				int y = g.getYatEnter();
				if (g.processCheckBoard()) {
					switch (g.processFinish(x, y)) {
					case -1:
						a.score1++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									load = 0;
									return VsComEasy(a, load, data);
									break;
								case 27:
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									system("cls");
									ScreenStartGame(n - 1);
									break;
								}
							}
						}
						break;
					case 1:
						a.score2++;
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									load = 0;
									return VsComEasy(a, load, data);
									break;
								case 27:
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									system("cls");
									ScreenStartGame(n - 1);
									break;
								}
							}
						}

						break;
					case 0:
						while (k)
						{
							if (_kbhit())
							{
								switch (_getch())
								{
								case 'y':
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									load = 0;
									return VsComEasy(a, load, data);
									break;
								case 27:
									PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									system("cls");
									ScreenStartGame(n - 1);
									break;
								}
							}
						}
						break;
					}
				}
			}
		}

	}
 }
 void Help()
 {
	 
	 int x = 80, y = 20;
	 Common::gotoXY(x, y);
	 for (int i = x; i < x+50; i++)
	 {
		 cout << char(220);
	 }
	 Common::gotoXY(x-1, y-1);
	 for (int i = x-1; i < x + 51; i++)
	 {
		 cout << char(220);
	 }
	 Common::gotoXY(x, y+17);
	 for (int i = x; i < x + 50; i++)
	 {
		 cout << char(220);
	 }
	 Common::gotoXY(x - 1, y+18);
	 for (int i = x - 1; i < x + 51; i++)
	 {
		 cout << char(220);
	 }


	 for (int i = 1; i < 18; i++)
	 {
		 Common::gotoXY(x, y + i); cout << char(219);
		 Common::gotoXY(x+49, y + i); cout << char(219);
	 }
	 Common::gotoXY(x + 2, y + 1); cout << "              Huong dan :";
	 Common::gotoXY(x+2, y+3); cout << "  L : Luu Game Da choi.";
	 Common::gotoXY(x+2, y+4); cout << "  T : Tai Game Da choi.";
	 Common::gotoXY(x+2, y+5); cout << "  ESc : Thoat Game.";
	 Common::gotoXY(x+2, y+6); cout << "  Load Game : Tai Game Da choi.";

	 Common::gotoXY(x + 2, y + 9); cout << "              Luat choi : ";
	 Common::gotoXY(x + 2, y + 10); cout << "  Du 5 quan co lien tiep ma hai dau khong bi ";
	 Common::gotoXY(x + 2, y + 11); cout << "  chan boi hai quan dich la chien thang";
	 Common::gotoXY(x + 2, y + 13); cout << " ^_^ | Chuc cac ban choi game vui ve | ^_^";
	
	 Common::gotoXY(x + 2, y + 16); cout << "    Nhan bat ky de quay lai.";
	

	 cout << "    <<<<BACK";
	 PlaySound(TEXT("abouthelp.wav"), NULL, SND_FILENAME | SND_ASYNC);
	 char command = ' ';
	 command = _getch();
	 system("cls");
 }
 void About()
 {
	 int x = 80, y = 20;
	 Common::gotoXY(x, y);
	 for (int i = x; i < x + 50; i++)
	 {
		 
		 cout << char(220);
	 }
	 Common::gotoXY(x - 1, y - 1);
	 for (int i = x - 1; i < x + 51; i++)
	 {
		 cout << char(220);
	 }
	 Common::gotoXY(x, y + 17);
	 for (int i = x; i < x + 50; i++)
	 {
		 cout << char(220);
	 }
	 Common::gotoXY(x - 1, y + 18);
	 for (int i = x - 1; i < x + 51; i++)
	 {
		 cout << char(220);
	 }


	 for (int i = 1; i < 18; i++)
	 {
		 Common::gotoXY(x, y + i); cout << char(219);
		 Common::gotoXY(x + 49, y + i); cout << char(219);
	 }
	 Common::gotoXY(x + 2, y + 1); cout << "                DO AN CO CARO";
	 Common::gotoXY(x + 2, y + 3); cout << "   GIAO VIEN HUONG DAN : ";
	 
	 Common::gotoXY(x + 2, y + 5); cout << "   MSSV : 19127295";
	 
	 Common::gotoXY(x + 2, y + 7); cout << "   MSSV : 19127612";
	 
	 Common::gotoXY(x + 2, y + 9); cout << "   MSSV : 19127615";
	 
	 Common::gotoXY(x + 2, y + 11); cout << "   MSSV : 19127456";
	 
	 Common::gotoXY(x + 2, y + 15); cout << "   Nhan bat ky de thoat ";
	 Common::gotoXY(x + 2, y + 16); cout << " Chuc cac ban choi game vui ve";

	 TextColor(12);
	 Common::gotoXY(x + 2, y + 4); cout << "             TRUONG TOAN THINH ";
	 Common::gotoXY(x + 2, y + 6); cout << "             TRAN THE TOAN ";
	 Common::gotoXY(x + 2, y + 8); cout << "             TRAN ANH TU ";
	 Common::gotoXY(x + 2, y + 10); cout << "             NGUYEN ANH TUAN   ";
	 Common::gotoXY(x + 2, y + 12); cout << "             NGUYEN THANH KIEN";
	 PlaySound(TEXT("abouthelp.wav"), NULL, SND_FILENAME | SND_ASYNC);
	 char command = ' ';
	 command = _getch();
	 system("cls");
 }
 int VsComHard(Diem& a, int load, char data[30])
 {
	 int k = 1, n = 100;
	 HienTroChuot();
	 Game g;
	 g.setCountXY();
	 if (load == -5)
	 {
		 g.LoadGame(data);
	 }
	 else
	 {
		 g.startGame();
		 g.setTurn();
	 }
	 TextColor(Cyan);
	 Common::gotoXY(89, 5);
	 cout << " PLAYER VS COM (hard) ";
	 TextColor(Blue);
	 Common::gotoXY(33, 27);
	 cout << a.score1;
	 TextColor(Red);
	 Common::gotoXY(167, 27);
	 cout << a.score2;
	 Common::gotoXY(42, 9);
	 while (g.isContinue())//get biến loop(tiếp tục hay dừng);
	 {
		 if (!g.getTurn())//lấy gái trị của lượt chơi.
		 {
			 if (g.DemNuocCoDaDi() == 0)
			 {
				 g.setX(92);
				 g.setY(25);
				 Common::gotoXY(92, 25);
				 g.setCommand(13);
			 }
			 else
			 {
				 g.TimKiemNuocDi();
				 int x = g.getXatEnter();
				 int y = g.getYatEnter();
				 Common::gotoXY(x, y);
				 Sleep(300);
				 g.setCommand(13);
			 }
		 }
		 else
			 g.waitKeyBoard();
		 if (g.getCommand() == 27)
		 {
			 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
			 return 27;
		 }
		 else
		 {
			 switch (g.getCommand())
			 {
			 case 'A':
				 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				 g.moveLeft();
				 break;
			 case 'D':
				 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				 g.moveRight();
				 break;
			 case 'W':
				 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				 g.moveUp();
				 break;
			 case 'S':
				 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				 g.moveDown();
				 break;
			 case 'L':
				 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				 g.SaveGame(-5);
				 break;
			 case 'T':
				 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				 LoadLoad();
				 break;
			 case 13:
				 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
				 int x = g.getXatEnter();
				 int y = g.getYatEnter();
				 if (g.processCheckBoard()) {
					 switch (g.processFinish(x, y)) {
					 case -1:
						 a.score1++;
						 while (k)
						 {
							 if (_kbhit())
							 {
								 switch (_getch())
								 {
								 case 'y':
									 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									 load = 0;
									 return VsComHard(a, load, data);
									 break;
								 case 27:
									 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									 system("cls");
									 ScreenStartGame(n - 1);
									 break;
								 }
							 }
						 }
						 break;
					 case 1:
						 a.score2++;
						 while (k)
						 {
							 if (_kbhit())
							 {
								 switch (_getch())
								 {
								 case 'y':
									 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									 load = 0;
									 return VsComHard(a, load, data);
									 break;
								 case 27:
									 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									 system("cls");
									 ScreenStartGame(n - 1);
									 break;
								 }
							 }
						 }

						 break;
					 case 0:
						 while (k)
						 {
							 if (_kbhit())
							 {
								 switch (_getch())
								 {
								 case 'y':
									 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									 load = 0;
									 return VsComHard(a, load, data);
									 break;
								 case 27:
									 PlaySound(TEXT("tick.wav"), NULL, SND_FILENAME | SND_ASYNC);
									 system("cls");
									 ScreenStartGame(n - 1);
									 break;
								 }
							 }
						 }
						 break;
					 }
				 }
			 }
		 }

	 }
 }
void LoadLoad()
{
	
	int n = 100;
	system("cls");
	LogoGame2();
	TaoKhung(46);
	ReadNameFile();
	char data[30];
	Common::gotoXY(90, 40);
	HienTroChuot();
	cout << "ENTER FILE NAME: ";
	cin.getline(data, 30);
	int chedo = ReadChedo(data);
	if (chedo == -30 || chedo == -31)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = VsPlayer(a, chedo, data);
		if (t == 27)
		{
			system("cls");
			ScreenStartGame(n - 1);
		}
	}
	if (chedo == -4)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = VsComEasy(a, -4, data);
		if (t == 27)
		{
			system("cls");
			ScreenStartGame(n - 1);
		}
	}
	if (chedo == -5)
	{
		Diem a;
		a.score1 = 0;
		a.score2 = 0;
		int t = VsComHard(a, -5, data);
		if (t == 27)
		{
			system("cls");
			ScreenStartGame(n - 1);
		}
	}
	
}
