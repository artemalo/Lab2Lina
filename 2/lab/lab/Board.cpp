#include "Board.h"

Board::Board()
{
	for (int i = 0; i < LEN; i++)
	{
		for (int j = 0; j < LEN; j++)
		{
			boardAtack[i][j] = 0;
			board[i][j] = 0;
		}
	}
}

void Board::AddAtack()
{
}

void Board::AddFigure()
{
	std::cout << "add";
}

void Board::PrintBoardAtack()
{
}

void Board::PrintBoard()
{
}
