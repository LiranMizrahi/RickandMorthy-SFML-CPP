#pragma once
#include "GameObj.h"
#include"Floor.h"
#include"Ladder.h"
#include"Rope.h"
class MovingObjects : public GameObj
{
public:

	MovingObjects();
	MovingObjects(const sf::Texture& tex, const sf::Vector2f& loc);
	void move(float,float);
	
	


};