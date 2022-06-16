#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include "constants.h"

using namespace std;

class Token
{
public:   
    //overloading insertion operator
    friend ostream& operator <<(ostream& outs, const Token& token);

    virtual void Print(ostream& outs)const;
    //Postcondition: prints the Token
    virtual int TypeOf()const;
    //Returns the Type of Token which in case is TOKEN=-1



};

#endif // TOKEN_H
