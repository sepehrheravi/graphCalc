#ifndef SYSTEM_H
#define SYSTEM_H

#include <SFML/Graphics.hpp>
#include "graph.h"
#include "graph_info.h"

using namespace std;
class System
{
public:
    System(Graph_info* info);
    //CTOR
    void Step(int &command);
    //calls graph update
    void Draw(sf::RenderWindow& widnow);
    //calls graph draw
private:
    Graph_info* _info;
    Graph _g;

};

#endif // SYSTEM_H
