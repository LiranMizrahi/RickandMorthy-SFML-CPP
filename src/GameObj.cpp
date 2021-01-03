#include "..\include\GameObj.h"



GameObj::GameObj(const sf::Texture& tex, const sf::Vector2f & location)
{

	m_sprite.setTexture(tex);
	m_sprite.setPosition(location);
	m_sprite.setOrigin(sf::Vector2f(tex.getSize() / 2u));
}

GameObj::GameObj()
{
}

GameObj::~GameObj()
{
}

bool GameObj::collisonWith(const GameObj& obj)const
{
	return this->m_sprite.getGlobalBounds().intersects(obj.m_sprite.getGlobalBounds());	
}

void GameObj::draw(sf::RenderWindow& window, const sf::Vector2f& size)const
{
	sf::RectangleShape rec(size);
	rec.setPosition(m_sprite.getPosition());
	rec.setTexture(m_sprite.getTexture());
	//rec.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));
	window.draw(rec);

	//window.draw(this->m_sprite);
}
