#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "../../!includes/queue/queue.h"
#include "../../shunting_yard/shunting_yard/shunting_yard.h"

using namespace std;
class Tokenize
{
public:
    Tokenize();
    //CTOR

//    Tokenize(char* c);
//    Tokenize(string s);
//    void set_string(char* c);

    Vector<Token*> token_vec(char str[]);
    //get the char array
    //Returns infix

private:
    char* pch;
};

#endif // TOKENIZE_H
