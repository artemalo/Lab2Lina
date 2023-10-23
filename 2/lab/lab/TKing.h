#pragma once
#include "TFigure.h"
class TKing :
    public TFigure
{
private:
    static int w_count;
    static int b_count;
public:
    TKing(Color, char, int);
    void AddAtack(Board&) override;
    void AddFigure(Board&) override;
    int Count(Color) override;
    void Situation(Board&);
};