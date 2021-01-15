#pragma once

#include "GameObj.h"
#include "SingletonPicture.h"


class StaticObjects : public GameObj
{
public:

	StaticObjects();
	StaticObjects(const sf::Texture &, const sf::Vector2f& loc, const sf::Vector2f&);
	//	void draw(sf::RenderWindow&, const sf::Vector2f& )const ;
	 ~StaticObjects() override= default;;
    virtual bool isObjectIsStandable(GameObj&) = 0;
    virtual bool isObjectDigable() = 0;
private:

};

