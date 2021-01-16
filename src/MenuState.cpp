#include "MenuState.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include "SingletonSound.h"
#include "SingletonFont.h"
#include "Macros.h"


MenuState::MenuState():State(SingletonPicture::instance().getMenuTexture(),SingletonSound::instance().getMRick())
{
    initializeScreenPic();
    initializeScreenText();
}

int MenuState::StartGame(sf::RenderWindow& window)
{

    ricksound.setBuffer(SingletonSound::instance().getMRick());
    jerrysound.setBuffer(SingletonSound::instance().getMJerry());

	while (window.isOpen())
	{

		window.clear();
		window.draw(m_stateBackround);
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
                    updateSelectPic(HEROASRICK);
					heroChoose = HEROASRICK;
					rickpic.setOutlineColor(sf::Color::White);
				ricksound.play();

				}
				else if(jerrypic.getGlobalBounds().contains(location))
				{
					heroChoose = HEROASJERRY;
                    updateSelectPic(HEROASJERRY);
					jerrypic.setOutlineColor(sf::Color::White);
				        jerrysound.play();
				}
				else if(start.getGlobalBounds().contains(location))
				{
					return heroChoose;
				}	
		  }
          else if(sf::Event::MouseMoved)
            {
                auto location = window.mapPixelToCoords(
                    { event.mouseMove.x, event.mouseMove.y });
                if (start.getGlobalBounds().contains(location))
                {
                    start.setColor(sf::Color::White);
                }
                else
                {
                    start.setColor(sf::Color::Black);

                }
            }
          
		}
	}
	return heroChoose;
}
//==================================================================
void MenuState::initializeScreenPic() {


    jerrypic = sf::RectangleShape();
    jerrypic.setTexture(&SingletonPicture::instance().getJerryTexture());
    jerrypic.setPosition(JERRYPOSITIONX, JERRYPOSITIONY);
    jerrypic.setSize(sf::Vector2f(SingletonPicture::instance().getJerryTexture().getSize()));
    jerrypic.scale(SCALEFACTOR,SCALEFACTOR);

    rickpic = sf::RectangleShape();
    rickpic.setTexture(&SingletonPicture::instance().getRickTexture());
    rickpic.setPosition(RICKPOSITIONX, RICKPOSITIONY);
    rickpic.setSize(sf::Vector2f(SingletonPicture::instance().getRickTexture().getSize()));
    rickpic.scale(SCALEFACTOR,SCALEFACTOR);


}
//==================================================================

void MenuState::initializeScreenText() {


    start.setFont(SingletonFont::instance().getMMenu()); // font is a sf::Font
    start.setString("Start");
    start.setCharacterSize(CHARSIZE); // in pixels, not points!
    start.setFillColor(sf::Color::Black);
    start.setStyle(sf::Text::Bold);
    start.setPosition(STARTTEXTX, STARTTEXTY);


    select.setFont(SingletonFont::instance().getMMenu()); // font is a sf::Font
    select.setString("Choose a player:");
    select.setCharacterSize(CHARSIZE1); // in pixels, not points!
    select.setFillColor(sf::Color::Black);
    select.setStyle(sf::Text::Bold );
    select.setPosition(SELECTX, SELECTY);


}
//==========================================================
void MenuState::updateSelectPic(int hero) {

    if(hero == HEROASJERRY) {
        jerrypic.setFillColor(sf::Color(255, 255, 255, 130));
        jerrypic.setOutlineThickness(SCALEFACTOR);
        rickpic.setFillColor(sf::Color(255, 255, 255, 255));
        rickpic.setOutlineThickness(0);
    }
    else {
        rickpic.setFillColor(sf::Color(255, 255, 255, 130));
        rickpic.setOutlineThickness(SCALEFACTOR);
        jerrypic.setFillColor(sf::Color(255, 255, 255, 255));
        jerrypic.setOutlineThickness(0);

    }

}

void MenuState::openstate(sf::RenderWindow &m_window, bool isplayerwin) {
    this->StartGame(m_window);

}
