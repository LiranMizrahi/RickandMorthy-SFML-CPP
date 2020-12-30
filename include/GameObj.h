#pragma once

#include <SFML/Graphics.hpp>

class GameObj {


public:
	GameObj() {};
	 GameObj(sf::Texture& ,sf::Vector2f);
	~GameObj();


	void draw(sf::RenderWindow&);

	sf::Sprite m_sprite;

private:


};