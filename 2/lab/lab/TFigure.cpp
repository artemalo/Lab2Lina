#include "TFigure.h"

int TFigure::w_count = 0;//test
int TFigure::b_count = 0;//test

TFigure::TFigure(Color color, char x, int y)
{
	this->color = color;
	this->x = x - 'a';
	this->y = y - 1;
	//if (!OnBoard()) TFigure::~TFigure();
	if (color == white) ++w_count;
	else ++b_count;
}

bool TFigure::OnBoard()
{
	return (this->x >= 0 && this->x < LEN) && (this->y >= 0 && this->y < LEN);
}
bool TFigure::OnBoard(int x, int y)
{
	return (x >= 0 && x < LEN) && (y >= 0 && y < LEN);
}

bool TFigure::Empty(Board& board)
{
	if (OnBoard())
	{
		return board.board[this->x][this->y] == NULL;
	}
	return false;
}

bool TFigure::Empty(Board& board, char x, int y)
{
	int intX = x - 'a';
	y--;
	if (board.board[intX][y] == NULL)
		return true;
	return false;
}

int TFigure::Count(Color color)
{
	if (color == white) return w_count;
	else return b_count;
}

void TFigure::AddAtack(Board&) {}

void TFigure::AddFigure(Board&) {}