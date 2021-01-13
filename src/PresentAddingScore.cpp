#include"PresentAddingScore.h"

PresentAddingScore::PresentAddingScore(const sf::Vector2f& loc, const sf::Vector2f& size) :Present(loc, size)
{
}

void PresentAddingScore::handleColision(Hero& Obj)
{
	Obj.handleColision(*this);
}


