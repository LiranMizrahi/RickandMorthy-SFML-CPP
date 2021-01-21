#include "Ladder.h"
#include "SingletonPicture.h"
#include  <cmath>

//=============================================================

Ladder::Ladder(const sf::Vector2f& loc , const sf::Vector2f& size): StaticObjects(SingletonPicture::instance().getLedderTexture(), loc, size)
{

}
//=============================================================

void Ladder::handleColision(Hero& obj)
{
	obj.handleColision(*this);
}
//=============================================================
void Ladder::handleColision(Enemy& obj)
{
	obj.handleColision(*this);
}
//=============================================================
void Ladder::handleColision(GameObj &obj) {
    obj.handleColision(*this);
}
//=============================================================
bool Ladder::isObjectIsStandable(Hero & hero) {

    return (std::abs(m_sprite.getPosition().x -hero.getSprite().getPosition().x )
    < this->m_sprite.getTexture()->getSize().x/2u) ;
    // &&std::abs( m_sprite.getPosition().y- obj.getSprite().getPosition().y )< 5)

}
//=============================================================
bool Ladder::isObjectIsStandable(Enemy & obj) {

    return (std::abs(m_sprite.getPosition().x -obj.getSprite().getPosition().x )
            < this->m_sprite.getTexture()->getSize().x/2u);

}
//=============================================================
bool Ladder::isObjectDigable(const sf::Time &) {
    return false;
}
//=============================================================

