#include "tokenize.h"

Tokenize::Tokenize():pch(NULL)
{

}

Vector<Token*> Tokenize:: token_vec(char str[])
{
    bool paren = false;

//    const bool debug=true;
    bool unary =false;
//    if (debug)
//    {
//        cout<<"token_vec: str: "<<str<<endl;
//    }
    Vector<Token*> infix;
     pch = strtok (str," ,.");
     if(*pch == '-')
     {
        infix.push_back(new Number(-1));
        infix.push_back(new Operator("*"));
        infix.push_back(new LParen);
        unary = true;
        pch = strtok (NULL," ,.");
     }

    while (pch != NULL)
    {
        string l = "-";
        if(pch == l && paren)
        {
            infix.push_back(new Number(-1));
            infix.push_back(new Operator("*"));
            paren = false;
        }
        else if(pch == l)
        {
            infix.push_back(new Operator("-")); //for minus;
        }

        //for unary in the middle like ( x + (-sinx))
        //I have to write -> (x+(-1*sinx))
        else if(isdigit(*pch) || *pch == '-' )
        {

            infix.push_back(new Number(pch));
        }
        else
        {
            if(strlen(pch) != 1)
            {
                infix.push_back(new Function(pch));
            }
            else
            {
                if(*pch == '(')
                {
                    infix.push_back(new LParen);
                    paren = true;

                }
                else if(*pch == ')')
                {
                    infix.push_back(new RParen);
                }
                else if(*pch == 'x')
                {
                    infix.push_back(new Variable(pch));
                }
                else
                {
                    infix.push_back(new Operator(pch));
                }
            }
        }

        pch = strtok (NULL, " ,.");
    }

    if(unary)
    {
        infix.push_back(new RParen);
    }

//    if (debug)
//    {
//        cout << "token_vec: infix is: " << infix << endl;
//    }
//    for(int i = 0; i<infix.get_size(); i++)
//    {
//        Token* t = infix[i];
//        cout << *t << endl;
//    }

    return infix;
}
