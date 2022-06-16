#include "graph.h"


Graph::Graph(Graph_info* info): _info(info), _plotter(_info)
{

}
void Graph::update(int &command)
{
    //zoom out
    if(command == ZOOM_OUT)
    {
        //set domain
        _info->_domain = sf::Vector2f(_info->_domain.x*ZOOM,
                                      _info->_domain.y*ZOOM);
        //plot
        _points = _plotter();

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_g,"") != 0)
        {
            _gpoints = _plotter(1);
        }

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_h,"") != 0)
        {
            _hpoints = _plotter(2);
        }
    }

    //zoom in
    else if(command == ZOOM_IN)
    {
        //set domain
        _info->_domain = sf::Vector2f(_info->_domain.x/ZOOM,
                                      _info->_domain.y/ZOOM);
        //plot
        _points = _plotter();

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_g,"") != 0)
        {
            _gpoints = _plotter(1);
        }

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_h,"") != 0)
        {
            _hpoints = _plotter(2);
        }
    }

    //Reset and draw
    else if(command == DRAW_N_RESET)
    {
        //set domain to default
        _info->_domain = sf::Vector2f(MIN_DOM,MAX_DOM);

        //set origin default
        float ox = (SCREEN_WIDTH-SIDE_BAR)/2;
        float oy = (SCREEN_HEIGHT)/2;
        _info->_origin = sf::Vector2f(ox,oy);

        //plot
        _points = _plotter();

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_g,"") != 0)
        {
            _gpoints = _plotter(1);
        }

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_h,"") != 0)
        {
            _hpoints = _plotter(2);
        }
    }

    //left
    else if(command == PAN_LEFT)
    {
        //set domain
        _info->_domain = sf::Vector2f(_info->_domain.x-1,
                                      _info->_domain.y-1);

        //find scale
        double scale = (WORK_PANEL)/
                (_info->_domain.y - _info->_domain.x);

        //set origin
        _info->_origin.x = _info->_origin.x + scale;

        //plot
        _points = _plotter();

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_g,"") != 0)
        {
            _gpoints = _plotter(1);
        }

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_h,"") != 0)
        {
            _hpoints = _plotter(2);
        }
    }

    //right
    else if(command == PAN_RIGHT)
    {
        _info->_domain = sf::Vector2f(_info->_domain.x+1,
                                      _info->_domain.y+1);

        //find scale
        double scale = (WORK_PANEL)/
                (_info->_domain.y - _info->_domain.x);

        //set origin
        _info->_origin.x = _info->_origin.x - scale;

        //plot
        _points = _plotter();

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_g,"") != 0)
        {
            _gpoints = _plotter(1);
        }

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_h,"") != 0)
        {
            _hpoints = _plotter(2);
        }
    }

    //up
    else if(command == PAN_UP)
    {
        //set scale
        double scale = (WORK_PANEL)/
                (_info->_domain.y - _info->_domain.x);

        //set origin
        _info->_origin.y = _info->_origin.y + scale;

        //plot
        _points = _plotter();

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_g,"") != 0)
        {
            _gpoints = _plotter(1);
        }

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_h,"") != 0)
        {
            _hpoints = _plotter(2);
        }
    }

    //down
    else if(command == PAN_DOWN)
    {
        //find scale
        double scale = (WORK_PANEL)/
                (_info->_domain.y - _info->_domain.x);

        //set origin
        _info->_origin.y = _info->_origin.y - scale;

        //plot
        _points = _plotter();

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_g,"") != 0)
        {
            _gpoints = _plotter(1);
        }

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_h,"") != 0)
        {
            _hpoints = _plotter(2);
        }

    }

    else if(command == CLICK_ZOOM)
    {
        //plot
        _points = _plotter();

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_g,"") != 0)
        {
            _gpoints = _plotter(1);
        }

        //check to see if the other graph needs to get drawn
        if(strcmp(_info->input_h,"") != 0)
        {
            _hpoints = _plotter(2);
        }

    }


    else if (command == START)
    {
        //plot
        _points = _plotter();
    }

   //set command to DEFAULT to prevent graph from plotting over & over
    command = DEFAULT;
}

void Graph::draw(sf::RenderWindow& window)
{
    //draw margin
    sf::Vertex line_left[] =
    {
        sf::Vertex(sf::Vector2f(EDGE, EDGE)),
        sf::Vertex(sf::Vector2f(EDGE, SCREEN_HEIGHT-EDGE))
    };
    window.draw(line_left, 2, sf::Lines);

    //draw margin
    sf::Vertex line_up[] =
    {
        sf::Vertex(sf::Vector2f(EDGE, EDGE)),
        sf::Vertex(sf::Vector2f(WORK_PANEL-EDGE, EDGE))
    };
    window.draw(line_up, 2, sf::Lines);

    //draw margin
    sf::Vertex line_right[] =
    {
        sf::Vertex(sf::Vector2f(WORK_PANEL-EDGE, EDGE)),
        sf::Vertex(sf::Vector2f(WORK_PANEL-EDGE, SCREEN_HEIGHT-EDGE))
    };
    window.draw(line_right, 2, sf::Lines);

    //draw margin
    sf::Vertex line_down[] =
    {
        sf::Vertex(sf::Vector2f(EDGE, SCREEN_HEIGHT-EDGE)),
        sf::Vertex(sf::Vector2f(WORK_PANEL-EDGE, SCREEN_HEIGHT-EDGE))
    };
    window.draw(line_down, 2, sf::Lines);

    //draw y axis
    sf::Vertex line_y[] =
    {
        sf::Vertex(sf::Vector2f(_info->_origin.x, 0)),
        sf::Vertex(sf::Vector2f(_info->_origin.x, SCREEN_HEIGHT))
    };
    window.draw(line_y, 2, sf::Lines);

    //draw x axis
    sf::Vertex line_x[] =
    {
        sf::Vertex(sf::Vector2f(0, _info->_origin.y)),
        sf::Vertex(sf::Vector2f((WORK_PANEL), _info->_origin.y))
    };
    window.draw(line_x, 2, sf::Lines);

    //check if there are points to draw for second function
    if(_hpoints.get_size() != 0)
    {
        sf::CircleShape circle_h(POINT);
        for(int i=0; i<_hpoints.get_size(); i++)
        {
            circle_h.setPosition(_hpoints[i]);
            circle_h.setFillColor(sf::Color::Green);
            window.draw(circle_h);
        }
    }

    //check if there are points to draw for third function
    if(_gpoints.get_size() != 0)
    {
        sf::CircleShape circle_g(POINT);
        for(int i=0; i<_gpoints.get_size(); i++)
        {
            circle_g.setPosition(_gpoints[i]);
            circle_g.setFillColor(sf::Color::Blue);
            window.draw(circle_g);
        }
    }

    //draw function
    sf::CircleShape circle(POINT);
    for(int i=0; i<_points.get_size(); i++)
    {
        circle.setPosition(_points[i]);
        circle.setFillColor(sf::Color::Red);
        window.draw(circle);
    }

}
