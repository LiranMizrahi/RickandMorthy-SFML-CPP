#pragma once


#include <SFML/Graphics.hpp>
class SingletonPicture
{

public:

    ~SingletonPicture() =default;
    static SingletonPicture& instance();

    const sf::Texture & getHerojerryTexture()const;
    const sf::Texture& getHeroRickTexture()const;
    const sf::Texture& getEnemyMeeseeksTexture()const;
    const sf::Texture & getEnemyMonsterTexture()const;
    const sf::Texture& getCoinTexture()const;
    const sf::Texture& getBoardTexture()const;
    const sf::Texture& getFloorTexture()const;
    const sf::Texture& getLedderTexture()const;
    const sf::Texture& getRopeTexture()const;
    const sf::Texture& getMenuTexture()const;
    const sf::Texture& getJerryTexture()const;
    const sf::Texture& getRickTexture()const;
    const sf::Texture& getGiftTexture()const;

    const sf::Texture& getMLevelUp() const;
    const sf::Texture& getMStartGame()const ;
    const sf::Texture& getMHeroIsdead()const ;
    const sf::Texture& getMGameOver() const;


  
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
//<<<<<< HEAD
    sf::Texture m_gift;
//=======
    sf::Texture m_levelUp;
    sf::Texture m_startGame;
    sf::Texture m_heroIsdead;
    sf::Texture m_gameOver;

//>>>>>>> a5a59284c1b35d92dc1af51a7eaf77db88b01fb8

};


