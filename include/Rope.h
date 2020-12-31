#pragma once

#include "StaticObjects.h"
class Picture;
#include <SFML/Graphics.hpp>
class Rope : public StaticObjects {

public:
	Rope();
	Rope(Picture&, const sf::Vector2f& loc);
		

};