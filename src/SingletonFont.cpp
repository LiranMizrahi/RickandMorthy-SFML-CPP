//
// Created by Liran Mizrahi on 14/01/2021.
//

#include "SingletonFont.h"

SingletonFont::SingletonFont() {

    m_gameover.loadFromFile("gameoverfont.ttf");
    m_menu.loadFromFile("menufont.TTF");
    m_boardstatus.loadFromFile("gamestatusfont.otf");
}

SingletonFont &SingletonFont::instance() {

    static SingletonFont inte;
    return inte;
}

const sf::Font &SingletonFont::getMStartgame() const {
    return m_startgame;
}

const sf::Font &SingletonFont::getMGameover() const {
    return m_gameover;
}

const sf::Font &SingletonFont::getMMenu() const {
    return m_menu;
}

const sf::Font &SingletonFont::getMBoardstatus() const {
    return m_boardstatus;
}
