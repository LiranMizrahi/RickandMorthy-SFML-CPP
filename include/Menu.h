#pragma once
#include <SFML/Graphics.hpp>
#include <Picture.h>
class Menu
{
public:
	Menu();
	
	bool StartGame();
private:
	Picture m_Picture;
	sf::Vector2f m_location;

	sf::RenderWindow m_window;

};
