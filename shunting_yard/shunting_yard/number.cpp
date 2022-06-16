#include "number.h"

Number::Number():n(0)
{
    //blank
}

Number::Number(double value):n(value)
{
    //blank
}

Number::Number(string value)
{
    n = atof(value.c_str());
    //turns string digit to double
}

void Number::Print(ostream& outs)const
{
    outs<<n;
}

int Number::TypeOf()const
{
    return NUMBER;
}

double Number::NumberOnly()
{
    return n;
}
