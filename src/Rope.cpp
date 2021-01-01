#include "Rope.h"
#include "Rope.h"

Rope::Rope()
{
}

Rope::Rope(Picture& pic, const sf::Vector2f& loc):StaticObjects(*pic.GetRopeTexture(), loc)

{
}
