#include "graph_info.h"

Graph_info::Graph_info()
{
    strcpy(input_str,"sin ( 1 / x )");
    strcpy(input_g,"");
    strcpy(input_h,"");
    _window_dim = sf::Vector2f(0,0);
    _origin = sf::Vector2f(0,0);
    _domain = sf::Vector2f(0,0);
    _inc = 0;
    _points = 0;
    _scale = 0;
}


