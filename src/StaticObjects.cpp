#include "StaticObjects.h"


StaticObjects::StaticObjects()
{
}


StaticObjects::StaticObjects(sf::Texture& tex, const sf::Vector2f& loc) : GameObj(tex, loc)
{

}

void StaticObjects::draw(sf::RenderWindow& window ,const sf::Vector2f & size) const
{
	sf::RectangleShape rec(size);
	rec.setTexture(m_sprite.getTexture());
	rec.setPosition(m_sprite.getPosition());
	rec.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));
	window.draw(rec);
}
