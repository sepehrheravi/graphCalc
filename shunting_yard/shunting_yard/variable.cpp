#include "variable.h"

Variable::Variable():v(NULL)
{
    //blank
}

Variable::Variable(string value):v(value)
{
    //blank
}

void Variable::Print(ostream& outs)const
{
    outs<<v;
}

int Variable::TypeOf()const
{
    return VARIABLE;
}
