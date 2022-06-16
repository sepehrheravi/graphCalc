#include "coord_translator.h"


Coord_translator::Coord_translator(Graph_info* info):_info(info)
{
    //blank
}
sf::Vector2f Coord_translator::translate(sf::Vector2f point)
{
    //get the origin info
    float ox = _info->_origin.x;
    float oy = _info->_origin.y;

    //scale for each pixel
    double scale =
            (WORK_PANEL)/ (_info->_domain.y - _info->_domain.x);
    sf::Vector2f trans_point;

    //calculate the point x and y based on scale
    // -Points because the center if circle drawn
    trans_point =
            sf::Vector2f(ox+scale*(point.x)-POINT,
                         oy-scale*(point.y)-POINT);
    return trans_point;

}
