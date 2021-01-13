#pragma once
#include <SFML/Graphics.hpp>
#include <SingletonPicture.h>
class SingletonSound;
class Menu
{
public:
	Menu();
	int StartGame(sf::RenderWindow & );


    void initializeScreenPic(sf::RectangleShape& , sf::RectangleShape&, sf::Sprite& );
    void initializeScreenText(sf::Text &text_1, sf::Text &text_2);
    void updateSelectPic(sf::RectangleShape &shape, sf::RectangleShape &shape1);
};
