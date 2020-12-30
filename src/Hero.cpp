#include "Hero.h"


Hero::Hero()
{

}

Hero::Hero(sf::Texture& pic,const sf::Vector2f& loc)
{
	m_sprite.setTexture(pic);
	m_sprite.setPosition(loc);
}
