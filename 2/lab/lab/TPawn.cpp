#include "TPawn.h"

int TPawn::w_count = 0;
int TPawn::b_count = 0;

TPawn::TPawn(Color color, char x, int y) : TFigure(color, x, y) {}

void TPawn::AddAtack(Board& board)
{
	if(OnBoard())
		/*if (board.board[this->x][this->y] == 2 && w_count <= LEN) {
			if (OnBoard(this->x + 1, this->y + 1))
				board.boardAtack[this->x + 1][this->y + 1] = 1;
			if (OnBoard(this->x - 1, this->y + 1))
				board.boardAtack[this->x - 1][this->y + 1] = 1;
		}
		else {*/
			if (board.board[this->x][this->y] == -2 && b_count <= LEN) {
				if (OnBoard(this->x - 1, this->y - 1))
					board.boardAtack[this->x - 1][this->y - 1] = 1;
				if (OnBoard(this->x + 1, this->y - 1))
					board.boardAtack[this->x + 1][this->y - 1] = 1;
			}
		//}
}

void TPawn::AddFigure(Board& board)
{
	if (Empty(board))
		if (this->color == white && w_count < LEN) {
			board.board[this->x][this->y] = 2;
			++w_count;
		}
		else if (b_count < LEN) {
			board.board[this->x][this->y] = -2;
			++b_count;
		}
}

int TPawn::Count(Color color) 
{
	if (color == white) return w_count;
	else return b_count;
}