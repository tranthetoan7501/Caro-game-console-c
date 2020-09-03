#pragma once
#include "Point.h"
#define top 9
#define left 42
#define D 24
#define H 18
//top : bắt đầu tọa độ trên bàn cờ, left bắt đầu của tọa độ bàn cờ từ trái, D số ô ngang, H số ô đứng
class Board {
private:

	Point** pos;// lưu giữ tọa độ x,y,check vào từng ô trong mãng tương đương từng ô trên bàn cờ
public:
	int getX_at(int i, int j);
	int getY_at(int i, int j);
	int getCheck_at(int i, int j);
	void loadData(int, int, int);// Đọc bàn cờ đã lưu vào mãng, dòng trong phần load game
	void reset();// cho bàn cờ trả về ô trống
	void drawBoard();// vẽ bàn cờ
	int check_XO(int x, int y, int turn);//kiểm tra tại ô đó là x hay o
	int testBoard(int x, int y);//kiểm tra thắng thua
	
	
	Point Tim_NuocDi_easy(); // Tìm nước đi cho máy dễ, xét ít điều kiện if else hơn
	long diem_ngang_easy(int, int);
	long diem_doc_easy(int, int);
	long diem_cheo1_easy(int, int);
	long diem_cheo2_easy(int, int);

	Point Tim_NuocDi_hard(); // Tìm nước đi cho máy khó,  xét nhiều điều kiện if else hơn
	long diem_ngang_hard(int, int);
	long diem_doc_hard(int, int);
	long diem_cheo1_hard(int, int);
	long diem_cheo2_hard(int, int);

	// kiểm tra thắng thua
	int checkWinRow(int x, int y, int value);
	int checkWinCol(int x, int y, int value);
	int checkfirstDiagonal(int x, int y, int value);
	int checksecondDiagonal(int x, int y, int value);
	Board();
	~Board();
	// đếm số quân X, số quân O
	int countX;
	int countO;

};
