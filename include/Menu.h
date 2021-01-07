#pragma once
#include <SFML/Graphics.hpp>
#include <Picture.h>
class Sound;
class Menu
{
public:
	Menu();
	int StartGame(sf::RenderWindow &,Picture &, Sound& );



private:
    enum ChoosingHero
	{
		HeroJerry = 1,
		HeroRick = 2
	};

    void initializeScreenPic(sf::RectangleShape& , sf::RectangleShape&,sf::Sprite& , Picture &);
    void initializeScreenText(sf::Text&, sf::Text&, const sf::Font &);
    void updateSelectPic(sf::RectangleShape &shape, sf::RectangleShape &shape1);
};
