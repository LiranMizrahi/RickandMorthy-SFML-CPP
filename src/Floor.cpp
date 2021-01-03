#include "Floor.h"
#include "Picture.h"
Floor::Floor()
{
}
Floor::Floor( Picture& pic, const sf::Vector2f& loc, const sf::Vector2f& size):StaticObjects(*pic.GetFloorTexture(),loc,size)
{

}
