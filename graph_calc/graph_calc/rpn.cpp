#include "rpn.h"

double RPN::eval(Vector<Token*> postfix, double var)
{
    Stack<Token*> s;

    //fo through postfix Vector
    for (int i=0; i<postfix.get_size(); i++)
    {
        //a Token* points at each object in Vector
        Token* current = postfix[i];

        //type of Token*
        switch(current->TypeOf())
        {
        case OPERATOR:
        {

            //change current from Token* to Operator*
            Operator* op = static_cast<Operator*>(current);

            //pop the stack and set a Number* to it
            Number* rhs = static_cast<Number*>(s.pop());

            //pop the stack and set a Number* to it
            Number* lhs = static_cast<Number*>(s.pop());

            //calculate and push the number into the stack
            s.push(new Number(op->calculate(lhs->NumberOnly(),
                                            rhs->NumberOnly())));
            break;
        }

        case NUMBER:

            //if type is number just push current into Stack
            s.push(current);
            break;

        case VARIABLE:

            //push in numbers to get in place of var
            s.push(new Number(var));
            break;

        case FUNCTION:

            //change current from Token* to Function*
            Function* func = static_cast<Function*>(current);

            //calling func() to get the string inside Function*
            string f = func->func();

            //pop the stack and set a Number* to it
            Number* rhs = static_cast<Number*>(s.pop());

            //in case of max function
            if(f == "max")
            {
                //pop stack and set it to lhs
                Number* lhs = static_cast<Number*>(s.pop());

                //calculate the function and push number in Stack
                s.push(new Number(max(lhs->NumberOnly(),rhs->NumberOnly())));
            }

            //in case of min function
            else if(f == "min")
            {
                //pop stack and set it to lhs
                Number* lhs = static_cast<Number*>(s.pop());

                //calculate the function and push number in Stack
                s.push(new Number(min(lhs->NumberOnly(),rhs->NumberOnly())));

            }

            else
            {
                //calculate the function and push number in Stack
                s.push(new Number(func->calculate(rhs->NumberOnly())));
            }
            break;

        }//end of switch
    }//end of Stack

    //pop the last Number and return it
    return(static_cast<Number*>(s.pop())->NumberOnly());
}
