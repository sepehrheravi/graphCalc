#include "animate.h"
#include "constants.h"
#include <iostream>
using namespace std;
#include "system.h"


animate::animate(): _info(new Graph_info), system(_info),
    sidebar(WORK_PANEL, SIDE_BAR)
{
    //set function_input to false
    function_input = false;
    j_input = false;
    k_input = false;
    help_box = false;

    //call set_info to initialize graph info
    set_info();

    //specify everything for text displayed in the screen
    function_input_text.setFont(font);
    function_input_text.setCharacterSize(30);
    function_input_text.setStyle(sf::Text::Bold);
    function_input_text.setFillColor(sf::Color::Red);
    function_input_text.setPosition(TEXT_POS_X,TEXT_POS_Y);

    help_box_text.setFont(font);
    help_box_text.setCharacterSize(30);
    help_box_text.setStyle(sf::Text::Bold);
    help_box_text.setFillColor(sf::Color::Red);
    help_box_text.setPosition(TEXT_POS_X,TEXT_POS_Y);

    //create the window
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
                  "Graphing Calculator");

    window.setFramerateLimit(60);


    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration


    if (!font.loadFromFile("../arial.ttf"))
    {
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    command = 0;
    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw()
{
    //call system to draw
    system.Draw(window);

    //sidebar draw itself
    sidebar.draw(window);

    //check if f is pressed
    if(function_input || j_input || k_input)
    {
        //create a box and set all the features
        sf::RectangleShape r;
        r.setFillColor(sf::Color::Black);
        r.setOutlineThickness(2);
        r.setOutlineColor(sf::Color::Yellow);
        r.setPosition(sf::Vector2f(TEXT_BOX_POS_X,TEXT_BOX_POS_Y));
        r.setSize(sf::Vector2f(TEXT_BOX_WIDTH, TEXT_BOX_HEIGHT));

        //draw the box first
        window.draw(r);

        //draw text inside of the box
        window.draw(function_input_text);
    }

    //check if f1 is pressed
    if(help_box)
    {
        //create a box and set all the features
        sf::RectangleShape r;
        r.setFillColor(sf::Color::Black);
        r.setOutlineThickness(2);
        r.setOutlineColor(sf::Color::Yellow);
        r.setPosition(sf::Vector2f(HELP_BOX_POS_X,HELP_BOX_POS_Y));
        r.setSize(sf::Vector2f(HELP_BOX_WIDTH, HELP_BOX_HEIGHT));

        //draw the box first
        window.draw(r);

        //draw text inside of the box
        window.draw(help_box_text);
    }
}

void animate::update()
{
    system.Step(command);

}

void animate::render()
{
       window.clear();
       Draw();
       window.display();
}

void animate::processEvents()
{
   sf::Event event;
   float mouseX, mouseY;

   while (window.pollEvent(event))//or waitEvent
       {

           //check the type of the event...
           switch (event.type)
           {
           //window closed
           case sf::Event::Closed:
               window.close();
               break;
           //if text is entered
           case sf::Event::TextEntered:
            //check if f is pressed
               if(function_input || j_input || k_input)
               {
                   //get the code for each key board button
                   if(event.text.unicode < 128)
                   {
                       //if backspace is pressed
                       if(event.text.unicode == '\b')
                       {
                           //check if text box is not empty
                           if(!function_str.isEmpty())
                           {
                               //remove one charachter
                               function_str.erase(function_str.
                                                  getSize()-1,1);
                           }
                       }
                       //if tab is pressed
                       else if(event.text.unicode == 9)
                       {
                           //if function is not empty
                           if(!function_str.isEmpty())
                           {
                               //clear the input
                               function_str.
                                       erase(function_str.getSize()-
                                             function_str.getSize(),
                                             function_str.getSize());
                           }
                       }

                       //if anything else is pressed
                       else
                       {
                           //change value to char and put it into
                           //function_str
                          function_str += static_cast<char>
                                  (event.text.unicode);
                       }
                   }

                   //set the function_input_text to function_str
                   //to draw on the screen
                   function_input_text.setString(function_str);
               }
               break;

           //key pressed
           case sf::Event::KeyPressed:
               switch(event.key.code)
               {

               //if return or enter is pressed
               case sf::Keyboard::Return:

                   if(help_box)
                   {
                       help_box = false;
                   }

                   //check if function input is true
                   else if(function_input)
                   {
                       //set function input to false (close text box)
                       function_input = false;

                       //assign a string to hold function_str
                       string st = function_str;

                       //insert eveything from str into
                       //_info->input_str to get it ready for tokenize
                       strcpy(_info->input_str,st.c_str());

                      //handle the connection between sidebar and file
                       history(_info->input_str);

                       //display the function at CURRENT
                       sidebar[CURRENT_FUNC_INDEX] =
                                 _info->input_str;

                       //set command to draw and reset graph
                       command = DRAW_N_RESET;
                   }
                   //check if function input is true
                   else if(j_input)
                   {
                       //set function input to false (close text box)
                       j_input = false;

                       //assign a string to hold function_str
                       string st = function_str;

                       //insert eveything from str into
                       //_info->input_str to get it ready for tokenize
                       strcpy(_info->input_g,st.c_str());

                      //handle the connection between sidebar and file
                       history(_info->input_g);

                       //display the function at CURRENT
                       sidebar[CURRENT_FUNC_INDEX] =
                                 _info->input_g;

                       //set command to draw and reset graph
                       command = DRAW_N_RESET;
                   }
                   //check if function input is true
                   else if(k_input)
                   {
                       //set function input to false (close text box)
                       k_input = false;

                       //assign a string to hold function_str
                       string st = function_str;

                       //insert eveything from str into
                       //_info->input_str to get it ready for tokenize
                       strcpy(_info->input_h,st.c_str());

                      //handle the connection between sidebar and file
                       history(_info->input_h);

                       //display the function at CURRENT
                       sidebar[CURRENT_FUNC_INDEX] =
                                 _info->input_h;

                       //set command to draw and reset graph
                       command = DRAW_N_RESET;
                   }

                   else
                   {
                       //if z and shift are both pressed
                       if (sf::Keyboard::isKeyPressed
                               (sf::Keyboard::LShift)||
                           sf::Keyboard::isKeyPressed
                               (sf::Keyboard::RShift))
                       {
                           command = ZOOM_OUT;
                       }

                       //if only z is pressed
                       else
                       {
                           command = ZOOM_IN;
                       }
                   }
                   break;

               //close textbox
               case sf::Keyboard::D:
                   function_input = false;
                   j_input = false;
                   k_input = false;
                   help_box = false;
                   break;

              //close textbox
              case sf::Keyboard::F1:
                   help_box_text.setString
                   ("HELP:\n"
                   "Hold Number [1-9] + [f] => Graph f(x)\n"
                   "Hold Number [1-9] + [g] => Graph g(x)\n"
                   "Hold Number [1-9] + [h] => Graph h(x)\n"
                   "Press [f]-type the equation -Enter => Graph f(x)\n"
                   "Press [g]-type the equation -Enter => Graph g(x)\n"
                   "Press [h]-type the equation -Enter => Graph h(x)\n"
                   "Left Click on Predefined Equations => Graph f(x)\n"
                   "Right Click on Predefined Equations => Graph g(x)\n"
                   "Left Click on History Equations => Graph f(x)\n"
                   "Right Click on History Equations => Graph g(x)\n"
                   "Press Enter => Zoom In\n"
                   "Press Shift + Enter => Zoom Out\n"
                   "Right Click on Screen => Zoom to Point\n"
                   "Left Click + Hold + Move => Drag\n"
                   "Press Left Arrow => Pan Left\n"
                   "Press Right Arrow => Pan Right\n"
                   "Press Up Arrow => Pan Up\n"
                   "Press Down Arrow => Pan Down\n"
                   "Press [R] => Reset       Press [ESC] => Exit\n"
                   "Press Enter or [D] => Close Help Window");

                   help_box = true;
                   break;


               case sf::Keyboard::R:
                   command = DRAW_N_RESET;
                   break;


               //for input the function
               case sf::Keyboard::F:
                   //check num 1-5 key is pressed at the same time
                   if(sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num1)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num2)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num3)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num4)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num5)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num6)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num7)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num8)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num9))
                   {
                      //if num 1 - 5 is pressed call num_draw to draw
                       //function
                      num_draw(_info->input_str);
                   }
                   else if(!j_input && !k_input && !function_input)
                   {
                       function_str = "";

                       //display EQ(X) on the text box
                       function_input_text.setString("f(x)=");

                       //to draw the box
                       function_input = true;

                       //handles the extra f for pressing f
                       window.pollEvent(event);
                   }
                   break;

               //for pressing G and num 1-5 for drawing g(x)
               case sf::Keyboard::G:

                   //check num 1-5 key is pressed at the same time
                   if(sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num1)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num2)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num3)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num4)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num5)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num6)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num7)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num8)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num9))
                   {
                      //if num 1 - 5 is pressed call num_draw to draw
                       //function
                      num_draw(_info->input_g);
                   }
                   else if(!j_input && !k_input && !function_input)
                   {
                       function_str = "";

                       //display EQ(X) on the text box
                       function_input_text.setString("g(x)=");

                       //to draw the box
                       j_input = true;

                       //handles the extra f for pressing f
                       window.pollEvent(event);
                   }
                   break;

               //for pressing H and num 1-5 for drawing h(x)
               case sf::Keyboard::H:

                   //check num 1-5 key is pressed at the same time
                   if(sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num1)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num2)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num3)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num4)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num5)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num6)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num7)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num8)||
                           sf::Keyboard::isKeyPressed
                           (sf::Keyboard::Num9))
                   {
                      //if num 1 - 5 is pressed call num_draw to draw
                       //function
                      num_draw(_info->input_h);
                   }
                   else if(!j_input && !k_input && !function_input)
                   {
                       function_str = "";

                       //display EQ(X) on the text box
                       function_input_text.setString("h(x)=");

                       //to draw the box
                       k_input = true;

                       //handles the extra f for pressing f
                       window.pollEvent(event);
                   }
                   break;
                case sf::Keyboard::Left:
                   command = PAN_LEFT;
                   break;

               case sf::Keyboard::Right:
                   command = PAN_RIGHT;
                   break;

               case sf::Keyboard::Escape:                   
                   window.close();
                   break;

               case sf::Keyboard::Up:
                  command = PAN_UP;
                  break;

              case sf::Keyboard::Down:
                  command = PAN_DOWN;
                  break;

               }//end of keyboard event

           //for dragging
           case sf::Event::MouseMoved:

               //if left mouse button is pressed
               if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
               {
                   //get the mouse position
                   mouseX = sf::Mouse::getPosition(window).x;
                   mouseY = sf::Mouse::getPosition(window).y;

                   //make sure the click is not on the sidebar
                   if(mouseX < WORK_PANEL)
                   {
                       //set the scale to each pixle
                       _info->_scale = (WORK_PANEL)/
                               (_info->_domain.y - _info->_domain.x);

                       double scale = _info->_scale;

                       //get the x parameter of vector
                       double nX = mouseX - _info->_origin.x;

                       //get the x parameter of vector
                       double nY = mouseY - _info->_origin.y;

                       //the vector displacement nX divided by scale
                       //give us the number to change place of domain
                       double n_domain = nX / scale;

                       //set domain
                       _info->_domain = sf::Vector2f
                               ((_info->_domain.x-n_domain),
                                (_info->_domain.y-n_domain));

                       //set origin based on vector of displacement
                       _info->_origin.x = _info->_origin.x + nX;
                       _info->_origin.y = _info->_origin.y + nY;

                       //just calls plotter
                       command = CLICK_ZOOM;
                   }

               }
               break;

           //mouse button clicked and released
           case sf::Event::MouseButtonReleased:

               //get mouse direction
               mouseX = sf::Mouse::getPosition(window).x;
               mouseY = sf::Mouse::getPosition(window).y;


               //right click
               if (event.mouseButton.button == sf::Mouse::Right)
               {
                     //make sure mouse is not on sidebar (zoom)
                   if(mouseX < WORK_PANEL)
                   {
                       //get the scale
                       _info->_scale = (WORK_PANEL)/
                               (_info->_domain.y - _info->_domain.x);

                       double scale = _info->_scale;
                       //vector of displacement x
                       double nX = mouseX - _info->_origin.x;

                       //vector of displacement y
                       double nY = mouseY - _info->_origin.y;

                       //the vector displacement nX divided by scale
                       //give us the number to change place of domain
                       double n_domain = nX / scale;

                       //set domain and zoom
                       _info->_domain = sf::Vector2f(
                                   (_info->_domain.x+n_domain)/ZOOM,
                                   (_info->_domain.y+n_domain)/ZOOM);

                       //set origin based on vector od displacement
                       _info->_origin.x = _info->_origin.x - nX;
                       _info->_origin.y = _info->_origin.y - nY;

                       command = CLICK_ZOOM;
                   }

                   //else if parameter x of mouse is between sidebar
                   //and half the sidebar
                   else if(mouseX>(WORK_PANEL)+LEFT_MARGIN &&
                           mouseX<(WORK_PANEL)+LEFT_MARGIN+SIDE_BAR/2)
                   {
                       //divide y parameter of mouse by sidebar scale
                       //this gives us the index of where we clicked
                       int scale = mouseY / SIDEBAR_SCALE;

                       //make sure the place we clicked is not empty
                       if(sidebar[scale] != "" &&
                          sidebar[scale] != "Current Graph:" &&
                          sidebar[scale] != "History:" &&
                          sidebar[scale] != "Functions:" &&
                          sidebar[scale] != "Press [F1] => HELP")
                       {
                           strcpy(_info->input_g,sidebar[scale].
                                  c_str());
                           sidebar[CURRENT_FUNC_INDEX] =
                                   sidebar[scale];
                           command = DRAW_N_RESET;
                       }
                   }
               }//end of right click

               //left click on mouse
               else
               {
                   //if parameter x of mouse is between sidebar
                   //and half the sidebar
                   if(mouseX>(WORK_PANEL)+LEFT_MARGIN &&
                           mouseX<(WORK_PANEL)+LEFT_MARGIN+SIDE_BAR/2)
                   {
                       //divide y parameter of mouse by sidebar scale
                       //this gives us the index of where we clicked
                       int scale = mouseY / SIDEBAR_SCALE;

                       //make sure the place we clicked is not empty
                       if(sidebar[scale] != "" &&
                          sidebar[scale] != "Current Graph:" &&
                          sidebar[scale] != "History:" &&
                          sidebar[scale] != "Functions:" &&
                          sidebar[scale] != "Press [F1] => HELP")
                       {
                           strcpy(_info->input_str,sidebar[scale].
                                  c_str());
                           sidebar[CURRENT_FUNC_INDEX] =
                                   sidebar[scale];
                           command = DRAW_N_RESET;
                       }
                   }

               }//end of left click
               break;

               default:
               break;
           }
   }
}

void animate::run()
{
   while(window.isOpen())
   {
       processEvents();
       update();
       render(); //clear/draw/display
   }
   cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}


//set info
void animate::set_info()
{
    //set domain
    _info->_domain = sf::Vector2f(MIN_DOM,MAX_DOM);

    //set number of points
    _info->_points = NUMBER_POINTS;

    //calculate increment and sets
    _info->_inc = (_info->_domain.y - _info->_domain.x)/
            (_info->_points-1);

    //locate origin of the screen
    float ox = (WORK_PANEL)/2;
    float oy = (SCREEN_HEIGHT)/2;

    //sets origin
    _info->_origin = sf::Vector2f(ox,oy);

}



//function draws graphs located in sidebar with numbers on keyboard
void animate::num_draw(char arr[])
{
    //check to see if num 1 on the keyboard is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        //check to see if the sidebar place is not empty
        if(sidebar[PREDEFINED_GRAPHS_INDEX] != "")
        {
            //copy the eq from sidebar into our char array to tokenize
            //and graph
            strcpy(arr,sidebar[PREDEFINED_GRAPHS_INDEX].c_str());
            //display the drawn eq on the current place in sidebar
            sidebar[CURRENT_FUNC_INDEX] =
                    sidebar[PREDEFINED_GRAPHS_INDEX];
            //set command to call system and graph properly
            command = DRAW_N_RESET;
        }
        //samething applies to all the other

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        if(sidebar[PREDEFINED_GRAPHS_INDEX+1] != "")
        {
            strcpy(arr,sidebar[PREDEFINED_GRAPHS_INDEX+1].c_str());
            sidebar[CURRENT_FUNC_INDEX] =
                    sidebar[PREDEFINED_GRAPHS_INDEX+1];
            command = DRAW_N_RESET;
        }

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    {
        if(sidebar[PREDEFINED_GRAPHS_INDEX+2] != "")
        {
            strcpy(arr,sidebar[PREDEFINED_GRAPHS_INDEX+2].c_str());
            sidebar[CURRENT_FUNC_INDEX] =
                    sidebar[PREDEFINED_GRAPHS_INDEX+2];
            command = DRAW_N_RESET;
        }



    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
    {
        if(sidebar[PREDEFINED_GRAPHS_INDEX+3] != "")
        {
            strcpy(arr,sidebar[PREDEFINED_GRAPHS_INDEX+3].c_str());
            sidebar[CURRENT_FUNC_INDEX] =
                    sidebar[PREDEFINED_GRAPHS_INDEX+3];
            command = DRAW_N_RESET;
        }

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
    {
        if(sidebar[PREDEFINED_GRAPHS_INDEX+4] != "")
        {
            strcpy(arr,sidebar[PREDEFINED_GRAPHS_INDEX+4].c_str());
            sidebar[CURRENT_FUNC_INDEX] =
                    sidebar[PREDEFINED_GRAPHS_INDEX+4];
            command = DRAW_N_RESET;
        }

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
    {
        if(sidebar[PREDEFINED_GRAPHS_INDEX+5] != "")
        {
            strcpy(arr,sidebar[PREDEFINED_GRAPHS_INDEX+5].c_str());
            sidebar[CURRENT_FUNC_INDEX] =
                    sidebar[PREDEFINED_GRAPHS_INDEX+5];
            command = DRAW_N_RESET;
        }

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
    {
        if(sidebar[PREDEFINED_GRAPHS_INDEX+6] != "")
        {
            strcpy(arr,sidebar[PREDEFINED_GRAPHS_INDEX+6].c_str());
            sidebar[CURRENT_FUNC_INDEX] =
                    sidebar[PREDEFINED_GRAPHS_INDEX+6];
            command = DRAW_N_RESET;
        }

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
    {
        if(sidebar[PREDEFINED_GRAPHS_INDEX+7] != "")
        {
            strcpy(arr,sidebar[PREDEFINED_GRAPHS_INDEX+7].c_str());
            sidebar[CURRENT_FUNC_INDEX] =
                    sidebar[PREDEFINED_GRAPHS_INDEX+7];
            command = DRAW_N_RESET;
        }

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
    {
        if(sidebar[PREDEFINED_GRAPHS_INDEX+8] != "")
        {
            strcpy(arr,sidebar[PREDEFINED_GRAPHS_INDEX+8].c_str());
            sidebar[CURRENT_FUNC_INDEX] =
                    sidebar[PREDEFINED_GRAPHS_INDEX+8];
            command = DRAW_N_RESET;
        }

    }
}

void animate::history(char arr[])
{
    //assign a found bool to becomes true if the
    //function input exist in history
    bool found = false;

    //declare a string
    string line;
    //declare an index
    int index = 0;

    //open the file
    fstream file ("equations.txt");
    if(!file)
    {
        cout << "File does not exist!" << endl;
        exit(-1);
    }
      if (file.is_open())
      {
          //get each line
          while (getline (file,line) )
          {
              //check to see if _info->input_str
              //already exists in the file
              if(line == arr)
              {
                  found = true;
              }
              //we use index to find the number of
              //equations in the file
              index++;
          }
            file.close();
      }

      //if eq doesn't exist
      if(!found)
      {

          //add it to sidebar history
          sidebar[index+HISOTY_INDEX] =
                  arr;

          //open the file
          fstream myfile("equations.txt",
                          ios::app);
          if(!myfile)
          {
              cout << "File does not exist!" << endl;
              exit(-1);
          }

          if(myfile.is_open())
          {
             //input the equation into the file
             myfile << arr << endl;
          }
          myfile.close();
      }
}




