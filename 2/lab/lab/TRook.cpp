#include "TRook.h"

int TRook::w_count = 0;
int TRook::b_count = 0;

TRook::TRook(Color color, char x, int y) : TFigure(color, x, y) {}

void TRook::AddAtack(Board& board)
{
	if (board.board[this->x][this->y] == -3 && b_count <= 2)
	{
		bool flag = true;
		for (int i = 1; OnBoard(this->x, this->y + i) && flag; ++i)
		{
			board.boardAtack[this->x][this->y + i] = 1;
			if (board.board[this->x][this->y + i] != 0)
				flag = false;
		}//Верх
		flag = true;
		for (int i = 1; OnBoard(this->x + i, this->y) && flag; ++i)
		{
			board.boardAtack[this->x + i][this->y] = 1;
			if (board.board[this->x + i][this->y] != 0)
				flag = false;
		}//Вправо
		flag = true;
		for (int i = 1; OnBoard(this->x, this->y - i) && flag; ++i)
		{
			board.boardAtack[this->x][this->y - i] = 1;
			if (board.board[this->x][this->y - i] != 0)
				flag = false;
		}//Вниз
		flag = true;
		for (int i = 1; OnBoard(this->x - i, this->y) && flag; ++i)
		{
			board.boardAtack[this->x - i][this->y] = 1;
			if (board.board[this->x - i][this->y] != 0)
				flag = false;
		}//Влево
	}
}

void TRook::AddFigure(Board& board)
{
	if (Empty(board))
		if (color == white && w_count < 2) {
			board.board[this->x][this->y] = 3;
			++w_count;
		}
		else if (color == black && b_count < 2) {
			board.board[this->x][this->y] = -3;
			++b_count;
		}
}

int TRook::Count(Color color)
{
	if (color == white)
		return w_count;
	else
		return b_count;
}