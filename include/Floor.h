#pragma once

#include "StaticObjects.h"
class Picture;
#include <SFML/Graphics.hpp>
class Floor : public StaticObjects {

public:
	Floor() ;
	Floor(Picture&, const sf::Vector2f& loc);


};