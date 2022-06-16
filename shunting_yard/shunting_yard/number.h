#ifndef NUMBER_H
#define NUMBER_H


#include <iostream>
#include <string>
#include "token.h"
using namespace std;
class Number : public Token
{
public:
    Number();
    //default CTOR
    Number(double value);
    //CTOR for if double is put
    Number(string value);
    //CTOR for if string is put
    void Print(ostream& outs)const;
    //Postcondition: prints the number
    int TypeOf()const;
    //Returns the Type of Token which in case is NUMBER=1
    double NumberOnly();
    //Returns the double number

private:
    double n;
};

#endif // NUMBER_H
