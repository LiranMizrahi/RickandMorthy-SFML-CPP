#include"PresentAddingLife.h"


PresentAddingLife::PresentAddingLife(const sf::Vector2f& loc, const sf::Vector2f& size) :Present(loc, size)
{
}

void PresentAddingLife::handleColision(Hero& Obj)
{
	Obj.handleColision(*this);	
}

