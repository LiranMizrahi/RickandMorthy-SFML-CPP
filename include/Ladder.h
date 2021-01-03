#pragma once

#include "StaticObjects.h"
class Picture;
#include <SFML/Graphics.hpp>
class Ladder : public StaticObjects {

public:
	Ladder();
	Ladder(Picture&, const sf::Vector2f& loc, const sf::Vector2f&);


};