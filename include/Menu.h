#pragma once
#include <SFML/Graphics.hpp>
#include <SingletonPicture.h>
class Sound;
class Menu
{
public:
	Menu();
	int StartGame(sf::RenderWindow &,  Sound& );



private:
    enum ChoosingHero
	{
		HeroJerry = 1,
		HeroRick = 2
	};

    void initializeScreenPic(sf::RectangleShape& , sf::RectangleShape&, sf::Sprite& );
    void initializeScreenText(sf::Text&, sf::Text&, const sf::Font &);
    void updateSelectPic(sf::RectangleShape &shape, sf::RectangleShape &shape1);
};
