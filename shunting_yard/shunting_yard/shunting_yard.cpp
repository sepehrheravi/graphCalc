#include "shunting_yard.h"

Shunting_yard::Shunting_yard()
{
   _postfix = NULL;
   //Set postfix Queue to NULL
}

Shunting_yard::Shunting_yard(Vector<Token*> infix)
{
    _postfix = _get_post_fix(infix);
    //gets the postfix form _get_post_fix func
}



Vector<Token*> Shunting_yard::postfix()
{
    return _postfix;
}


Vector<Token*> Shunting_yard::_get_post_fix(Vector<Token*> infix)
{
    //1.declare a postfix Queue
    Vector<Token*> post;

    //2.declare a stack
    Stack<Token*> s;

    //3.go through infix Queue
   for(int i=0; i<infix.get_size(); i++)
    {
        //if type of item is one of below, directly push them into
        //postfix Queue
        if(infix[i]->TypeOf() == NUMBER  ||infix[i]->TypeOf() ==
                VARIABLE)
        {
            post.push_back(infix[i]);
        }

        //if type of item is Left Paren then put it in Stack
        else if(infix[i]->TypeOf() == LPAREN)
        {
            s.push(infix[i]);
        }

        //if type is Function put it in Stack
        else if(infix[i]->TypeOf() == FUNCTION)
        {
            s.push(infix[i]);
        }

        //if type of item is operator
        else if(infix[i]->TypeOf() == OPERATOR)
        {
            //1.check to see if Stack is empty
            if(s.begin() == NULL)
            {
                s.push(infix[i]);
            }

            else
            {
                //find top of the Stack
                Token* p = s.top();

                //item from infix Queue that goes into Stack
                //we change out Token* to Operator* and call prec func
                int next = static_cast<Operator*>(infix[i])->prec();
                int prev  = 0;

                //if top of stack is Operator
                if(p->TypeOf() == OPERATOR)
                {
                    //same as next we change type of pointer to Op
                    prev = static_cast<Operator*>(p)->prec();
                }

                //if top of Stack is Function
                else if(p->TypeOf() == FUNCTION)
                {
                    //we change type of pointer to function
                    prev  = static_cast<Function*>(p)->prec();
                }


                //2.check to see if item from infix Queue that goes
                //into Stack has higher prec than top of Stack
                if(next > prev  || next == OPERATOR_POW)
                {

                   s.push(infix[i]);
                }
                else
                {
                    //if not then we pop Stack and put the popped item
                    //in postfix Queue
                    post.push_back(s.pop());
                    //then push item from infix Queue in Stack
                    s.push(infix[i]);
                }
            }
        }

        //if Type was something else(Right Paren)
        else
        {
            //locate top of the stack
            Token* p = s.top();

            //while haven't reached Left Paren
            while(p->TypeOf() != LPAREN)
            {
                if(p->TypeOf() != LPAREN)
                {
                    //pop items from Stack into postfix Queue
                    post.push_back(s.pop());
                }
                else
                {
                    s.pop();
                }

                //each time set p pointer to top of Stack
                p = s.top();
            }
            //pop last L paren
            s.pop();
        }
 }

    //at the end put all the remainings from Stack into postfix Queue
    if(s.begin() != NULL)
    {
        while(!s.empty())
        {
            post.push_back(s.pop());
        }
    }

    return post;

}








