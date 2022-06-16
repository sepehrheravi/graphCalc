#ifndef LPAREN_H
#define LPAREN_H

#include <iostream>
#include <string>
#include "token.h"
using namespace std;
class LParen : public Token
{
public:

    void Print(ostream& outs)const;
    //Postcondition: prints the left paren
    int TypeOf()const;
    //Returns the Type of Token which in case is LPAREN=4


private:
    string l="(";
};
#endif // LPAREN_H
