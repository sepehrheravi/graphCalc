#include "system.h"
#include <iostream>
#include <constants.h>

System::System(Graph_info* info): _info(info), _g(_info)
{
    //blank
}
void System::Step(int &command)
{
    //call graph
    _g.update(command);

}

void System::Draw(sf::RenderWindow& window)
{
    //call draw
    _g.draw(window);

}

