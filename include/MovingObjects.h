#pragma once
#include "GameObj.h"
class MovingObjects : public GameObj
{
public:

	MovingObjects();
	MovingObjects(const sf::Texture& tex, const sf::Vector2f& loc);
	// ~MovingObjects() {};

};