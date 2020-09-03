#pragma once
#include "Board.h"
#include "Point.h"
#include "Common.h"
#include "Play.h"
#include <Windows.h>
#include <fstream>

class Game
{
	Board* b;		
	bool turn;//lượt true lượt người chơi 1, false là lượt người chơi 2		
	int x, y;		
	int command; //Nhận phím
	bool loop;	 //True tiếp, false thoát
	int scorep1; // điểm người chơi 1
	int scorep2; // điểm người chơi 2
	int chedo;   // biến dùng trong phần load game
	// -31 : Chế độ P vs P đang đến lượt X
	// -30 : Chế độ P vs P đang đến lượt O
	// -4  : Chế độ P vs Bot (Dễ ) đang đến lượt X
	// -5  : Chế độ P vs Bot (Khó ) đang đến lượt X
	
public:
	void setCountXY() {
		b->countX = 0;
		b->countO = 0;
	}
	
	int getChedo() { return chedo; }
	// lấy chế độ
	int getScore1() { return scorep1; }
	int getScore2() { return scorep2; }
	//lấy điểm của người chơi 1 người chơi 2
	
	void setScore1() { scorep1 = 0; }
	void setScore2() { scorep2 = 0; }
	
	int getCommand();
	void setCommand(int x) { command = x; }
	//hàm get set giá trị nhận từ phím
	bool isContinue();
	//Tiếp tục trò chơi
	char waitKeyBoard();
	//Nhận phím
	//char askContinue();
	// dừng hay chơi tiếp
	

public:
	void startGame(); // Khởi tạo game . Bắt đầu game 
	void exitGame(); // Thoát Game
	void SaveGame(int n);  // Lưu Game đang chơi với biến n là chế độ và lượt .
	void LoadGame(char data[30]); // Khởi tạo game . Bắt đầu game ( trường hợp Load Game ) 
public:
	int processFinish(int x, int y);
	// Kiểm tra thắng thua - tiếp tục
	bool processCheckBoard();
	// Đánh dấu X và O trên bàn cờ
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	// Di chuyển lên - xuống - trái - phải
	void setX(int a) { x = a; }
	void setY(int b) { y = b; }
	// Cài đặt biến _x _y 
	int getXatEnter() { return x; }
	int getYatEnter() { return y; }
	// Lấy giá trị _x _y 
	bool getTurn() { return turn; }
	// Lấy giá trị của lượt chơi .
	void setTurn() { turn = !turn; }
	// Đảo lượt chơi
	void TimKiemNuocDi();
	void TimKiemNuocDi2();
	// Tìm kiếm nước đi cho máy
	int DemNuocCoDaDi();
	// Đếm nước cờ đã đi được
public:
	Game();
	~Game();
};

