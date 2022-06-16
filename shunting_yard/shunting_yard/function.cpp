#include "function.h"

Function::Function():f(NULL)
{
    //blank
}

Function::Function(string value):f(value)
{
    //blank
}

void Function::Print(ostream& outs)const
{
    outs<<f;
}

int Function::TypeOf()const
{
    return FUNCTION;
}

int Function:: prec()
{
    return FUNCTION;
}

string Function::func()
{
    return f;
}

double Function::calculate(double var)
{
    if (f == "sin")
        return sin(var);

    else if (f == "cos")
        return cos(var);

    else if (f == "tan")
        return tan(var);

    else if (f == "cot")
        return 1/tan(var);

    else if (f == "abs")
        return abs(var);

    else if (f == "sqrt")
        return sqrt(var);

    else if (f == "ln")
        return log(var);

    else if (f == "log")
        return log10(var);

    else if (f == "asin")
        return asin(var);

    else if (f == "acos")
        return acos(var);

    else if (f == "atan")
        return atan(var);

    else if (f == "sinh")
        return sinh(var);

    else if (f == "cosh")
        return cosh(var);

    else if (f == "tanh")
        return tanh(var);

    else if (f == "coth")
        return cosh(var)/sinh(var);

    else if (f == "asinh")
        return asinh(var);

    else if (f == "acosh")
        return acosh(var);

    else if (f == "atanh")
        return atanh(var);

    else if (f == "sec")
        return 1/cos(var);

    else if (f == "csc")
        return 1/sin(var);

    return 0;
}
