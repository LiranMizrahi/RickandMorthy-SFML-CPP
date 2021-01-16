#include "Ladder.h"
#include "SingletonPicture.h"

Ladder::Ladder()
{
}

Ladder::Ladder(const sf::Vector2f& loc , const sf::Vector2f& size): StaticObjects(SingletonPicture::instance().getLedderTexture(), loc, size)
{

}

void Ladder::handleColision(Hero& obj)
{
	obj.handleColision(*this);
}

void Ladder::handleColision(Enemy& obj)
{
	obj.handleColision(*this);

}

void Ladder::handleColision(GameObj &obj) {
    obj.handleColision(*this);

}

bool Ladder::isObjectIsStandable(GameObj &) {
    return true;
}

bool Ladder::isObjectDigable(const sf::Time &) {
    return false;
}

