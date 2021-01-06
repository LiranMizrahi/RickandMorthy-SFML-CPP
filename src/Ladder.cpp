#include "Ladder.h"
#include "Picture.h"

Ladder::Ladder()
{
}

Ladder::Ladder(Picture& pic, const sf::Vector2f& loc , const sf::Vector2f& size):StaticObjects(*pic.getLedderTexture(), loc, size)
{
}

void Ladder::handleColision(Hero& obj)
{
	obj.handleColision(*this);
}
