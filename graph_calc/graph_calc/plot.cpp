#include "plot.h"

Plot::Plot(Graph_info* info):_info(info)
{
    //blank
}
Vector<sf::Vector2f> Plot::operator ()(int index)
{
    //declare a Vector of points
    Vector<sf::Vector2f> points;

    //declare a Coord_trans object
    Coord_translator c(_info);

    //declare min and max
    float max = _info->_domain.y;
    float min = _info->_domain.x;

    //declare increment
    double inc = _info->_inc;

    //declare a character array
    char str[CHAR_MAX];

    //draw g(x) if 1 passed
    if(index == 1)
    {
        strcpy(str,_info->input_g);
    }

    //draw h(x) if 2 passed
    else if(index == 2)
    {
        strcpy(str,_info->input_h);
    }

    //draw f(x) if 0 or nothing passed
    else
    {
        strcpy(str,_info->input_str);
    }

    Tokenize t;

    //Tokenize the string input and return a Vector of Token*
    Vector<Token*> infix = t.token_vec(str);

    //call Shunting_yard to give us postfix eventually
    Shunting_yard s(infix);  
    _post_fix = s.postfix();


    //start from min domain till max domain
    for(double x=min; x<= max; x+=inc)
    {
        RPN r;
        //calcualte y of each point based on x and RPN
        double y = r.eval(_post_fix,x);

        //pass the x and y to coord translate to get screend coord
        sf::Vector2f point(x,y);     
        points.push_back(c.translate(point));
    }
    return points;
}

