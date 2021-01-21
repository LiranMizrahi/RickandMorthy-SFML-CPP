#include "Rope.h"

Rope::Rope()
{
}
//=============================================================
Rope::Rope(const sf::Vector2f& loc, const sf::Vector2f& size): StaticObjects(SingletonPicture::instance().getRopeTexture(), loc, size)
{

}
//=============================================================

void Rope::handleColision(Hero& obj)
{
	obj.handleColision(*this);
}

void Rope::handleColision(Enemy& obj)
{
	obj.handleColision(*this);

}

void Rope::handleColision(GameObj &obj) {
    obj.handleColision(*this);
}

bool Rope::isObjectIsStandable(Hero & hero) {
   return  hero.getSprite().getPosition().y-this->getSprite().getPosition().y > 0;

}
bool Rope::isObjectIsStandable(Enemy & enemy) {
    return enemy.getSprite().getPosition().y - this->getSprite().getPosition().y > 0;

}

bool Rope::isObjectDigable(const sf::Time &) {
    return false;
}



