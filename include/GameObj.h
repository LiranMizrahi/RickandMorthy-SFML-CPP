#pragma once

#include <SFML/Graphics.hpp>

class GameObj {


public:

	GameObj();
	GameObj(sf::Texture& ,sf::Vector2f);

private:

	sf::Sprite m_sprite;

};