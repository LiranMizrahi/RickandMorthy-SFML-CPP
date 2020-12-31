#pragma once


#include <SFML/Graphics.hpp>
class Picture
{

public:

    Picture();

    sf::Texture* GetHeroTexture();
    sf::Texture* GetEnemyTexture();
    sf::Texture* GetGunTexture();
    sf::Texture* GetBoardTexture();
    sf::Texture* GetFloorTexture();
    sf::Texture* GetLedderTexture();
    sf::Texture* GetRopeTexture();
    sf::Texture* GetMenuTexture();
    sf::Texture* GetStartTexture();

  
   private:
    sf::Texture m_hero;
    sf::Texture m_enemy;
    sf::Texture m_gun;
    sf::Texture m_board;
    sf::Texture m_ledder;
    sf::Texture m_rope;
    sf::Texture m_floor;
    sf::Texture m_menu;
    sf::Texture m_start;


};


