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
    void initializeScreenText(sf::Text&, sf::Text&, const sf::Font &);
    void updateSelectPic(sf::RectangleShape &shape, sf::RectangleShape &shape1);
};
