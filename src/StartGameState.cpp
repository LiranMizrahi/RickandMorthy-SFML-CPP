//
// Created by Liran Mizrahi on 14/01/2021.
//

#include "StartGameState.h"
#include "SingletonSound.h"
#include "SingletonPicture.h"
#include "SingletonFont.h"


StartGameState::StartGameState(const sf::Texture &unnamed,
                               const sf::SoundBuffer &unnamed1) : State(unnamed, unnamed1) {//:State(SingletonPicture::instance().getMStartGame(),sf::Sound(SingletonSound::instance().getOpenGame())){

}



void StartGameState::openstate(sf::RenderWindow &m_window, bool isplayerwin) {

    auto soundmusic = sf::Sound(SingletonSound::instance().getOpenGame());
    soundmusic.play();
    sf::Sprite openpic(SingletonPicture::instance().getMStartGame());

    while (m_window.isOpen()) {
        if (auto event = sf::Event{}; m_window.waitEvent(event)) {}

        m_window.clear();
        m_window.draw(openpic);
        m_window.display();

        sf::sleep(sf::seconds(4));
        return;
    }

}
