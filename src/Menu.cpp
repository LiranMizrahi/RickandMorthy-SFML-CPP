#include "Menu.h"

Menu::Menu():m_window(sf::VideoMode(1800, 1080), "Start Game")
{
	
}

void Menu::OpenMenu()
{
	auto loc = sf::Vector2f(50, 50);
	m_location = loc;
	auto picture = sf::Sprite(*m_Picture.GetHeroTexture());
	  
	picture.setOrigin(50, 50);
	picture.setPosition(m_location);

	auto loc1 = sf::Vector2f(100, 100);
	m_location = loc1;
	auto picture1 = sf::Sprite(*m_Picture.GetInsertScreenTexture());
	picture1.setOrigin(100, 100);
	picture1.setPosition(m_location);





	sf::Text text;


	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	//font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	// select the font

	text.setFont(font); // font is a sf::Font

	// set the string to display
	text.setString("start game");

	// set the character size
	text.setCharacterSize(100); // in pixels, not points!

	// set the color
	text.setFillColor(sf::Color::Red);

	// set the text style
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(100, 100);
	text.setOrigin(50, 50);


		// inside the main loop, between window.clear() and window.display()
		
	while (m_window.isOpen())
	{

		m_window.clear();
		m_window.draw(picture1);

		m_window.draw(picture);
		m_window.draw(text);

		m_window.display();

	}
}
