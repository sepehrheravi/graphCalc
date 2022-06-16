#ifndef CONSTANTS_H
#define CONSTANTS_H

//screen dimentions
const float SCREEN_WIDTH = 1500;
const float SCREEN_HEIGHT = 1200;
const float WORK_PANEL = SCREEN_WIDTH*4/5;
const float SIDE_BAR = SCREEN_WIDTH*1/5;

//graph information
const float POINT = 2;
const float MIN_DOM = -5;
const float MAX_DOM = 5;
const float ZOOM = 1.5;
const int NUMBER_POINTS = 5000;

//sidebar texts
const double VERTICAL_LINE_SPACING = 10.0;
const double LEFT_MARGIN = 10.0;
const double SB_FONT_SIZE = 20;
const double HISOTY_INDEX = 15;
const double SIDEBAR_SCALE = VERTICAL_LINE_SPACING + SB_FONT_SIZE;
const int PREDEFINED_GRAPHS_INDEX = 4;
const int CURRENT_FUNC_INDEX = 1;
const int HELP_INDEX = 2;

//char array
const int MAX_CHAR = 250;

//margin
const int EDGE = 10;

//text-box and text
const int TEXT_BOX_WIDTH = 800;
const int TEXT_BOX_HEIGHT = 100;
const float TEXT_BOX_POS_X = (WORK_PANEL)/2-(TEXT_BOX_WIDTH/2);
const float TEXT_BOX_POS_Y = 25;
const float TEXT_POS_X = TEXT_BOX_POS_X + 25;
const float TEXT_POS_Y = TEXT_BOX_POS_Y * 2;

//help box
const int HELP_BOX_WIDTH = 800;
const int HELP_BOX_HEIGHT = 800;
const float HELP_BOX_POS_X = (WORK_PANEL)/2-(TEXT_BOX_WIDTH/2);
const float HELP_BOX_POS_Y = 25;




//commands
const int         START = 0,
                  ZOOM_IN = 1,
                  ZOOM_OUT = 2,
                  PAN_LEFT = 3,
                  PAN_RIGHT = 4,
                  PAN_UP = 5,
                  PAN_DOWN = 6,
                  CLICK_ZOOM = 7,
                  DRAW_N_RESET = 8,
                  FX = 9,
                  GX = 10,
                  DEFAULT = -1;






#endif // CONSTANTS_H
