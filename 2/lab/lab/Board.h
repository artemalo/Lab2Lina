#include <iostream>
#define LEN 8
#pragma once
class Board
{
private:
	bool boardAtack[LEN][LEN];
	int board[LEN][LEN];
protected:
	virtual void AddAtack();
	virtual void AddFigure();
public:
	Board();
	void PrintBoardAtack();
	void PrintBoard();
};