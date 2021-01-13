#pragma once


#include <SFML/Graphics.hpp>
class SingletonPicture
{

public:

    ~SingletonPicture() =default;
    static SingletonPicture& instance();

    const sf::Texture* getHerojerryTexture();
    const sf::Texture* getHeroRickTexture();
    const sf::Texture* getEnemyMeeseeksTexture();
    const sf::Texture * getEnemyMonsterTexture();
    const sf::Texture* getCoinTexture();
    const sf::Texture* getBoardTexture();
    const sf::Texture* getFloorTexture();
    const sf::Texture* getLedderTexture();
    const sf::Texture* getRopeTexture();
    const sf::Texture* getMenuTexture();
    const sf::Texture* getJerryTexture();
    const sf::Texture* getRickTexture();
    const sf::Texture* getGiftTexture();

    const sf::Texture* getMLevelUp() ;
    const sf::Texture* getMStartGame() ;
    const sf::Texture* getMHeroIsdead() ;
    const sf::Texture* getMGameOver() ;


  
   private:
    SingletonPicture();
    SingletonPicture(const SingletonPicture &) = default;
    SingletonPicture&  operator=(const SingletonPicture&) = default;
    //static SingletonPicture m_instance;
    sf::Texture m_heroMenu1;
    sf::Texture m_heroMenu2;
    sf::Texture m_heroJerry;
    sf::Texture m_heroRick;
    sf::Texture m_enemyMeeseeks;
    sf::Texture m_enemyMonster;
    sf::Texture m_coin;
    sf::Texture m_board;
    sf::Texture m_ledder;
    sf::Texture m_rope;
    sf::Texture m_floor;
    sf::Texture m_menu;

    sf::Texture m_gift;

    sf::Texture m_levelUp;
    sf::Texture m_startGame;
    sf::Texture m_heroIsdead;
    sf::Texture m_gameOver;



};


