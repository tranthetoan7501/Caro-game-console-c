#pragma once
#include "Play.h"
#include "Board.h"
#include "Common.h"
vector <Point> win;

int Board::getX_at(int i, int j)
{
	return pos[i][j].getX();
}

int Board::getY_at(int i, int j)
{
	return pos[i][j].getY();
}

int Board::getCheck_at(int i, int j)
{
	return pos[i][j].getCheck();
}

void Board::loadData(int i, int j, int check)
{
	pos[i][j].setX(j * 5 + 42);
	pos[i][j].setY(i * 2 + 9);
	pos[i][j].setCheck(check);
	if (check == -1)
	{
		TextColor(Blue);	//X
		Common::gotoXY(5 * j + left, i * 2 + top);
		cout << "X";
		countX++;
		TextColor(Green);
	}
	if (check == 1)
	{
		TextColor(Red);	//O
		Common::gotoXY(5 * j + left, i * 2 + top);
		cout << "O";
		countO++;
		TextColor(Green);
	}
}

void Board::reset()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < D; j++)
		{
			pos[i][j].setX(5 * j + 42);
			pos[i][j].setY(2 * i + 9);
			pos[i][j].setCheck(0);
		}
	}
}

void Board::drawBoard()
{
	Common::gotoXY(19, 11); cout << "PLAYER 1";
	Common::gotoXY(174, 11); cout << "PLAYER 2";

	Common::gotoXY(15, 24); cout << "SO LUOT : ";
	Common::gotoXY(177, 24); cout << ": SO LUOT";
	Common::gotoXY(15, 27); cout << "SO TRAN THANG : ";
	Common::gotoXY(171, 27); cout << ": SO TRAN THANG";
	TextColor(11);
	Common::gotoXY(8, 7);
	for (int i = 0; i < 185; i++)
	{
		cout << char(220);
	}
	Common::gotoXY(8, 45);
	for (int i = 0; i < 185; i++)
	{
		cout << char(220);
	}
	for (int i = 0; i < 38; i++)
	{
		Common::gotoXY(8, 8 + i); cout << char(219);
		Common::gotoXY(38, 8 + i); cout << char(219);
		Common::gotoXY(162, 8 + i); cout << char(219);
		Common::gotoXY(192, 8 + i); cout << char(219);
	}
	for (int i = 7; i <= 45; i++)
	{
		if (i % 2 == 0) {
			Common::gotoXY(40, i);
			for (int j = 0; j < 120; j++)
			{
				cout << (char)196;
			}
		}
	}
	for (int i = 8; i <= 44; i++)
	{

		for (int j = 40; j < 165; j++)
		{
			if (j % 5 == 0)
			{
				Common::gotoXY(j, i);
				cout << (char)179;
			}

		}

	}
	Common::gotoXY(pos[0][0].getX(), pos[0][0].getY());
}

int Board::check_XO(int x, int y, int turn)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < D; j++)
		{
			if (pos[i][j].getX() == x && pos[i][j].getY() == y && pos[i][j].getCheck() == 0)
			{
				if (turn)
				{
					pos[i][j].setCheck(-1);
					countX++;
				}	// X
				else
				{
					pos[i][j].setCheck(1);
					countO++;
				}	// O	
				return pos[i][j].getCheck();
			}
		}
	}
	return 0;
}

int Board::checkWinRow(int x, int y, int value)
{
	int dong, cot;
	int loop = 1;
	int test = -1;
	int check2dau = 0;
	int countColLeft = 0, countColRight = 0;
	cot = (x - left ) / 5;//khoảng cách giữa hai cột là 5
	dong = (y - top ) / 2;//khoảng cahs giữa hai dòng là 2
	int cottrai, cotphai; // Xet dem X ve phia trai, va ve phia phai
	cottrai = cotphai = cot;
	// Xet X chien thang
	// Xet hang ngang
	while (pos[dong][cottrai].getCheck() == value)
	{
		win.push_back(pos[dong][cottrai]);
		countColLeft++;
		if (cottrai == 0)
			break;
		cottrai--;
	}
	while (pos[dong][cotphai].getCheck() == value)
	{
		win.push_back(pos[dong][cotphai]);
		countColRight++;
		if (cotphai == 24 - 1)
			break;
		cotphai++;
	}
	if (pos[dong][cottrai].getCheck() == -value && pos[dong][cotphai].getCheck() == -value)
		check2dau = 1;
	if (((countColLeft + countColRight - 1) == 5 && (check2dau == 0))|| (countColLeft + countColRight - 1) > 5)
	{
		test = 1;
	}
	else
		test = 0;
	if (test == 1)
	{
		//
		while (loop < 30)
		{
			TextColor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				Common::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}
int Board::checkWinCol(int x, int y, int value) // Xet chien thang theo hang doc
{
	int dong, cot;
	int test = -1, loop = 1;
	int check2dau = 0;
	int countRowTop = 0, countRowBot = 0;
	cot = (x - left) / 5;
	dong = (y - top) / 2;
	int dongtren, dongduoi; // Xet bien dem ve phia tren, va ve phia duoi
	dongtren = dongduoi = dong;
	// Xet chien thang
	// Xet hang doc
	while (pos[dongtren][cot].getCheck() == value)
	{
		countRowTop++;
		win.push_back(pos[dongtren][cot]);
		if (dongtren == 0)
			break;
		dongtren--;
	}
	while (pos[dongduoi][cot].getCheck() == value)
	{
		countRowBot++;
		win.push_back(pos[dongduoi][cot]);
		if (dongduoi == 18 - 1)
			break;
		dongduoi++;
	}
	if (pos[dongtren][cot].getCheck() == -value && pos[dongduoi][cot].getCheck() == -value)
		check2dau = 1;
	if (((countRowTop + countRowBot - 1) == 5 && (check2dau == 0)) || (countRowTop + countRowBot - 1) > 5)
	{
		test = 1;
	}
	else
		test = 0;
	if (test == 1)
	{
		//
		while (loop < 30)
		{
			TextColor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				Common::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}
int Board::checksecondDiagonal(int x, int y, int value)
{
	int dong, cot;
	int test = -1, loop = 1;
	int check2dau = 0;
	int countDiaTop = 0, countDiaBot = 0;
	cot = (x - left ) / 5;
	dong = (y - top ) / 2;
	int dongtren, dongduoi;// Xet dem X ve phia tren, va ve phia duoi
	int cotphai, cottrai;
	dongtren = dongduoi = dong;
	cotphai = cottrai = cot;
	// Xet X chien thang
	// Xet hang ngang
	while (pos[dongtren][cottrai].getCheck() == value)
	{
		win.push_back(pos[dongtren][cottrai]);
		countDiaTop++;
		if (dongtren == 0 || cottrai == 0)
			break;
		dongtren--;
		cottrai--;
	}

	while (pos[dongduoi][cotphai].getCheck() == value)
	{
		win.push_back(pos[dongduoi][cotphai]);
		countDiaBot++;
		if (dongduoi == 18 - 1 || cotphai == 24 - 1)
			break;
		dongduoi++;
		cotphai++;
	}
	if (pos[dongtren][cottrai].getCheck() == -value && pos[dongduoi][cotphai].getCheck() == -value)
		check2dau = 1;
	if (((countDiaTop + countDiaBot - 1) == 5 && (check2dau == 0))|| (countDiaTop + countDiaBot - 1) > 5)
	{
		test = 1;
	}
	else
		test = 0;
	if (test == 1)
	{
		//
		while (loop < 30)
		{
			TextColor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				Common::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}
int Board::checkfirstDiagonal(int x, int y, int value)
{
	int dong, cot;
	int test = -1, loop = 1;
	int check2dau = 0;
	int countDiaTop = 0, countDiaBot = 0;
	cot = (x - left ) / 5;
	dong = (y - top ) / 2;
	int dongtren, dongduoi;// Xet dem X ve phia tren, va ve phia duoi
	int cotphai, cottrai;
	dongtren = dongduoi = dong;
	cotphai = cottrai = cot;
	// Xet X chien thang
	// Xet hang ngang
	while (pos[dongtren][cotphai].getCheck() == value)
	{
		countDiaTop++;
		win.push_back(pos[dongtren][cotphai]);
		if (dongtren == 0 || cotphai == 24 - 1)
			break;
		dongtren--;
		cotphai++;
	}
	while (pos[dongduoi][cottrai].getCheck() == value)
	{
		win.push_back(pos[dongduoi][cottrai]);
		countDiaBot++;
		if (dongduoi == 18 - 1 || cottrai == 0)
			break;
		dongduoi++;
		cottrai--;
	}
	if (pos[dongtren][cotphai].getCheck() == -value && pos[dongduoi][cottrai].getCheck() == -value)
		check2dau = 1;
	if (((countDiaTop + countDiaBot - 1) == 5 && (check2dau == 0))|| (countDiaTop + countDiaBot - 1) > 5)
	{
		test = 1;
	}
	else
		test = 0;
	if (test == 1)
	{
		
		while (loop < 30)
		{
			TextColor(rand() % 15 + 1);
			for (int i = 0; i < win.size(); i++)
			{
				Common::gotoXY(win[i].getX(), win[i].getY());
				if (win[i].getCheck() == -1)
					cout << "X";
				else
					cout << "O";
			}
			Sleep(100);
			loop++;
		}
	}
	else win.clear();
	return test;
}

int Board::testBoard(int x, int y)
{
	//x chien thang
	if (checkWinRow(x, y, -1) == 1)
		return -1;
	if (checkWinCol(x, y, -1) == 1)
		return -1;
	if (checkfirstDiagonal(x, y, -1) == 1)
		return -1;
	if (checksecondDiagonal(x, y, -1) == 1)
		return -1;
	// O chien thang
	if (checkWinRow(x, y, 1) == 1)
		return 1;
	if (checkWinCol(x, y, 1) == 1)
		return 1;
	if (checkfirstDiagonal(x, y, 1) == 1)
		return 1;
	if (checksecondDiagonal(x, y, 1) == 1)
		return 1;
	if (countX + countO == 18*24)
		return 0;
	return 2;//chưa ai thắng
}
Point Board::Tim_NuocDi_hard()
{
	Point result;
	int dong = 0, cot = 0;
	long Diemchinh = 0;
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			long Diemphu = 0;
			
			if (pos[i][j].getCheck() == 0)
			{
				Diemphu += diem_doc_hard(i,j);
				Diemphu += diem_ngang_hard(i,j);
				Diemphu += diem_cheo1_hard(i,j);
				Diemphu += diem_cheo2_hard(i,j);
			
			if (Diemchinh<Diemphu)
				{
					Diemchinh = Diemphu;
					dong = i;
					cot = j;
				}				
			}
		}
	}
	result.setX(cot*5 + 42);
	result.setY(dong*2 + 9);
	return result;
}
long Board::diem_ngang_hard(int dong, int cot)
{
	long diem = 0;
	long soquanta1 = 0;
	long soquanta2 = 0;
	long soquandich = 0;
	long so_o_trong = 0;
	int k = 0;
	//kiểm tra sang trái
	for (int i = 1; i < 6 && cot+i<24; i++)
	{
		if (pos[dong][cot + i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong][cot + i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong][cot + i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6&&cot-i>=0; i++)
	{
		if (pos[dong][cot - i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong][cot - i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong][cot - i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//xet de tan cong
	if (soquandich == 2)
	{
		if ((soquanta1+soquanta2 + so_o_trong) <= 6)
		{
			diem -= 12345;
		}
		else
		{
			diem += 12*soquanta1+1*soquanta2;
		}
	}
	if (soquandich == 1)
	{
		diem += soquanta1 * 120 + soquanta2;
		if (soquanta1 == 3)
		{
			diem += 1000;
		}
	}
	if (soquandich == 0)
	{
		diem +=soquanta1 * 129 + soquanta2;
		if (soquanta1 == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 4 && (so_o_trong > 0 || soquanta2 > 0))
	{
		diem += 123456789;
	}
	//kiem tra quan dich
	soquanta1 = 0;
	soquandich = 0;
	long soquandich2 = 0;
	so_o_trong = 0;
	k = 0;
	//kiểm tra sang trái
	for (int i = 1; i < 6 && cot + i < 24; i++)
	{
		if (pos[dong][cot + i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong][cot + i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong][cot + i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && cot - i >= 0; i++)
	{
		if (pos[dong][cot - i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong][cot - i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong][cot - i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//xet phong thu
	if (soquanta1 == 0)
	{
		diem += soquandich * 19 + soquandich2 * 1;
		if (soquandich == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 1)
	{
		diem += soquandich * 10 + soquandich2 * 1;
		if (soquandich == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 2)
	{
		if ((soquandich + soquandich2 + so_o_trong) <= 6)
		{
			diem -= 1234;
		}
		else
		{
			diem += 10 * soquandich + 2 * soquandich2;
		}
	}
	if (soquandich == 4 )
	{
		diem += 12345678;
	}
	return diem;
	
}
long Board::diem_doc_hard(int dong, int cot)
{
	long diem = 0;
	long soquanta1 = 0;
	long soquanta2 = 0;
	long soquandich = 0;
	long so_o_trong = 0;
	int k = 0;
	//kiểm tra sang trái
	for (int i = 1; i < 6 && dong + i < 18; i++)
	{
		if (pos[dong + i][cot ].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong+i][cot].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong+i][cot].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0; i++)
	{
		if (pos[dong-i][cot].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong-i][cot].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong-i][cot].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//xet de tan cong
	if (soquandich == 2)
	{
		if ((soquanta1 + soquanta2 + so_o_trong) <= 6)
		{
			diem -= 12345;
		}
		else
		{
			diem += 12 * soquanta1 + 1 * soquanta2;
		}
	}
	if (soquandich == 1)
	{
		diem += soquanta1 * 120 + soquanta2;
		if (soquanta1 == 3)
		{
			diem += 1000;
		}
	}
	if (soquandich == 0)
	{
		diem += soquanta1 * 129 + soquanta2;
		if (soquanta1 == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 4 && (so_o_trong > 0 || soquanta2 > 0))
	{
		diem += 123456789;
	}
	//kiem tra quan dich
	soquanta1 = 0;
	soquandich = 0;
	long soquandich2 = 0;
	so_o_trong = 0;
	k = 0;
	//kiểm tra sang trái
	for (int i = 1; i < 6 && dong + i < 18; i++)
	{
		if (pos[dong+i][cot].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong+i][cot].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong+i][cot].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0; i++)
	{
		if (pos[dong-i][cot ].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong-i][cot].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong-i][cot].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//xet phong thu
	if (soquanta1 == 0)
	{
		diem += soquandich * 190 + soquandich2 * 1;
		if (soquandich == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 1)
	{
		diem += soquandich * 100 + soquandich2 * 1;
		if (soquandich == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 2)
	{
		if ((soquandich + soquandich2 + so_o_trong) <= 6)
		{
			diem -= 1234;
		}
		else
		{
			diem += 10 * soquandich + 2 * soquandich2;
		}
	}
	if (soquandich == 4)
	{
		diem += 12345678;
	}
	return diem;
}
long Board::diem_cheo1_hard(int dong, int cot)
{
	long diem = 0;
	long soquanta1 = 0;
	long soquanta2 = 0;
	long soquandich = 0;
	long so_o_trong = 0;
	long k = 0;
	//kiểm tra sang trái
	for (int i = 1; i < 6 && dong + i < 18&&cot+i<24; i++)
	{
		if (pos[dong + i][cot+i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong + i][cot+i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong + i][cot+i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0&&cot-i>=0; i++)
	{
		if (pos[dong - i][cot-i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong - i][cot-i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong - i][cot-i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//xet de tan cong
	if (soquandich == 2)
	{
		if ((soquanta1 + soquanta2 + so_o_trong) <= 6)
		{
			diem -= 12345;
		}
		else
		{
			diem += 12 * soquanta1 + 1 * soquanta2;
		}
	}
	if (soquandich == 1)
	{
		diem += soquanta1 * 120 + soquanta2;
		if (soquanta1 == 3)
		{
			diem += 1000;
		}
	}
	if (soquandich == 0)
	{
		diem += soquanta1 * 129 + soquanta2;
		if (soquanta1 == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 4 && (so_o_trong > 0 || soquanta2 > 0))
	{
		diem += 123456789;
	}
	//kiem tra quan dich
	soquanta1 = 0;
	soquandich = 0;
	long soquandich2 = 0;
	so_o_trong = 0;
	k = 0;
	//kiểm tra sang phai
	for (int i = 1; i < 6 && dong + i < 18 && cot+i<24; i++)
	{
		if (pos[dong + i][cot+i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong + i][cot+i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong + i][cot+i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0 && cot -i>=0; i++)
	{
		if (pos[dong - i][cot-i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong - i][cot-i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong - i][cot-i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//xet phong thu
	if (soquanta1 == 0)
	{
		diem += soquandich * 190 + soquandich2 * 1;
		if (soquandich == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 1)
	{
		diem += soquandich * 100 + soquandich2 * 1;
		if (soquandich == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 2)
	{
		if ((soquandich + soquandich2 + so_o_trong) <= 6)
		{
			diem -= 1234;
		}
		else
		{
			diem += 10 * soquandich + 2 * soquandich2;
		}
	}
	if (soquandich == 4 )
	{
		diem += 12345678;
	}
	return diem;
}
long Board::diem_cheo2_hard(int dong, int cot)
{
	long diem = 0;
	long soquanta1 = 0;
	long soquanta2 = 0;
	long soquandich = 0;
	long so_o_trong = 0;
	long k = 0;
	//kiểm tra xuống sang trái
	for (int i = 1; i < 6 && dong + i < 18 && cot - i >=0; i++)
	{
		if (pos[dong + i][cot - i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong + i][cot - i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong + i][cot - i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//kiem tra lên sang phải
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0 && cot + i < 24; i++)
	{
		if (pos[dong - i][cot + i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong - i][cot + i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong - i][cot + i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//xet de tan cong
	if (soquandich == 2)
	{
		if ((soquanta1 + soquanta2 + so_o_trong) <= 6)
		{
			diem -= 12345;
		}
		else
		{
			diem += 12 * soquanta1 + 1 * soquanta2;
		}
	}
	if (soquandich == 1)
	{
		diem += soquanta1 * 120 + soquanta2;
		if (soquanta1 == 3)
		{
			diem += 1000;
		}
	}
	if (soquandich == 0)
	{
		diem += soquanta1 * 129 + soquanta2;
		if (soquanta1 == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 4 && (so_o_trong > 0 || soquanta2 > 0))
	{
		diem += 123456789;
	}
	//kiem tra quan dich
	soquanta1 = 0;
	soquandich = 0;
	long soquandich2 = 0;
	so_o_trong = 0;
	k = 0;
	//kiểm tra sang phai
	for (int i = 1; i < 6 && dong + i < 18 && cot - i >=0; i++)
	{
		if (pos[dong + i][cot - i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong + i][cot - i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong + i][cot - i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//kiểm lên sang phải
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0 && cot + i <24; i++)
	{
		if (pos[dong - i][cot + i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong - i][cot + i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong - i][cot + i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//xét phòng thủ
	if (soquanta1 == 0)
	{
		diem += soquandich * 190 + soquandich2 * 1;
		if (soquandich == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 1)
	{
		diem += soquandich * 100 + soquandich2 * 1;
		if (soquandich == 3)
		{
			diem += 1000;
		}
	}
	if (soquanta1 == 2)
	{
		if ((soquandich + soquandich2 + so_o_trong) <= 6)
		{
			diem -= 1234;
		}
		else
		{
			diem += 10 * soquandich + 2 * soquandich2;
		}
	}
	if (soquandich == 4)
	{
		diem += 12345678;
	}
	return diem;
}



Point Board::Tim_NuocDi_easy()
{
	Point result;
	int dong = 0, cot = 0;
	long Diemchinh = 0;
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			long Diemphu = 0;

			if (pos[i][j].getCheck() == 0)
			{
				Diemphu += diem_doc_easy(i, j);
				Diemphu += diem_ngang_easy(i, j);
				Diemphu += diem_cheo1_easy(i, j);
				Diemphu += diem_cheo2_easy(i, j);

				if (Diemchinh < Diemphu)
				{
					Diemchinh = Diemphu;
					dong = i;
					cot = j;
				}
			}
		}
	}
	result.setX(cot * 5 + 42);
	result.setY(dong * 2 + 9);
	return result;
}

long Board::diem_ngang_easy(int dong, int cot)
{
	long diem = 0;
	long soquanta1 = 0;
	long soquanta2 = 0;
	long soquandich = 0;
	long so_o_trong = 0;
	int k = 0;
	//kiểm tra sang trái
	for (int i = 1; i < 6 && cot + i < 24; i++)
	{
		if (pos[dong][cot + i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong][cot + i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong][cot + i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && cot - i >= 0; i++)
	{
		if (pos[dong][cot - i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong][cot - i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong][cot - i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//xet de tan cong

	if (soquandich == 1)
	{
		diem += soquanta1 * 120 + soquanta2;
		
	}
	if (soquandich == 0)
	{
		diem += soquanta1 * 129 + soquanta2;
		
	}
	if (soquanta1 == 4 && (so_o_trong > 0 || soquanta2 > 0))
	{
		diem += 123456789;
	}
	//kiem tra quan dich
	soquanta1 = 0;
	soquandich = 0;
	long soquandich2 = 0;
	so_o_trong = 0;
	k = 0;
	//kiểm tra sang trái
	for (int i = 1; i < 6 && cot + i < 24; i++)
	{
		if (pos[dong][cot + i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong][cot + i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong][cot + i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && cot - i >= 0; i++)
	{
		if (pos[dong][cot - i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong][cot - i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong][cot - i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//xet phong thu
	if (soquanta1 == 0)
	{
		diem += soquandich * 19 + soquandich2 * 1;
		
	}
	if (soquanta1 == 1)
	{
		diem += soquandich * 10 + soquandich2 * 1;
		
	}
	if (soquandich == 4)
	{
		diem += 12345678;
	}
	return diem;

}
long Board::diem_doc_easy(int dong, int cot)
{
	long diem = 0;
	long soquanta1 = 0;
	long soquanta2 = 0;
	long soquandich = 0;
	long so_o_trong = 0;
	int k = 0;
	//kiểm tra sang trái
	for (int i = 1; i < 6 && dong + i < 18; i++)
	{
		if (pos[dong + i][cot].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong + i][cot].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong + i][cot].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0; i++)
	{
		if (pos[dong - i][cot].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong - i][cot].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong - i][cot].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//xet de tan cong
	if (soquandich == 1)
	{
		diem += soquanta1 * 120 + soquanta2;
	}
	if (soquandich == 0)
	{
		diem += soquanta1 * 129 + soquanta2;
	}
	if (soquanta1 == 4 && (so_o_trong > 0 || soquanta2 > 0))
	{
		diem += 123456789;
	}
	//kiem tra quan dich
	soquanta1 = 0;
	soquandich = 0;
	long soquandich2 = 0;
	so_o_trong = 0;
	k = 0;
	//kiểm tra sang trái
	for (int i = 1; i < 6 && dong + i < 18; i++)
	{
		if (pos[dong + i][cot].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong + i][cot].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong + i][cot].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0; i++)
	{
		if (pos[dong - i][cot].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong - i][cot].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong - i][cot].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//xet phong thu
	if (soquanta1 == 0)
	{
		diem += soquandich * 190 + soquandich2 ;
	}
	if (soquanta1 == 1)
	{
		diem += soquandich * 100 + soquandich2 ;
	}
	if (soquandich == 4)
	{
		diem += 12345678;
	}
	return diem;
}
long Board::diem_cheo1_easy(int dong, int cot)
{
	long diem = 0;
	long soquanta1 = 0;
	long soquanta2 = 0;
	long soquandich = 0;
	long so_o_trong = 0;
	long k = 0;
	//kiểm tra sang trái
	for (int i = 1; i < 6 && dong + i < 18 && cot + i < 24; i++)
	{
		if (pos[dong + i][cot + i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong + i][cot + i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong + i][cot + i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0 && cot - i >= 0; i++)
	{
		if (pos[dong - i][cot - i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong - i][cot - i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong - i][cot - i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//xet de tan cong
	if (soquandich == 1)
	{
		diem += soquanta1 * 120 + soquanta2;		
	}
	if (soquandich == 0)
	{
		diem += soquanta1 * 129 + soquanta2;
	}
	if (soquanta1 == 4 && (so_o_trong > 0 || soquanta2 > 0))
	{
		diem += 123456789;
	}
	//kiem tra quan dich
	soquanta1 = 0;
	soquandich = 0;
	long soquandich2 = 0;
	so_o_trong = 0;
	k = 0;
	//kiểm tra sang phai
	for (int i = 1; i < 6 && dong + i < 18 && cot + i < 24; i++)
	{
		if (pos[dong + i][cot + i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong + i][cot + i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong + i][cot + i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//kiem tra sang phai
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0 && cot - i >= 0; i++)
	{
		if (pos[dong - i][cot - i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong - i][cot - i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong - i][cot - i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//xet phong thu
	if (soquanta1 == 0)
	{
		diem += soquandich * 190 + soquandich2 * 1;
		
	}
	if (soquanta1 == 1)
	{
		diem += soquandich * 100 + soquandich2 * 1;
		
	}
	if (soquanta1 == 2)

	if (soquandich == 4)
	{
		diem += 12345678;
	}
	return diem;
}
long Board::diem_cheo2_easy(int dong, int cot)
{
	long diem = 0;
	long soquanta1 = 0;
	long soquanta2 = 0;
	long soquandich = 0;
	long so_o_trong = 0;
	long k = 0;
	//kiểm tra xuống sang trái
	for (int i = 1; i < 6 && dong + i < 18 && cot - i >= 0; i++)
	{
		if (pos[dong + i][cot - i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong + i][cot - i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong + i][cot - i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//kiem tra lên sang phải
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0 && cot + i < 24; i++)
	{
		if (pos[dong - i][cot + i].getCheck() == 1)//=1 la quaan ta;
		{
			if (k == 0)
			{
				soquanta1++;
			}
			else
			{
				soquanta2++;
			}
		}
		if (pos[dong - i][cot + i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong - i][cot + i].getCheck() == -1)
		{
			soquandich++;
			break;
		}
	}
	//xet de tan cong
	if (soquandich == 1)
	{
		diem += soquanta1 * 120 + soquanta2;	
	}
	if (soquandich == 0)
	{
		diem += soquanta1 * 129 + soquanta2;
	}
	if (soquanta1 == 4 && (so_o_trong > 0 || soquanta2 > 0))
	{
		diem += 123456789;
	}
	//kiem tra quan dich
	soquanta1 = 0;
	soquandich = 0;
	long soquandich2 = 0;
	so_o_trong = 0;
	k = 0;
	//kiểm tra sang phai
	for (int i = 1; i < 6 && dong + i < 18 && cot - i >= 0; i++)
	{
		if (pos[dong + i][cot - i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong + i][cot - i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong + i][cot - i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//kiểm lên sang phải
	k = 0;
	for (int i = 1; i < 6 && dong - i >= 0 && cot + i < 24; i++)
	{
		if (pos[dong - i][cot + i].getCheck() == -1)
		{
			if (k == 0)
			{
				soquandich++;
			}
			else
			{
				soquandich2++;
			}
		}
		if (pos[dong - i][cot + i].getCheck() == 0)
		{
			k = 1;
			so_o_trong++;
		}
		if (pos[dong - i][cot + i].getCheck() == 1)
		{
			soquanta1++;
			break;
		}
	}
	//xét phòng thủ
	if (soquanta1 == 0)
	{
		diem += soquandich * 190 + soquandich2 ;
	}
	if (soquanta1 == 1)
	{
		diem += soquandich * 100 + soquandich2 ;
	}
	if (soquandich == 4)
	{
		diem += 12345678;
	}
	return diem;
}








Board::Board()
{
	pos = new Point * [18];
	for (int i = 0; i < 18; i++)
	{
		pos[i] = new Point[24];
	}
}

Board::~Board()
{
	for (int i = 0; i < 18; i++)
	{
		delete[] pos[i];
	}
	delete[] pos;
}

