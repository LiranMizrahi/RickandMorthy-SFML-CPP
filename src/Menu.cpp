#include "Menu.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "Sound.h"

Menu::Menu()
{
	
}
//
//const int JERRYPOSITIONX ;
//const int JERRYPOSITIONY;
//const int RICKPOSITIONX;
//const int RICKPOSITIONY;
//const int JERRYPOSITIONX;




int Menu::StartGame(sf::RenderWindow& window , Picture & m_Picture,  Sound& sound)
{
	int heroChoose = HeroJerry;

	auto picture1 = sf::Sprite(*m_Picture.GetMenuTexture());


	auto hero_1 = sf::RectangleShape(sf::Vector2f((193*2), (250*2)));
	hero_1.setTexture(m_Picture.GetHeroMenu1Texture());
	hero_1.setOrigin(50, 50);
	hero_1.setPosition(1000, 500);
	


	auto hero_2 = sf::RectangleShape(sf::Vector2f((118 * 2), (250 * 2)));
	hero_2.setTexture(m_Picture.GetHeroMenu2Texture());
	hero_2.setOrigin(50, 50);
	hero_2.setPosition(750, 500);



	sf::Text text_1;
	sf::Font font;
	
	if (!font.loadFromFile("BAUHS93.ttf"))
		std::cout << "Cant open font";
	text_1.setFont(font); // font is a sf::Font
	text_1.setString("Start");
	text_1.setCharacterSize(200); // in pixels, not points!
	text_1.setFillColor(sf::Color::Black);
	text_1.setStyle(sf::Text::Bold);
	text_1.setPosition(750, 100);
	text_1.setOrigin(50, 50);


	sf::Text text_2;
	
	font.loadFromFile("BAUHS93.ttf");
	text_2.setFont(font); // font is a sf::Font
	text_2.setString("Choose a player:");
	text_2.setCharacterSize(50); // in pixels, not points!
	text_2.setFillColor(sf::Color::Black);
	text_2.setStyle(sf::Text::Bold );
	text_2.setPosition(750, 400);
	text_2.setOrigin(50, 50);

	// inside the main loop, between window.clear() and window.display()

	//create sound items



	while (window.isOpen())
	{

		window.clear();
		window.draw(picture1);

	     window.draw(hero_1);
		window.draw(hero_2);
		window.draw(text_1);
		window.draw(text_2);

		window.display();


		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			switch (event.type)
		{

			case sf::Event::Closed:// if close
				window.close();
				window.clear();
				break;

			case sf::Event::MouseButtonReleased:
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x - 7, event.mouseButton.y + 3 });


				if (hero_2.getGlobalBounds().contains(location))
				{
					heroChoose = HeroRick;
					hero_2.setFillColor(sf::Color(255, 255, 255, 130));
					hero_2.setOutlineThickness(2);
					hero_2.setOutlineColor(sf::Color::Blue);
					sound.playRickSound();
					hero_1.setFillColor(sf::Color(255, 255, 255, 255));
					hero_1.setOutlineThickness(0);
				}
				else if(hero_1.getGlobalBounds().contains(location))
				{
					heroChoose = HeroJerry;
					hero_1.setFillColor(sf::Color(255, 255, 255, 130));
					hero_1.setOutlineThickness(2);
					hero_1.setOutlineColor(sf::Color::Green);
					sound.playJerrySound();
					hero_2.setFillColor(sf::Color(255, 255, 255, 255));
					hero_2.setOutlineThickness(0);

				}
				else if(text_1.getGlobalBounds().contains(location))
				{
				   

					return heroChoose;
					break;
				}
				
		}
		}
	}
	return heroChoose;
}