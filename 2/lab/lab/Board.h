#include <iostream>
#define LEN 8
#pragma once
class Board
{
	friend class TFigure;
	friend class TPawn;
	friend class THorse;
	friend class TQueen;
private:
	bool boardAtack[LEN][LEN];
	int board[LEN][LEN];
//protected:
//	virtual void AddAtack(Board*);
//	virtual void AddFigure(Board*);
public:
	Board();
	void PrintBoardAtack();
	void PrintBoard();
};