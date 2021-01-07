#include "Menu.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "Sound.h"
const int JERRYPOSITIONX = 800 ;
const int JERRYPOSITIONY = 500;
const int RICKPOSITIONX =550;
const int RICKPOSITIONY =500;
const int STARTTEXTX = 650;
const int STARTTEXTY = 100;
const int SELECTX = 650;
const int SELECTY = 400;
const int CHARSIZE = 200;
const int CHARSIZE1 = 50;
const int SCALEFACTOR = 2;

Menu::Menu()
{
	
}

int Menu::StartGame(sf::RenderWindow& window , Picture & m_Picture,  Sound& sound)
{
	int heroChoose = HeroJerry;
	auto background = sf::Sprite(*m_Picture.getMenuTexture());
    sf::Text start;
    sf::Text select;
    sf::RectangleShape rickpic,jerrypic;
    sf::Font font;

    if (!font.loadFromFile("BAUHS93.ttf"))
        std::cout << "Cant open font";

    initializeScreenPic(jerrypic, rickpic, background, m_Picture);
    initializeScreenText(start, select, font);

	while (window.isOpen())
	{

		window.clear();
		window.draw(background);
	     window.draw(jerrypic);
		window.draw(rickpic);
		window.draw(start);
		window.draw(select);
		window.display();

		if (auto event = sf::Event{}; window.waitEvent(event))
		{
            if( event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Key::Escape) {
                window.close();
                window.clear();
                break;
            }
          else if  (event.type == sf::Event::MouseButtonReleased)
		{
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y});

				if (rickpic.getGlobalBounds().contains(location))
				{
				    updateSelectPic(rickpic,jerrypic);
					heroChoose = HeroRick;
					rickpic.setOutlineColor(sf::Color::Blue);
					sound.playRickSound();

				}
				else if(jerrypic.getGlobalBounds().contains(location))
				{
					heroChoose = HeroJerry;
                    updateSelectPic(jerrypic,rickpic);
					jerrypic.setOutlineColor(sf::Color::Green);
					sound.playJerrySound();
				}
				else if(start.getGlobalBounds().contains(location))
				{
					return heroChoose;
				}
				
		}
		}
	}
	return heroChoose;
}
//==================================================================
void Menu::initializeScreenPic(sf::RectangleShape& jerry, sf::RectangleShape& rick,
                               sf::Sprite& sprite, Picture & picture) {


    sprite = sf::Sprite(*picture.getMenuTexture());



    jerry = sf::RectangleShape();
    jerry.setTexture(picture.getJerryTexture());
    jerry.setPosition(JERRYPOSITIONX, JERRYPOSITIONY);
    jerry.setSize(sf::Vector2f(picture.getJerryTexture()->getSize()));
    jerry.scale(SCALEFACTOR,SCALEFACTOR);

    rick = sf::RectangleShape();
    rick.setTexture(picture.getRickTexture());
    rick.setPosition(RICKPOSITIONX, RICKPOSITIONY);
    rick.setSize(sf::Vector2f(picture.getRickTexture()->getSize()));
    rick.scale(SCALEFACTOR,SCALEFACTOR);


}
//==================================================================

void Menu::initializeScreenText(sf::Text& text_1, sf::Text& text_2, const sf::Font & font) {


    text_1.setFont(font); // font is a sf::Font
    text_1.setString("Start");
    text_1.setCharacterSize(CHARSIZE); // in pixels, not points!
    text_1.setFillColor(sf::Color::Black);
    text_1.setStyle(sf::Text::Bold);
    text_1.setPosition(STARTTEXTX, STARTTEXTY);


    text_2.setFont(font); // font is a sf::Font
    text_2.setString("Choose a player:");
    text_2.setCharacterSize(CHARSIZE1); // in pixels, not points!
    text_2.setFillColor(sf::Color::Black);
    text_2.setStyle(sf::Text::Bold );
    text_2.setPosition(SELECTX, SELECTY);


}
//==========================================================
void Menu::updateSelectPic(sf::RectangleShape &shape, sf::RectangleShape &shape1) {

    shape.setFillColor(sf::Color(255, 255, 255, 130));
    shape.setOutlineThickness(SCALEFACTOR);

    shape1.setFillColor(sf::Color(255, 255, 255, 255));
    shape1.setOutlineThickness(0);


}
