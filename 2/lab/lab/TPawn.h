#include "TFigure.h"
#pragma once
class TPawn :
    public TFigure
{
private:
    static int w_count;
    static int b_count;
public:
    TPawn(Color, char, int);
    void AddAtack(Board&) override;
    void AddFigure(Board&) override;
    int Count(Color) override;

};