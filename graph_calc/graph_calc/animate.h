#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include "graph_info.h"
#include <fstream>
class animate{
public:
    animate();
    //CTOR
    void run();
    //call processEvent, update and render
    void processEvents();
    //process all the events
    void update();
    //pass command into system
    void render();
    //clear, draw, display
    void Draw();
    //draws sidebar, graph and texts on screen
    void set_info();
    //sets all the graph info

private:
    sf::RenderWindow window;
    //project window
    Graph_info* _info;
    //graph information
    System system;
    //system
    int command;
    //command to send to system
    sf::Font font;
    //font to draw on main screen
    Sidebar sidebar;
    //rectangular message sidebar


    sf::String function_str;
    //string holding text inside text box
    sf::Text function_input_text;
    //text to draw inside of the text box

    bool function_input;
    //bool for checking if the text box is opem
    bool j_input;
    //bool for checking if the text box is opem
    bool k_input;
    //bool for checking if the text box is opem

    bool help_box;
    sf::Text help_box_text;



    //extra functions
    void num_draw(char arr[]);
    //use num and draw

    void history(char arr[]);
    //use num and draw
};

#endif // GAME_H
