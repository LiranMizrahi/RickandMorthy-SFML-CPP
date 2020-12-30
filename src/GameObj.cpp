#include "..\include\GameObj.h"

GameObj::GameObj(sf::Texture& tex, sf::Vector2f location)
{
	m_sprite.setTexture(tex);
	m_sprite.setPosition(location);
}

GameObj::~GameObj()
{
}
