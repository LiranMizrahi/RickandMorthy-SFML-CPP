//
// Created by Liran Mizrahi on 14/01/2021.
//

#include "StartGameState.h"
#include "SingletonSound.h"
#include "SingletonPicture.h"
#include "SingletonFont.h"


StartGameState::StartGameState() :State(SingletonPicture::instance().getMStartGame(),SingletonSound::instance().getOpenGame()){

}



void StartGameState::openstate(sf::RenderWindow &m_window, bool isplayerwin) {


    m_stateSound.play();


    while (m_window.isOpen()) {
        if (auto event = sf::Event{}; m_window.waitEvent(event)) {}

        m_window.clear();
        m_window.draw(m_stateBackround);
        m_window.display();

        sf::sleep(sf::seconds(4));
        return;
    }

}
