#include "Menu.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "SingletonSound.h"
#include "SingletonFont.h"
#include "Macros.h"
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

int Menu::StartGame(sf::RenderWindow& window)
{
	int heroChoose = HEROASJERRY;
	auto background = sf::Sprite(SingletonPicture::instance().getMenuTexture());
    sf::Text start;
    sf::Text select;
    sf::RectangleShape rickpic,jerrypic;
    sf::Sound ricksound;
    sf::Sound jerrysound;



    ricksound.setBuffer(SingletonSound::instance().getMRick());
    jerrysound.setBuffer(SingletonSound::instance().getMJerry());


    initializeScreenPic(jerrypic, rickpic, background);
    initializeScreenText(start, select);

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
          else if (event.type == sf::Event::MouseButtonReleased)
		{
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y});

				if (rickpic.getGlobalBounds().contains(location))
				{
				    updateSelectPic(rickpic,jerrypic);
					heroChoose = HEROASRICK;
					rickpic.setOutlineColor(sf::Color::Blue);
				ricksound.play();

				}
				else if(jerrypic.getGlobalBounds().contains(location))
				{
					heroChoose = HEROASJERRY;
                    updateSelectPic(jerrypic,rickpic);
					jerrypic.setOutlineColor(sf::Color::Green);
				        jerrysound.play();
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
                               sf::Sprite& sprite) {


    sprite = sf::Sprite(SingletonPicture::instance().getMenuTexture());



    jerry = sf::RectangleShape();
    jerry.setTexture(&SingletonPicture::instance().getJerryTexture());
    jerry.setPosition(JERRYPOSITIONX, JERRYPOSITIONY);
    jerry.setSize(sf::Vector2f(SingletonPicture::instance().getJerryTexture().getSize()));
    jerry.scale(SCALEFACTOR,SCALEFACTOR);

    rick = sf::RectangleShape();
    rick.setTexture(&SingletonPicture::instance().getRickTexture());
    rick.setPosition(RICKPOSITIONX, RICKPOSITIONY);
    rick.setSize(sf::Vector2f(SingletonPicture::instance().getRickTexture().getSize()));
    rick.scale(SCALEFACTOR,SCALEFACTOR);


}
//==================================================================

void Menu::initializeScreenText(sf::Text &text_1, sf::Text &text_2) {


    text_1.setFont(SingletonFont::instance().getMMenu()); // font is a sf::Font
    text_1.setString("Start");
    text_1.setCharacterSize(CHARSIZE); // in pixels, not points!
    text_1.setFillColor(sf::Color::Black);
    text_1.setStyle(sf::Text::Bold);
    text_1.setPosition(STARTTEXTX, STARTTEXTY);


    text_2.setFont(SingletonFont::instance().getMMenu()); // font is a sf::Font
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
