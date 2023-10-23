#include <fstream>
#include <map>
#include <vector>

#include "TFigure.h"
#include "TPawn.h"
#include "TRook.h"
#include "THorse.h"
#include "TElephant.h"
#include "TQueen.h"
#include "TKing.h"

#define MAX 32
#define filename "figures.txt"

using namespace std;

int main()
{
	ifstream f(filename);
	if (!f.is_open()) {
		cout << "ERROR " << filename;
		return 1;
	}

	string type; string text; char x; int y;

	map<string, enum Color> w_or_b;
	w_or_b["white"] = Color::white;
	w_or_b["black"] = Color::black;

	vector<TFigure*> figures;
	while (f >> type >> text >> x >> y)
	{
		TFigure* piece = nullptr;
		Color color = w_or_b[text];
		cout << type << " " << color << " " << x << " " << y << endl;
		if (type == "Pawn")
			piece = new TPawn(color, x, y);
		else if (type == "Rook")
			piece = new TRook(color, x, y);
		else if (type == "Horse")
			piece = new THorse(color, x, y);
		else if (type == "Elephant")
			piece = new TElephant(color, x, y);
		else if (type == "Queen")
			piece = new TQueen(color, x, y);
		else if (type == "King" && color == black)
			piece = new TKing(color, x, y);
		if (piece)
		{
			figures.push_back(piece);
		}
	}
	f.close();

	Board board;

	/*for (TFigure* piece : figures)
	{
		piece->AddFigure(board);
		piece->AddAtack(board);
	}*/
	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->AddFigure(board);
	}

	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->AddAtack(board);
	}

	do
	{
		cout << "White king (x, y): ";
		cin >> x >> y;
	} while (!figures[0]->Empty(board, x, y));
	TKing WKing(white, x, y);
	WKing.AddFigure(board);

	board.PrintBoard();

	cout << endl;

	board.PrintBoardAtack();

	cout << endl;

	WKing.Situation(board);

	/*for (TFigure *piece:figures)
	{
		delete piece;
	}*/
	for (int i = 0; i < figures.size(); i++)
	{
		delete figures[i];
	}
}