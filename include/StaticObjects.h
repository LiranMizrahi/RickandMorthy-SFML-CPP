#pragma once

#include "GameObj.h"
#include "Picture.h"


class StaticObjects : public GameObj
{
public:

	StaticObjects();
	StaticObjects(sf::Texture &, const sf::Vector2f& loc, const sf::Vector2f&);
	//	void draw(sf::RenderWindow&, const sf::Vector2f& )const ;
	 ~StaticObjects() override= default;;

private:

};

