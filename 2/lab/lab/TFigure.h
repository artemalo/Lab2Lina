#pragma once
#include "Board.h"

enum Color {
	white,
	black
};

class TFigure
{
private:
	static int w_count;
	static int b_count;
protected:
	int x, y;
	Color color;
public:
	TFigure(Color, char, int);
	virtual bool OnBoard();
	virtual bool OnBoard(int x, int y);
	virtual bool Empty(Board&);
	virtual int Count(Color color);
	virtual void AddAtack(Board&);
	virtual void AddFigure(Board&);
	~TFigure();
};