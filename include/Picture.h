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
    sf::Texture* GetClearTexture();
    sf::Texture* GetFloorTexture();
    sf::Texture* GetDeleteTexture();
    sf::Texture* GetLedderTexture();
    sf::Texture* GetSaveTexture();
    sf::Texture* GetRopeTexture();
    sf::Texture* GetbackgroundTexture();
    sf::Texture* GetInsertScreenTexture();

  
   private:
    sf::Texture m_hero;
    sf::Texture m_enemy;
    sf::Texture m_gun;
    sf::Texture m_board;
    sf::Texture m_clear;
    sf::Texture m_delete;
    sf::Texture m_save;
    sf::Texture m_ledder;
    sf::Texture m_rope;
    sf::Texture m_floor;
    sf::Texture m_background;
    sf::Texture m_insertScreen;


};


