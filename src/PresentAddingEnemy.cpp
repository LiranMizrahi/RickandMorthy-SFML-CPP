#include"PresentAddingEnemy.h"

PresentAddingEnemy::PresentAddingEnemy(const sf::Vector2f& loc, const sf::Vector2f& size) :Present(loc, size)
{
}

void PresentAddingEnemy::handleColision(Hero& Obj)
{
	Obj.handleColision(*this);
}
