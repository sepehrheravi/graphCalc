#include "operator.h"

Operator::Operator():o(NULL),_prec(0)
{
    //blank
}


Operator::Operator(string value):o(value)
{
    //based on string operator return that Operator prec
    if(o == "*")
    {
        _prec = OPERATOR_MULT;
    }
    else if(o == "/")
    {
        _prec = OPERATOR_DIV;
    }
    else if(o == "+")
    {
        _prec = OPERATOR_ADD;
    }
    else if(o == "-")
    {
        _prec = OPERATOR_SUB;
    }
    else if(o == "^")
    {
        _prec = OPERATOR_POW;
    }
}

void Operator::Print(ostream& outs)const
{
    outs<<o;
}

int Operator::TypeOf()const
{
    return OPERATOR;
}

string Operator::op()
{
    return o;
}

int Operator::prec()
{    
    return _prec;
}

double Operator::calculate(double lhs, double rhs)
{

    if(o == "+")
        return lhs + rhs;

    else if(o == "-")
        return lhs - rhs;

    else if(o == "*")
        return lhs * rhs;

    else if(o == "/")
        return lhs / rhs;

    else if(o == "^")
        return pow(lhs, rhs);

    return 0;
}


