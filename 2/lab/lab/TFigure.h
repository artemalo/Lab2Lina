#pragma once
#include "Board.h"

enum Color {
	white,
	black
};

class TFigure
	//public Board
{
protected:
	int x, y;
	Color color;
public:
	TFigure(Color, char, int);
	virtual bool OnBoard();
	virtual bool Empty(Board*);
	virtual int Count();
	virtual void mapStep(bool*);
	~TFigure();
};