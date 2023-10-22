#include "TFigure.h"
#pragma once
class TPawn :
    public TFigure
{
public:
    TPawn(Color, char, int);
    void AddFigure();

};