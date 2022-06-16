#ifndef FUNCTION_H
#define FUNCTION_H


#include <string>
#include "token.h"
#include "operator.h"
#include <cmath>
#include <cassert>


using namespace std;

class Function : public Token
{
public:
    Function();
    //default CTOR
    Function(string value);
    //CTOR for if string is put
    int prec();
    //Return the precedence of function
    void Print(ostream &outs)const;
    //Postcondition: prints the function
    int TypeOf()const;
    //Returns the Type of Token which in case is FUNCTION=10
    string func();

    double calculate(double var);
    //Returns the calculated number

private:
    string f;
};

#endif // FUNCTION_H
