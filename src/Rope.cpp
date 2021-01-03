#include "Rope.h"
#include "Rope.h"

Rope::Rope()
{
}

Rope::Rope(Picture& pic, const sf::Vector2f& loc, const sf::Vector2f& size):StaticObjects(*pic.GetRopeTexture(), loc,size)

{
}
