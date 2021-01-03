#include "Ladder.h"
#include "Picture.h"

Ladder::Ladder()
{
}

Ladder::Ladder(Picture& pic, const sf::Vector2f& loc , const sf::Vector2f& size):StaticObjects(*pic.GetLedderTexture(), loc,size)
{
}
