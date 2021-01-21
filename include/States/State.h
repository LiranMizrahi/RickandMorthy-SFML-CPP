#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class State {
public:
    State() = default;
    State(const sf::Texture& ,const sf::SoundBuffer&);
    //===================public function=================
    virtual void openstate(sf::RenderWindow &m_window, bool isplayerwin) = 0;


protected:
    //=========protected members======================
    sf::Sprite m_stateBackround;
    sf::Sound m_stateSound;

};

