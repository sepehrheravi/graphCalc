#include "token.h"

ostream& operator <<(ostream& outs, const Token& token)
{
    token.Print(outs);
    return outs;
}

void Token::Print(ostream &outs)const
{
    outs<<"TOKEN Print: DON't ^%#$# call me again!"<<endl;

}

int Token::TypeOf()const
{
    return TOKEN;
}
