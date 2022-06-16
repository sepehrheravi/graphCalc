#ifndef PLOT_H
#define PLOT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "../../my_vector/my_vector/my_vector.h"
#include "../../shunting_yard/shunting_yard/shunting_yard.h"
#include "rpn.h"
#include <cmath>
#include "coord_translator.h"
#include "graph_info.h"
#include "tokenize.h"

class Plot
{
public:
    Plot(Graph_info* info);
    //CTOR
    Vector<sf::Vector2f> operator ()(int index = 0);
    //index defines which graph to draw
    //Returns a Vector of points after translating them
private:
   Graph_info* _info;
   Vector<Token*> _post_fix;
};

#endif // PLOT_H
