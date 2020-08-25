#pragma once
#include "Point.h"
#include "Common.h"
#include "Board.h"
#include "Game.h"

#define SIZE			16   // SIZE BÀN CỜ 
#define Black			0
#define DarkBlue		1
#define DarkGreen		2
#define DarkCyan		3
#define DarkRed			4
#define DarkPink		5
#define DarkYellow		6
#define DarkWhite		7
#define Grey			8
#define Blue			9
#define Green			10
#define Cyan			11
#define Red				12
#define Pink			13
#define Yellow			14
#define White			15
#define defaultColor		7 
// MẶC ĐỊNH CÁC MÀU CƠ BẢN
struct Diem
{
	int score1;
	int score2;
};
// Tỉ số thắng thua 

int ReadChedo(char a[30]); // Đọc chế độ chơi
void ReadNameFile();  // Đọc tên các file đã lưu
void LogoGame1();
void LogoGame2();
void PrintP1Win();
void PrintP2Win();
void PrintDraw();
void TaoKhung(int);
void Screen();
void signTurn(int);
// In chữ CARO 
void TextColor(int n); // Đổi màu kí tự 
void AnTroChuot();    // Ẩn trỏ chuột
void HienTroChuot();  // Hiện trỏ chuột
void ScreenStartGame(int n); // Menu Chính
int VsPlayer(Diem& a, int, char data[30]);
int VsComHard(Diem& a, int, char data[30]); // 29 hard
int VsComEasy(Diem& a, int, char data[30]); // 27 easy

void Help(); // Help
void About(); // About 

void LoadLoad();
