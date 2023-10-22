#include "TFigure.h"
#include "TPawn.h"
#define MAX 32

using namespace std;

int main()
{
	Board board;

	TPawn bPawn1(black, 'a', 1);
	TPawn wPawn2(white, 'a', 2);
	TPawn wPawn3(white, 'a', 3);
	TPawn wPawn4(white, 'a', 1);//!!!!!!!!!!
	TPawn bPawn5(black, 'g', 4);

	//====================
	TFigure* figures[MAX];
	//-Инициализация
	for (int i = 0; i < MAX; i++)
		figures[i] = NULL;
	//-
	figures[0] = &bPawn1;
	figures[1] = &wPawn2;
	figures[2] = &wPawn3;
	figures[3] = &wPawn4;
	figures[4] = &bPawn5;
	//====================

	for (int i = 0; i < MAX && figures[i] != NULL; i++)
	{
			figures[i]->AddFigure(board);
			figures[i]->AddAtack(board);
	}
	
	cout << bPawn1.Count(black) << " - Black Pawn" << endl;
	cout << bPawn1.Count(white) << " - White Pawn" << endl;

	board.PrintBoard();

	cout << endl;

	board.PrintBoardAtack();
}