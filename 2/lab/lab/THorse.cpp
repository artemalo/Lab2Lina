#include "THorse.h"

int THorse::w_count = 0;
int THorse::b_count = 0;

THorse::THorse(Color color, char x, int y) : TFigure(color, x, y) {}

void THorse::AddAtack(Board& board)
{
	if (OnBoard())
		if (/*board.board[this->x][this->y] == 4 && w_count <= 2 ||*/ board.board[this->x][this->y] == -4 && b_count <= 2) {
			if (OnBoard(this->x + 1, this->y + 2))
				board.boardAtack[this->x + 1][this->y + 2] = 1;
			if (OnBoard(this->x + 2, this->y + 1))
				board.boardAtack[this->x + 2][this->y + 1] = 1;
			if (OnBoard(this->x + 2, this->y - 1))
				board.boardAtack[this->x + 2][this->y - 1] = 1;
			if (OnBoard(this->x + 1, this->y - 2))
				board.boardAtack[this->x + 1][this->y - 2] = 1;
			if (OnBoard(this->x - 1, this->y - 2))
				board.boardAtack[this->x - 1][this->y - 2] = 1;
			if (OnBoard(this->x - 2, this->y - 1))
				board.boardAtack[this->x - 2][this->y - 1] = 1;
			if (OnBoard(this->x - 2, this->y + 1))
				board.boardAtack[this->x - 2][this->y + 1] = 1;
			if (OnBoard(this->x - 1, this->y + 2))
				board.boardAtack[this->x - 1][this->y + 2] = 1;
		}
}

void THorse::AddFigure(Board& board)
{
	if (Empty(board))
		if (this->color == white && w_count < 2) {
			board.board[this->x][this->y] = 4;
			++w_count;
		}
		else if (b_count < 2) {
			board.board[this->x][this->y] = -4;
			++b_count;
		}
}

int THorse::Count(Color color)
{
	if (color == white)
		return w_count;
	else
		return b_count;
}
