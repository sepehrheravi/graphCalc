#include "rparen.h"


void RParen::Print(ostream& outs)const
{
    outs << r;
}

int RParen::TypeOf()const
{
    return RPAREN;
}
