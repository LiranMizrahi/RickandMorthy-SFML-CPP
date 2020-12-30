#pragma once
#include <SFML/Graphics.hpp>
#include <Picture.h>
class Menu
{
public:
	Menu();
	
	void OpenMenu();
private:
	Picture m_Picture;
	sf::Vector2f m_location;

	sf::RenderWindow m_window;
	void Start();

};
