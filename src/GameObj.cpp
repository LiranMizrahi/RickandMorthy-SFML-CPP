#include "..\include\GameObj.h"



GameObj::GameObj(const sf::Texture& tex, const sf::Vector2f & location, const sf::Vector2f& board_size)
{

	m_sprite.setTexture(tex);
	m_sprite.setPosition(location);

	//     all texture calibrate to board in size 15*25
	m_sprite.scale(sf::Vector2f((board_size.x/15) ,(board_size.y/25)));
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

	if (obj.m_sprite.getGlobalBounds().intersects(this->m_sprite.getGlobalBounds()))
	{
		return true;

	}
	return false;

}

void GameObj::draw(sf::RenderWindow& window, const sf::Vector2f& size)const
{
	
	//sf::RectangleShape rec(size);
	//rec.setPosition(m_sprite.getPosition());
	//rec.setTexture(m_sprite.getTexture());
	//rec.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));
	//window.draw(rec);
	
	window.draw(this->m_sprite);
}
