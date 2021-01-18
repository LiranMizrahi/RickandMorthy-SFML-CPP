#pragma once
#include <SFML/Graphics.hpp>
#include <SingletonPicture.h>
#include "State.h"
#include "Macros.h"

const int JERRYPOSITIONX = 800 ;
const int JERRYPOSITIONY = 500;
const int RICKPOSITIONX =550;
const int RICKPOSITIONY =500;
const int STARTTEXTX = 650;
const int STARTTEXTY = 100;
const int SELECTX = 650;
const int SELECTY = 400;
const int CHARSIZE = 200;
const int CHARSIZE1 = 50;
const int SCALEFACTOR = 2;

class MenuState:State
{
public:
	MenuState();
	int StartGame(sf::RenderWindow & );
    virtual void openstate(sf::RenderWindow &m_window, bool);


private:
    int heroChoose = HEROASJERRY;
    sf::Text start;
    sf::Text select;
    sf::RectangleShape rickpic,jerrypic;
    sf::Sound ricksound;
    sf::Sound jerrysound;

    void initializeScreenPic();
    void initializeScreenText();
    void updateSelectPic(int hero);


};

