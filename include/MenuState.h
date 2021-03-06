#pragma once
#include <SFML/Graphics.hpp>
#include <Singletons/SingletonPicture.h>
#include "States/State.h"
#include "Macros.h"

const int JERRYPOSITIONX = 800;
const int JERRYPOSITIONY = 350;
const int RICKPOSITIONX =550;
const int RICKPOSITIONY =350;
const int STARTTEXTX = 490;
const int STARTTEXTY = 900;
const int SELECTX = 240;
const int SELECTY = 100;
const int CHARSIZE = 100;
const int CHARSIZE1 = 140;
const int SCALEFACTOR = 2;

class MenuState
{
public:
	MenuState();
    //===================public function=================
	int StartGame(sf::RenderWindow & );



private:
    //=========private members======================
    int heroChoose = HEROASJERRY;
    sf::Text start;
    sf::Text select;
    sf::RectangleShape rickpic,jerrypic;
    sf::Sound ricksound;
    sf::Sound jerrysound;
    sf::Sprite m_backGround;
    //=========private function======================
    void initializeScreenPic();
    void initializeScreenText();
    void updateSelectPic(int hero);


};

