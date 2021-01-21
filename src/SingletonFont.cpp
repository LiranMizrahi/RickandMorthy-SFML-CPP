
#include "SingletonFont.h"
#include <iostream>

//=========================constructor ======================================
SingletonFont::SingletonFont() {

   if(! m_gameover.loadFromFile("gameoverfont.ttf"))
        std::cout << " Cant open gameoverfont font";

    if(!m_menu.loadFromFile("menufont.TTF"))
    std::cout << " Cant open menufont font";
    if(!m_boardstatus.loadFromFile("gamestatusfont.otf"))
        std::cout << " Cant open gameoverfont font";
}
//=============================================================
SingletonFont &SingletonFont::instance() {

    static SingletonFont inte;
    return inte;
}
//=============================================================
const sf::Font &SingletonFont::getMStartgame() const {
    return m_startgame;
}
//=============================================================
const sf::Font &SingletonFont::getMGameover() const {
    return m_gameover;
}
//=============================================================
const sf::Font &SingletonFont::getMMenu() const {
    return m_menu;
}
//=============================================================

const sf::Font &SingletonFont::getMBoardstatus() const {
    return m_boardstatus;
}
//=============================================================
