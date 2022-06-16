 #include "sidebar.h"
#include "constants.h"
#include "fstream"
Sidebar::Sidebar(){

}

Sidebar::Sidebar(float left, float width):_left(left), _width(width)
{
    cout<<"Sidebar CTOR: TOP"<<endl;
    items.reserve(50);



    //set up the sidebar rectangle:

    rect.setFillColor(sf::Color(105,105,105)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));
    cout<<"Sidebar CTOR: about to load font."<<endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Sidebar CTOR: Text object initialized."<<endl;
    info_text.setFont(font);
    info_text.setCharacterSize(SB_FONT_SIZE);
    info_text.setStyle(sf::Text::Bold);
    info_text.setColor(sf::Color::Yellow);

    history_text.setFont(font);
    history_text.setCharacterSize(SB_FONT_SIZE);
    history_text.setStyle(sf::Text::Bold);
    history_text.setColor(sf::Color::White);

    func_text.setFont(font);
    func_text.setCharacterSize(SB_FONT_SIZE);
    func_text.setStyle(sf::Text::Bold);
    func_text.setColor(sf::Color::Black);


//    items.push_back("Sidebar");
    //Fill the items vector with empty strings so that we can use
    //[] to read them:
    for (int i=0 ; i<50; i++)
    {
        items.push_back("");
    }
    items[0] = "Current Graph:";
    items[CURRENT_FUNC_INDEX] = "sin ( 1 / x )";
    items[2] = "Press [F1] => HELP";

    items[PREDEFINED_GRAPHS_INDEX-1] = "Functions:";
    int i=PREDEFINED_GRAPHS_INDEX;
    items[i] = "sin ( x )";
    items[i+1] = "cos ( x )";
    items[i+2] = "tan ( x )";
    items[i+3] = "sec ( x )";
    items[i+4] = "log ( x )";
    items[i+5] = "ln ( x )";
    items[i+6] = "sqrt ( x )";
    items[i+7] = "x ^ 2";
    items[i+8] = "1 / x";


    items[HISOTY_INDEX-1] = "History:";

    string line;
    int index = HISOTY_INDEX;
    fstream myfile ("equations.txt");
    if(!myfile)
    {
        cout << "File does not exist!" << endl;
        exit(-1);
    }
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {
          items[index] = line;
          index++;
        }
        myfile.close();
      }

    cout<<"Sidebar: CTOR: Exit."<<endl;
}

void Sidebar::draw(sf::RenderWindow& window)
{



    window.draw(rect);


    float height = VERTICAL_LINE_SPACING;
    float h = PREDEFINED_GRAPHS_INDEX*
        (VERTICAL_LINE_SPACING+SB_FONT_SIZE) + VERTICAL_LINE_SPACING;

    for(int i=1; i<10; i++)
    {
        func_text.setString("[" + to_string(i) + "] ");
        func_text.setPosition(sf::Vector2f(_left+10, h));
        h += SB_FONT_SIZE+VERTICAL_LINE_SPACING;
        window.draw(func_text);
    }

//    for (vector<string>::iterator it = items.begin();
//                                it!= items.end(); it++)

    for(int i=0; i<PREDEFINED_GRAPHS_INDEX-1; i++)
    {
        bool blank = false;

        if (items[i].size() == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            info_text.setString("BLANK");
        }
        else
        {
            info_text.setString(items[i]);
        }
        info_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
        height += SB_FONT_SIZE+VERTICAL_LINE_SPACING;
        if (!blank)
            window.draw(info_text);
    }

    bool blank = false;
    func_text.setString((items[PREDEFINED_GRAPHS_INDEX-1]));
    func_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
    height += SB_FONT_SIZE+VERTICAL_LINE_SPACING;
    if (!blank)
        window.draw(func_text);
    for(int i=PREDEFINED_GRAPHS_INDEX; i<HISOTY_INDEX-1; i++)
    {
        bool blank = false;
        if (items[i].size() == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            func_text.setString("BLANK");
        }
        else
        {
            func_text.setString(items[i]);
        }
        func_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN+32,
                                           height));
        height += SB_FONT_SIZE+VERTICAL_LINE_SPACING;
        if (!blank)
            window.draw(func_text);

    }
    for(int i=HISOTY_INDEX-1; i<50; i++)
    {
        bool blank = false;

        if (items[i].size() == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            history_text.setString("BLANK");
        }
        else
        {
            history_text.setString(items[i]);
        }
        history_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN,
                                              height));
        height += SB_FONT_SIZE+VERTICAL_LINE_SPACING;
        if (!blank)
            window.draw(history_text);
    }
}

string& Sidebar::operator [](int index)
{
    return items[index];
}



