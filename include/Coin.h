#pragma once

#include "StaticObjects.h"
#include <SFML/Graphics.hpp>
class Picture;


class Coin : public StaticObjects {

public:
	Coin();
	Coin(Picture&, const sf::Vector2f& loc, const sf::Vector2f&);

private:
	bool m_isTaken;

};