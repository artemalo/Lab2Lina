#pragma once
#include "TFigure.h"
class TQueen :
    public TFigure
{
private:
    static int w_count;
    static int b_count;
public:
    TQueen(Color, char, int);
    void AddAtack(Board&) override;
    void AddFigure(Board&) override;
    int Count(Color) override;
};