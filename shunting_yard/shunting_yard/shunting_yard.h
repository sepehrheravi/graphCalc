#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "../../!includes/stack/stack.h"
#include "../../my_vector/my_vector/my_vector.h"
#include "token.h"
#include "operator.h"
#include "function.h"
#include "rparen.h"
#include "lparen.h"
#include "variable.h"
#include "number.h"
#include <cmath>


class Shunting_yard
{
public:
    Shunting_yard();
    //Default CTOR
    Shunting_yard(Vector<Token*> infix);
    //CTOR
    Vector<Token*> postfix();
    //Returns the postfix Queue

    double RPN(Vector<Token*> postfix, double x=1);
    //Precondition: use postfix Queue to calculate the answer
    //gives the final answer to equation
    //Returns double number


private:
    Vector<Token*> _postfix;
    Vector<Token*> _get_post_fix(Vector<Token*> infix);
    //Precondition:infix to change to postfix using shunting yard algo
    //Postcondition: change infix to postfix
    //Returns the postfix Queue


};



#endif // SHUNTING_YARD_H
