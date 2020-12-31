#include "Ladder.h"
#include "Picture.h"

Ladder::Ladder()
{
}

Ladder::Ladder(Picture& pic, const sf::Vector2f& loc):StaticObjects(*pic.GetLedderTexture(), loc)
{
}
