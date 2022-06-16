#ifndef VARIABLE_H
#define VARIABLE_H


#include <string>
#include "token.h"


using namespace std;

class Variable : public Token
{
public:
    Variable();
    //default CTOR
    Variable(string value);
    //CTOR for if string is put
    void Print(ostream &outs)const;
    //Postcondition: prints the variable
    int TypeOf()const;
    //Returns the Type of Token which in case is VARIABLE=8


private:
    string v;
};

#endif // VARIABLE_H
