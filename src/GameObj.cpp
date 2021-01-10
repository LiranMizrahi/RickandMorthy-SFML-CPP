#include "GameObj.h"
#include "Macros.h"


GameObj::GameObj(const sf::Texture& tex, const sf::Vector2f & location, const sf::Vector2f& board_size)
{

	m_sprite.setTexture(tex);
	m_sprite.setPosition(location);

	//     all texture calibrate to board in size 15*25
	m_sprite.setScale(sf::Vector2f((WIDTHSIZECALI/board_size.y) ,(HEIGHTSIZECALI/board_size.x)));
	m_sprite.setOrigin(sf::Vector2f(tex.getSize() / 2u));
}

GameObj::GameObj()
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
   if(!m_isOff)
	window.draw(this->m_sprite);
}

sf::Sprite GameObj::getSprite() {
    return m_sprite;
}
