#ifndef COORD_TRANSLATOR_H
#define COORD_TRANSLATOR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../my_vector/my_vector/my_vector.h"
#include <constants.h>
#include <graph_info.h>


class Coord_translator
{
public:
    Coord_translator(Graph_info* info);
    //CTOR
    sf::Vector2f translate(sf::Vector2f point);
    //translates each point

private:
    Graph_info* _info;

};

#endif // COORD_TRANSLATOR_H
