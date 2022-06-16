#include "lparen.h"

void LParen::Print(ostream& outs)const
{
    outs << l;
}

int LParen::TypeOf()const
{
    return LPAREN;
}


