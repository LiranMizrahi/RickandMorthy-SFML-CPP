#include "Floor.h"
#include "Picture.h"
Floor::Floor()
{
}
Floor::Floor( Picture& pic, const sf::Vector2f& loc):StaticObjects(*pic.GetFloorTexture(),loc)
{

}
