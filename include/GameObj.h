#pragma once
#include <SFML/Graphics.hpp>

class GameObj {


public:
	GameObj();
	GameObj(const sf::Texture&, const sf::Vector2f&);
		 ~GameObj();


  void draw(sf::RenderWindow&)const;

protected:
	sf::Sprite m_sprite;

private:
	

};