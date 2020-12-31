#include "..\include\GameObj.h"

GameObj::GameObj(const sf::Texture& tex, const sf::Vector2f & location)
{
	m_sprite.setTexture(tex);
	m_sprite.setPosition(location);
}

GameObj::~GameObj()
{
}

void GameObj::draw(sf::RenderWindow& window)const
{
	window.draw(this->m_sprite);
}
