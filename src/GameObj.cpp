#include "GameObj.h"
#include "Macros.h"


GameObj::GameObj(const sf::Texture& tex, const sf::Vector2f & location, const sf::Vector2f& board_size)
{

	m_sprite.setTexture(tex);
	m_sprite.setPosition(location);

	//     all texture calibrate to m_background in size 15*25
	m_sprite.setScale(sf::Vector2f((WIDTHSIZECALI/board_size.y) ,(HEIGHTSIZECALI/board_size.x)));
   // m_sprite.setOrigin(sf::Vector2f(m_sprite.getGlobalBounds().width/2,m_sprite.getGlobalBounds().height/2));
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));
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

void GameObj::draw(sf::RenderWindow& window)const
{
   if(!m_isOff)
	window.draw(this->m_sprite);
}

sf::Sprite GameObj::getSprite() const{
    return m_sprite;
}

bool GameObj::getIsOff()const {
    return m_isOff;
}

void GameObj::setIsOff(bool isoff) {
    m_isOff = isoff;

}

//bool GameObj::restoreGameObj(const sf::Time &, float cellheight) {
//
//
//}
