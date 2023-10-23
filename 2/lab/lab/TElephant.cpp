#include "TElephant.h"

int TElephant::w_count = 0;
int TElephant::b_count = 0;

TElephant::TElephant(Color color, char x, int y) : TFigure(color, x, y) {}

void TElephant::AddAtack(Board& board)
{
	if (board.board[this->x][this->y] == -5 && b_count <= 2)
	{
		bool flag = true;
		for (int i = 1; OnBoard(this->x + i, this->y + i) && flag; i++)
		{
			board.boardAtack[this->x + i][this->y + i] = 1;
			if (board.board[this->x + i][this->y + i] != 0)
				flag = false;
		}//ƒиагональ права€-верхн€€

		flag = true;
		for (int i = 1; OnBoard(this->x + i, this->y - i) && flag; i++)
		{
			board.boardAtack[this->x + i][this->y - i] = 1;
			if (board.board[this->x + i][this->y - i] != 0)
				flag = false;
		}//ƒиагональ права€-нижн€€

		flag = true;
		for (int i = 1; OnBoard(this->x - i, this->y + i) && flag; i++)
		{
			board.boardAtack[this->x - i][this->y + i] = 1;
			if (board.board[this->x - i][this->y + i] != 0)
				flag = false;
		}//ƒиагональ лева€-верхн€€

		flag = true;
		for (int i = 1; OnBoard(this->x - i, this->y - i) && flag; i++)
		{
			board.boardAtack[this->x - i][this->y - i] = 1;
			if (board.board[this->x - i][this->y - i] != 0)
				flag = false;
		}//ƒиагональ лева€-нижн€€
	}
}

void TElephant::AddFigure(Board& board)
{
	if (Empty(board))
		if (color == white && w_count < 2)
		{
			board.board[this->x][this->y] = 5;
			++w_count;
		}
		else if (color == black && b_count < 2)
		{
			board.board[this->x][this->y] = -5;
			++b_count;
		}
}

int TElephant::Count(Color color)
{
	if (color == white)
		return w_count;
	else
		return b_count;
}
