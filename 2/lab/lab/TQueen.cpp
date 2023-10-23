#include "TQueen.h"

int TQueen::w_count = 0;
int TQueen::b_count = 0;

TQueen::TQueen(Color color, char x, int y) : TFigure(color, x, y) {}

void TQueen::AddAtack(Board& board)
{
	if (/*board.board[this->x][this->y] == 6 && w_count == 1 ||*/ board.board[this->x][this->y] == -6 && b_count == 1)
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

		flag = true;
		for (int i = 1; OnBoard(this->x, this->y + i) && flag; ++i)
		{
			board.boardAtack[this->x][this->y + i] = 1;
			if (board.board[this->x][this->y + i] != 0)
				flag = false;
		}//¬ерх
		flag = true;
		for (int i = 1; OnBoard(this->x + i, this->y) && flag; ++i)
		{
			board.boardAtack[this->x + i][this->y] = 1;
			if (board.board[this->x + i][this->y] != 0)
				flag = false;
		}//¬право
		flag = true;
		for (int i = 1; OnBoard(this->x, this->y - i) && flag; ++i)
		{
			board.boardAtack[this->x][this->y - i] = 1;
			if (board.board[this->x][this->y - i] != 0)
				flag = false;
		}//¬низ
		flag = true;
		for (int i = 1; OnBoard(this->x - i, this->y) && flag; ++i)
		{
			board.boardAtack[this->x - i][this->y] = 1;
			if (board.board[this->x - i][this->y] != 0)
				flag = false;
		}//¬лево
	}
}

void TQueen::AddFigure(Board& board)
{
	if (Empty(board))
		if (color == white && w_count < 1) {
			board.board[this->x][this->y] = 6;
			++w_count;
		}
		else if (color == black && b_count < 1) {
			board.board[this->x][this->y] = -6;
			++b_count;
		}

}

int TQueen::Count(Color color)
{
	if (color == white)
		return w_count;
	else
		return b_count;
}
