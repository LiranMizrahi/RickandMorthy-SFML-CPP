#include "Menu.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <zconf.h>

Menu::Menu()
	
{
	
}

int Menu::StartGame(sf::RenderWindow& window)
{
	int heroChoose = HeroJerry;



	auto picture1 = sf::Sprite(*m_Picture.GetMenuTexture());
	picture1.setOrigin(100, 100);
	picture1.setPosition(100, 100);


	
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
	
	font.loadFromFile("BAUHS93.ttf");
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
//	sf::SoundBuffer rick;
//    if (!rick.loadFromFile("ricksound.wav"))
//        std::cout <<"cant open file";
//    sf::Sound rickSound(rick);
//
//    sf::SoundBuffer jerry;
//   if (!jerry.loadFromFile("jerrysound.wav"))
//       std::cout <<"cant open file";
//    sf::Sound jerrySound(jerry);
//
//    sf::SoundBuffer start;
//    if (!start.loadFromFile("start.wav"))
//        std::cout <<"cant open file";
//    sf::Sound startSound(start);

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
             //       rickSound.play();
					hero_1.setFillColor(sf::Color(255, 255, 255, 255));
					hero_1.setOutlineThickness(0);
				}
				else if(hero_1.getGlobalBounds().contains(location))
				{
					heroChoose = HeroJerry;
					hero_1.setFillColor(sf::Color(255, 255, 255, 130));
					hero_1.setOutlineThickness(2);
					hero_1.setOutlineColor(sf::Color::Green);
			//		jerrySound.play();
					hero_2.setFillColor(sf::Color(255, 255, 255, 255));
					hero_2.setOutlineThickness(0);

				}
				else if(text_1.getGlobalBounds().contains(location))
				{
			//	    startSound.play();

				    sleep(2);
				//    startSound.stop();
					return heroChoose;

				}
				break;
			}
		}
	}
	return heroChoose;
}