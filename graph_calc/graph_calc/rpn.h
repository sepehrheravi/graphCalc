#ifndef RPN_H
#define RPN_H
#include "../../shunting_yard/shunting_yard/shunting_yard.h"


class RPN
{
public:
    double eval(Vector<Token*> postfix, double var);
    //get the postfix Vectro
    //get the variable
    //Returns final number
};

#endif // RPN_H
