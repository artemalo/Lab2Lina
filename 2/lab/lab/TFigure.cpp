#include "TFigure.h"

TFigure::TFigure(Color color, char x, int y)
{
	this->color = color;
	this->x = x - 'a';
	this->y = y - 1;
	//if (!OnBoard()) TFigure::~TFigure();
}

bool TFigure::OnBoard()
{
	return (this->x >= 0 && this->x < LEN) && (this->y >= 0 && this->y < LEN);
}

bool TFigure::Empty(Board*)
{
	return false;
}

int TFigure::Count()
{
	return 0;
}

void TFigure::mapStep(bool*)
{

}

TFigure::~TFigure()
{
}
