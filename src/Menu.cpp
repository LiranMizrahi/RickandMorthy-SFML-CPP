#include "Menu.h"
#include <iostream>

Menu::Menu()
	//:window(sf::VideoMode(1800, 1080), "Start Game")
{
	
}

bool Menu::StartGame(sf::RenderWindow& window)
{
	bool heroChoose = false;



	auto picture1 = sf::Sprite(*m_Picture.GetMenuTexture());
	picture1.setOrigin(100, 100);
	picture1.setPosition(100, 100);


	
	auto hero_1 = sf::RectangleShape(sf::Vector2f((74*2.5), (129*2.5)));
	hero_1.setTexture(m_Picture.GetHeroTexture());
	//auto hero_1 = sf::Sprite(*m_Picture.GetHeroTexture());
	hero_1.setOrigin(50, 50);
	hero_1.setPosition(1000, 500);
	


	auto hero_2 = sf::RectangleShape(sf::Vector2f((77 * 2.5), (129 * 2.5)));
	hero_2.setTexture(m_Picture.GetEnemyTexture());
	//auto hero_2 = sf::Sprite(*m_Picture.GetEnemyTexture());
	hero_2.setOrigin(50, 50);
	hero_2.setPosition(750, 500);





	auto start_button = sf::RectangleShape(sf::Vector2f((300), (111)));
	start_button.setTexture(m_Picture.GetStartTexture());
	//auto hero_2 = sf::Sprite(*m_Picture.GetEnemyTexture());
	start_button.setOrigin(50, 50);
	start_button.setPosition(750, 200);


	


	sf::Text text_2;
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	text_2.setFont(font); // font is a sf::Font
	text_2.setString("Choose a player");
	text_2.setCharacterSize(50); // in pixels, not points!
	text_2.setFillColor(sf::Color::Black);
	text_2.setStyle(sf::Text::Bold );
	text_2.setPosition(750, 400);
	text_2.setOrigin(50, 50);

	// inside the main loop, between window.clear() and window.display()

	while (window.isOpen())
	{

		window.clear();
		window.draw(picture1);

		window.draw(hero_1);
		window.draw(hero_2);

		window.draw(start_button);
		window.draw(text_2);

		window.display();


		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:// if close
				window.close();
				break;

			case sf::Event::MouseButtonReleased:
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x - 7, event.mouseButton.y + 3 });


				if (hero_2.getGlobalBounds().contains(location))
				{
					heroChoose = true;
					hero_2.setFillColor(sf::Color(255, 255, 255, 130));
					hero_2.setOutlineThickness(2);
					hero_2.setOutlineColor(sf::Color::Blue);
				//	hero_2.setOutlineColor(sf::Color::Color(153,0,0,153));

					hero_1.setFillColor(sf::Color(255, 255, 255, 255));
					hero_1.setOutlineThickness(0);
				}
				else if(hero_1.getGlobalBounds().contains(location))
				{
					heroChoose = false;
					hero_1.setFillColor(sf::Color(255, 255, 255, 130));
					hero_1.setOutlineThickness(2);
					hero_1.setOutlineColor(sf::Color::Green);
					hero_2.setFillColor(sf::Color(255, 255, 255, 255));
					hero_2.setOutlineThickness(0);

				}
				else if(start_button.getGlobalBounds().contains(location))
				{
					return heroChoose;
				}
				break;
			}
		}
	}
}