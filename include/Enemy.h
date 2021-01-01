#pragma once
#include "GameObj.h"
#include "Picture.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"
class Enemy : public MovingObjects {



public:
	Enemy(Picture&, const sf::Vector2f&, int);


};