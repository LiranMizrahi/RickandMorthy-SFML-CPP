#pragma once


#include <SFML/Graphics.hpp>
class Picture
{

public:

    Picture();

    sf::Texture* getHerojerryTexture();
    sf::Texture* getHeroRickTexture();
    sf::Texture* getEnemyMeeseeksTexture();
    sf::Texture* getEnemyMonsterTexture();
    sf::Texture* getCoinTexture();
    sf::Texture* getBoardTexture();
    sf::Texture* getFloorTexture();
    sf::Texture* getLedderTexture();
    sf::Texture* getRopeTexture();
    sf::Texture* getMenuTexture();

    sf::Texture* getJerryTexture();
    sf::Texture* getRickTexture();


  
   private:
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


};


