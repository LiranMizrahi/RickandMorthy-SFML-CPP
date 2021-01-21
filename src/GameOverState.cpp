
#include "GameOverState.h"
#include "SingletonFont.h"
#include "SingletonPicture.h"
#include "SingletonSound.h"

const int NEWGAMEXPOS = 620;
const int NEWGAMEYPOS = 600;
const int GAMEEXITSTATUSX = 580;
const int GAMEEXITSTATUSY = 350;

const int EXITXPOS = 730;
const int EXITYPOS = 700;
const int MENUTEXTSIZE = 55;
const int TITLECHARSIZE = 80;
//=========================constructor ======================================
GameOverState::GameOverState():State(SingletonPicture::instance().getMGameOver(),SingletonSound::instance().getMGameOver())
{

    gameexitstatus.setFont(SingletonFont::instance().getMGameover());
    exitgame.setFont(SingletonFont::instance().getMGameover());
    newgame.setFont(SingletonFont::instance().getMGameover());

    newgame.setCharacterSize(MENUTEXTSIZE);
    exitgame.setCharacterSize(MENUTEXTSIZE);

    exitgame.setStyle(exitgame.Underlined);
    gameexitstatus.setCharacterSize(TITLECHARSIZE);
    gameexitstatus.setPosition(GAMEEXITSTATUSX, GAMEEXITSTATUSY);
    newgame.setPosition(NEWGAMEXPOS, NEWGAMEYPOS);
    exitgame.setPosition(EXITXPOS, EXITYPOS);
    newgame.setString("NEW GAME");
    exitgame.setString("EXIT");

}
//=============================================================
void GameOverState::openstate(sf::RenderWindow &m_window, bool isplayerwin)


{

    if (isplayerwin)
        gameexitstatus.setString("YOU WON");
    else {

        gameexitstatus.setString("YOU LOST");
    }
    sf::sleep(sf::seconds(2));
    m_stateSound.play();

    auto event = sf::Event();

    while (m_window.isOpen())
    {
        m_window.clear();
        m_window.draw(m_stateBackround);
        m_window.draw(exitgame);
        m_window.draw(newgame);
        m_window.draw(gameexitstatus);
        m_window.display();
        if (m_window.waitEvent(event))
        {
            if (event.type == sf::Event::KeyReleased)
            {
                if(event.key.code ==sf::Keyboard::Up)
                {
                    choose = NEWGAME;
                    newgame.setStyle(exitgame.Underlined);
                    exitgame.setStyle(0);
                }

                else if (event.key.code ==sf::Keyboard::Down)
                {
                    choose = EXIT;
                    exitgame.setStyle(exitgame.Underlined);
                    newgame.setStyle(0);

                }
                else if (event.key.code ==sf::Keyboard::Enter)
                {
                    if (choose == EXIT)
                    {
                        m_window.close();
                        exit(EXIT_SUCCESS);
                    }

                    if (choose == NEWGAME)
                    {
                        return;
                    }

                }

            }

        }
    }
}
