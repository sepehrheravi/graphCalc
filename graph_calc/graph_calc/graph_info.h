#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "../../my_vector/my_vector/my_vector.h"


using namespace std;


struct Graph_info
{
    char input_str[MAX_CHAR];
    char input_g[MAX_CHAR];
    char input_h[MAX_CHAR];
    sf::Vector2f _window_dim;
    //set of window dim
    sf::Vector2f _origin;
    //origin point
    double _scale;
    //scale
    sf::Vector2f _domain;
    //domain
    double _inc;
    //increment
    int _points;
    //no of points

    Graph_info();
    //CTOR
};

#endif // GRAPH_INFO_H
