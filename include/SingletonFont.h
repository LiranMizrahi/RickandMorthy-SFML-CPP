#pragma once
#include <SFML/Graphics.hpp>




class SingletonFont {

public:
    ~SingletonFont() =default;
    //===================public function=================
    const sf::Font& getMStartgame() const;
    const sf::Font& getMGameover() const;
    const sf::Font& getMMenu() const;
    const sf::Font& getMBoardstatus() const;

    //===================static function=================
    static SingletonFont& instance();

private:
    //=========private members======================
    sf::Font m_startgame;
    sf::Font m_gameover;
    sf::Font m_menu;
    sf::Font m_boardstatus;
    //=========private constructor======================
    SingletonFont();
};

