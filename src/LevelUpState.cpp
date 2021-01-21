
#include "LevelUpState.h"
#include "SingletonSound.h"
#include "SingletonPicture.h"

LevelUpState::LevelUpState(): State(SingletonPicture::instance().getMLevelUp(),SingletonSound::instance().getMLevelUp()){


}


void LevelUpState::openstate(sf::RenderWindow &m_window, bool isplayerwin) {

    m_window.clear();
    m_window.draw(m_stateBackround);
    m_window.display();
    m_stateSound.play();
    sf::sleep(sf::seconds(2));

    }
