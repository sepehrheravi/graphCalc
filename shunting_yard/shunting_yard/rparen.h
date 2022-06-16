#ifndef RPAREN_H
#define RPAREN_H

#include <iostream>
#include <string>
#include "token.h"
using namespace std;
class RParen : public Token
{
public:

    void Print(ostream& outs)const;
    //Postcondition: prints the right paren
    int TypeOf()const;
    //Returns the Type of Token which in case is LPAREN=3


private:
    string r=")";
};


#endif // RPAREN_H
