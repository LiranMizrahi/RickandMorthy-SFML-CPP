#pragma once
#include <SFML/Graphics.hpp>
#include <Picture.h>
class Menu
{
public:
	Menu();
	
	int StartGame(sf::RenderWindow &,Picture &);
private:
	//Picture m_Picture;
	sf::Vector2f m_location;

	sf::RenderWindow window;
	enum ChoosingHero
	{
		HeroJerry = 1,
		HeroRick = 2
	};
};
