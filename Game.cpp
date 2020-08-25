#include "Game.h"

int Game::getCommand()
{
	return command;
}

bool Game::isContinue()
{
	return loop;
}

char Game::waitKeyBoard()
{
	command = toupper(_getch());
	return command;
}

//char Game::askContinue()
//{
//	Common::gotoXY(0, b->getY_at(H - 1, D + 4));
//	return waitKeyBoard();
//}

void Game::startGame()//có hiển thị lượt, hiển thị số lần đi của x,o
{
	system("cls");
	b->reset();
	b->drawBoard();
	x = b->getX_at(0, 0);
	y = b->getY_at(0, 0);
	if (turn == 1)
	{
		TextColor(Blue);
		signTurn(1);
		TextColor(White);
		signTurn(2);
	}
	else
	{
		TextColor(Red);
		signTurn(2);
		TextColor(White);
		signTurn(1);
	}
	TextColor(Blue);
	Common::gotoXY(33,24);
	cout << b->countX;
	TextColor(Red);
	Common::gotoXY(167,24);
	cout << b->countO;
}

void Game::exitGame()
{
	loop = false;
}

void Game::SaveGame(int n)
{
	char data[30];
	ofstream f1;
	ofstream f2;
	Common::gotoXY(80, 46);
	cout << "ENTER FILE NAME: ";
	TextColor(Cyan);
	cin.getline(data, 30);
	f1.open(data, ios::out);
	f2.open("Name.txt", ios::app);
	f2 << data << " " << endl;
	//thong tin
	f1 << scorep1 << " " << scorep2 << " " << n << endl;
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			f1 << b->getCheck_at(i,j) << " ";
		}
		f1 << endl;
	}
	f1.close();
	f2.close();
	Common::gotoXY(80, 47);
	cout << "ESC : BACK";
	int t = 1;
	while (t)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 27:
				t = 0;
				system("cls");
				ScreenStartGame(99);
				break;
			}
		}
	}
}

void Game::LoadGame(char data[30])
{

	//NHAP FILE
	ifstream f;
	f.open(data, ios::in);
	if (!f) {
		Common::gotoXY(35, 46);
		cout << "\n FILE KHONG TON TAI!" << endl;
	}
	else
	{
		f >> scorep1 >> scorep2 >> chedo;
		system("cls");
		//thong tin
		//ban co
		int k;
		for (int i = 0; i < 18; i++)
		{
			for (int j = 0; j < 24; j++)
			{
				f >> k;
				b->loadData(i, j, k);
			}
		}
		x = b->getX_at(0, 0);
		y = b->getY_at(0, 0);
		b->drawBoard();
		f.close();
	}
	TextColor(Blue);
	Common::gotoXY(33, 24);
	cout << b->countX;
	TextColor(Red);
	Common::gotoXY(167, 24);
	cout << b->countO;
	if (turn == 1)
	{
		TextColor(Blue);
		signTurn(1);
		TextColor(White);
		signTurn(2);
	}
	else
	{
		TextColor(White);
		signTurn(1);
		TextColor(Red);
		signTurn(2);
	}

}
int Game::processFinish(int x, int y)
{
	Common::gotoXY(0, b->getY_at(18 - 1, 24 - 1) + 2);
	int pWhoWin = b->testBoard(x, y);
	switch (pWhoWin)
	{
	case -1:
		system("cls");
		PrintP1Win();
		break;
	case 1:
		system("cls");
		PrintP2Win();
		break;
	case 0:
		system("cls");
		PrintDraw();
		break;
	case 2:
		turn = !turn;
	}
	Common::gotoXY(x, y);// Trả về vị trí hiện hành của con trỏ màn hình bàn cờ
	return pWhoWin;
}
bool Game::processCheckBoard()
{
	switch (b->check_XO(x, y, turn))
	{
	case -1:
		TextColor(Blue);
		cout << "X";
		Common::gotoXY(33,24);
		cout << b->countX;
		TextColor(Red);
		Common::gotoXY(167,24);
		cout << b->countO;
		TextColor(White);
		signTurn(1);
		TextColor(Red);
		signTurn(2);

		Common::gotoXY(x, y);
		break;
	case 1:
		TextColor(Red);
		cout << "O";
		TextColor(Blue);
		Common::gotoXY(33,24);
		cout << b->countX;
		TextColor(Blue);
		signTurn(1);
		TextColor(White);
		signTurn(2);
		TextColor(Red);
		Common::gotoXY(167,24);
		cout << b->countO;

		break;
	case 0:
		return false;
		break;
	}
	return true;
}
void Game::moveRight()
{
	if (x < b->getX_at(H - 1, D - 1))
	{
		x += 5;
		Common::gotoXY(x, y);
	}
}

void Game::moveLeft()
{
	if (x > b->getX_at(0, 0))
	{
		x -= 5;
		Common::gotoXY(x, y);
	}
}

void Game::moveUp()
{
	if (y > b->getY_at(0, 0))
	{
		y -= 2;
		Common::gotoXY(x, y);
	}
}

void Game::moveDown()
{
	if (y < b->getY_at(H - 1, D - 1))
	{
		y += 2;
		Common::gotoXY(x, y);
	}
}


void Game::TimKiemNuocDi()
{
	x = b->Tim_NuocDi_hard().getX();
	y = b->Tim_NuocDi_hard().getY();

}

void Game::TimKiemNuocDi2()
{
	x = b->Tim_NuocDi_easy().getX();
	y = b->Tim_NuocDi_easy().getY();
}

int Game::DemNuocCoDaDi()
{
	return b->countX + b->countO;
}

Game::Game()
{
	b = new checkBoard;
	loop = turn = true;
	command = -1;
	x = left;
	y = top;
}



Game::~Game()
{
	
}
