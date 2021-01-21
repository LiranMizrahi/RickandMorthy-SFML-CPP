#include "MenuState.h"
#include <SFML/Audio.hpp>
#include "SingletonSound.h"
#include "SingletonFont.h"
#include "Macros.h"

//=========================constructor ======================================
MenuState::MenuState()
{
    initializeScreenPic();
    initializeScreenText();
}
//=============================================================
int MenuState::StartGame(sf::RenderWindow& window)
{
    ricksound.setBuffer(SingletonSound::instance().getMRick());
    jerrysound.setBuffer(SingletonSound::instance().getMJerry());
    m_backGround.setTexture(SingletonPicture::instance().getMenuTexture());

	while (window.isOpen())
	{

		window.clear();
		window.draw(m_backGround);
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
            //take mouse relased
          else if (event.type == sf::Event::MouseButtonReleased)
		  {
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y});
                //if click on the rick pic 
				if (rickpic.getGlobalBounds().contains(location))
				{
                    updateSelectPic(HEROASRICK);
					heroChoose = HEROASRICK;
					rickpic.setOutlineColor(sf::Color::White);
				ricksound.play();


				}//if click on the jerry pic
				else if(jerrypic.getGlobalBounds().contains(location))
				{
					heroChoose = HEROASJERRY;
                    updateSelectPic(HEROASJERRY);
					jerrypic.setOutlineColor(sf::Color::White);
				        jerrysound.play();

				}// if click start
				else if(start.getGlobalBounds().contains(location))
				{
					return heroChoose;
				}	
		  }// if loc mouse in the board 
          else if(sf::Event::MouseMoved)
            {
                auto location = window.mapPixelToCoords(
                    { event.mouseMove.x, event.mouseMove.y });
                start.setColor(start.getGlobalBounds().contains(location)
                               ? sf::Color::White : sf::Color::Black);
                // If the mouse is on rick pic 
                if(rickpic.getGlobalBounds().contains(location))
                {
                    rickpic.setFillColor(sf::Color(255, 255, 255, 255));
                    jerrypic.setFillColor(sf::Color(255, 255, 255, 130));
                }
                // If the mouse is on jerry pic 
                if(jerrypic.getGlobalBounds().contains(location))
                {
                    jerrypic.setFillColor(sf::Color(255, 255, 255, 255));
                    rickpic.setFillColor(sf::Color(255, 255, 255, 130));
                }

                else if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)
                    return heroChoose;

            }

		}
	}
	return heroChoose;
}
//==================================================================
void MenuState::initializeScreenPic() {

    // take jerry pic and set posion
    jerrypic = sf::RectangleShape();
    jerrypic.setTexture(&SingletonPicture::instance().getJerryTexture());
    jerrypic.setPosition(JERRYPOSITIONX, JERRYPOSITIONY);
    jerrypic.setSize(sf::Vector2f(SingletonPicture::instance().getJerryTexture().getSize()));
    jerrypic.scale(SCALEFACTOR,SCALEFACTOR);

    // take rick pic and set posion
    rickpic = sf::RectangleShape();
    rickpic.setTexture(&SingletonPicture::instance().getRickTexture());
    rickpic.setPosition(RICKPOSITIONX, RICKPOSITIONY);
    rickpic.setSize(sf::Vector2f(SingletonPicture::instance().getRickTexture().getSize()));
    rickpic.scale(SCALEFACTOR,SCALEFACTOR);


}
//==================================================================

void MenuState::initializeScreenText() {

    //take font 
    start.setFont(SingletonFont::instance().getMMenu()); // font is a sf::Font
    start.setString("Press to start");
    start.setCharacterSize(CHARSIZE); // in pixels, not points!
    start.setFillColor(sf::Color::White);
    start.setStyle(sf::Text::Bold);
    start.setOutlineThickness(3);
    start.setOutlineColor(sf::Color::White);
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

        rickpic.setFillColor(sf::Color(255, 255, 255, 130));
        jerrypic.setOutlineThickness(SCALEFACTOR);
        jerrypic.setFillColor(sf::Color(255, 255, 255, 255));
        rickpic.setOutlineThickness(0);
    }
    else {
        jerrypic.setFillColor(sf::Color(255, 255, 255, 130));
        rickpic.setOutlineThickness(SCALEFACTOR);
        rickpic.setFillColor(sf::Color(255, 255, 255, 255));
        jerrypic.setOutlineThickness(0);

    }
}
//==========================================================

