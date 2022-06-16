#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "../../my_vector/my_vector/my_vector.h"
#include "plot.h"
#include <cmath>
#include "graph_info.h"


class Graph
{
public:
    Graph(Graph_info* info);
    //CTOR
    void update(int &command);
    //update the graph systems calls with command
    void draw(sf::RenderWindow& window);
    //draws

private:
    Vector<sf::Vector2f> _points;
    //Vector of points

    Vector<sf::Vector2f> _gpoints;
    //Vector of points

    Vector<sf::Vector2f> _hpoints;
    //Vector of points

    Graph_info* _info;
    //object Graph_info

    Plot _plotter;
    //object Plot

};

#endif // GRAPH_H
