#include "TKing.h"

int TKing::w_count = 0;
int TKing::b_count = 0;

TKing::TKing(Color color, char x, int y) : TFigure(color, x, y) {}

void TKing::AddAtack(Board& board)
{
	if (board.board[this->x][this->y] == -7 && b_count == 1)
	{
		if (OnBoard(this->x, this->y + 1))
			board.boardAtack[this->x][this->y + 1] = 1;
		if (OnBoard(this->x + 1, this->y + 1))
			board.boardAtack[this->x + 1][this->y + 1] = 1;
		if (OnBoard(this->x + 1, this->y))
			board.boardAtack[this->x + 1][this->y] = 1;
		if (OnBoard(this->x + 1, this->y - 1))
			board.boardAtack[this->x + 1][this->y - 1] = 1;
		if (OnBoard(this->x, this->y - 1))
			board.boardAtack[this->x][this->y - 1] = 1;
		if (OnBoard(this->x - 1, this->y - 1))
			board.boardAtack[this->x - 1][this->y - 1] = 1;
		if (OnBoard(this->x - 1, this->y))
			board.boardAtack[this->x - 1][this->y] = 1;
		if (OnBoard(this->x - 1, this->y + 1))
			board.boardAtack[this->x - 1][this->y + 1] = 1;
	}
}

void TKing::AddFigure(Board& board)
{
	if (Empty(board))
		if (color == white && w_count < 1)
		{
			board.board[this->x][this->y] = 7;
			++w_count;
		}
		else if (color == black && b_count < 1)
		{
			board.board[this->x][this->y] = -7;
			++b_count;
		}
}

int TKing::Count(Color color)
{
	if (color == white)
		return w_count;
	else
		return b_count;
}
