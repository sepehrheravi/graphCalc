#include "test_shuntin_yard.h"



void test_shunting_yard_function()
{
    Queue<Token*> infix;




//    infix.push(new Number(3));
//    infix.push(new Operator("*"));
//    infix.push(new Function("sin"));
//    infix.push(new LParen);
//    infix.push(new Variable("x"));
//    infix.push(new Operator("^"));
//    infix.push(new Number(2));
//    infix.push(new RParen);

//    infix.push(new Variable("x"));
//    infix.push(new Operator("*"));
//    infix.push(new Function("cos"));
//    infix.push(new LParen);
//    infix.push(new Number("1"));
//    infix.push(new Operator("/"));
//    infix.push(new Variable("x"));
//    infix.push(new RParen);

    infix.push(new Function("sin"));
    infix.push(new LParen);
    infix.push(new Function("max"));
    infix.push(new LParen);
    infix.push(new Number(2));
    infix.push(new Number(3));
    infix.push(new RParen);
    infix.push(new Operator("/"));
    infix.push(new Number(3));
    infix.push(new Operator("*"));
    infix.push(new Variable("π"));
    infix.push(new RParen);






    Shunting_yard s(infix);
    cout << endl;
    cout << "Infix:" << endl;
    print(infix);
    cout << endl;
    cout << endl;
    cout << "Postfix: " << endl;
    print(s.postfix());
    cout << endl;
    cout << endl;

}
void test_shunting_yard_RPN()
{
    Queue<Token*> infix;

//    infix.push(new Number(3));
//    infix.push(new Operator("+"));
//    infix.push(new Number(5));
//    infix.push(new Operator("*"));
//    infix.push(new Number(2));
//    infix.push(new Operator("^"));
//    infix.push(new Number(4));





//    infix.push(new Number(3));
//    infix.push(new Operator("/"));
//    infix.push(new LParen);
//    infix.push(new Number(5));
//    infix.push(new Operator("-"));
//    infix.push(new LParen);
//    infix.push(new Number(6));
//    infix.push(new Operator("+"));
//    infix.push(new Number(7));
//    infix.push(new RParen);
//    infix.push(new Operator("/"));
//    infix.push(new LParen);
//    infix.push(new Number(2));
//    infix.push(new Operator("+"));
//    infix.push(new Number(8));
//    infix.push(new Operator("*"));
//    infix.push(new Number(4));
//    infix.push(new RParen);
//    infix.push(new RParen);
//    infix.push(new Operator("*"));
//    infix.push(new Number(9));

//    infix.push(new Number(3));
//    infix.push(new Operator("*"));
//    infix.push(new LParen);
//    infix.push(new Number(2));
//    infix.push(new Operator("*"));
//    infix.push(new Number(3));
//    infix.push(new RParen);
//    infix.push(new Operator("^"));
//    infix.push(new Variable("x"));

//    infix.push(new Function("sin"));
//    infix.push(new Number("90"));

//    infix.push(new LParen);
//    infix.push(new Number(1));
//    infix.push(new Operator("/"));
//    infix.push(new Variable("x"));
//    infix.push(new RParen);
//    infix.push(new Operator("^"));
//    infix.push(new Number(3));


    Shunting_yard s(infix);
    cout << endl;
    cout << "Infix:" << endl;
    print(infix);
    cout << endl;
    cout << endl;
    cout << "Postfix: " << endl;
    print(s.postfix());
    cout << endl;
    cout << endl;

    cout << "RPN: " << endl;
    cout <<  s.RPN(s.postfix()) << endl;
    cout << endl;
}
