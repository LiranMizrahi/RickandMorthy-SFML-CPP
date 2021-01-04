#pragma once


#include <SFML/Graphics.hpp>
class Picture
{

public:

    Picture();

    sf::Texture* GetHerojerryTexture();
    sf::Texture* GetHeroRickTexture();
    sf::Texture* GetEnemyMeeseeksTexture();
    sf::Texture* GetEnemyMonsterTexture();
    sf::Texture* GetCoinTexture();
    sf::Texture* GetBoardTexture();
    sf::Texture* GetFloorTexture();
    sf::Texture* GetLedderTexture();
    sf::Texture* GetRopeTexture();
    sf::Texture* GetMenuTexture();
    sf::Texture* GetStartTexture();
    sf::Texture* GetHeroMenu1Texture();
    sf::Texture* GetHeroMenu2Texture();


  
   private:
    sf::Texture m_HeroMenu1;
    sf::Texture m_HeroMenu2;
    sf::Texture m_heroJerry;
    sf::Texture m_heroRick;
    sf::Texture m_EnemyMeeseeks;
    sf::Texture m_EnemyMonster;
    sf::Texture m_coin;
    sf::Texture m_board;
    sf::Texture m_ledder;
    sf::Texture m_rope;
    sf::Texture m_floor;
    sf::Texture m_menu;
    sf::Texture m_start;


};


