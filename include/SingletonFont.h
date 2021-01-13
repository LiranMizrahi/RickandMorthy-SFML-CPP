#pragma once
#include <SFML/Graphics.hpp>




class SingletonFont {

public:

    ~SingletonFont() =default;
    static SingletonFont& instance();

private:
    SingletonFont();

public:
    const sf::Font &getMStartgame() const;

    const sf::Font &getMGameover() const;

    const sf::Font &getMMenu() const;

    const sf::Font &getMBoardstatus() const;

private:
    sf::Font m_startgame;
    sf::Font m_gameover;
    sf::Font m_menu;
    sf::Font m_boardstatus;

};

