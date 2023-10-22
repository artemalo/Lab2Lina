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

void Board::PrintBoardAtack()
{
	int k = LEN - 1;
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			std::cout << boardAtack[j][k] << "   ";
		}
		--k;
		std::cout << '\n';
	}
}

void Board::PrintBoard()
{
	int k = LEN - 1;
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			std::cout << board[j][k] << "   ";
		}
		--k;
		std::cout << '\n';
	}
}
