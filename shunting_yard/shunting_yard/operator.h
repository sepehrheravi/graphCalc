#ifndef OPERATOR_H
#define OPERATOR_H


#include <iostream>
#include <string>
#include "token.h"
#include <cmath>
using namespace std;
class Operator : public Token
{
public:
    Operator();
    //default CTOR
    Operator(string value);
    //CTOR for if string is put
    void Print(ostream& outs)const;
    //Postcondition: prints the operator
    int TypeOf()const;
    //Returns the Type of Token which in case is OPERATOR=2
    string op();
    //Returns the operator type
    int prec();
    //Return the precedence of operator

    double calculate(double lhs, double rhs);
    //Returns the calculated number





private:
    string o;
    int _prec;
};

#endif // OPERATOR_H
