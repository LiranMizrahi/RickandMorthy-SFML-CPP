#pragma once
#include "GameObj.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"
class Hero : public MovingObjects {



   public:
	   Hero();
	   Hero(sf::Texture&,const sf::Vector2f &);
	

};