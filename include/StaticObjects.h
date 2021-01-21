#pragma once

#include "GameObj.h"
#include "SingletonPicture.h"


class StaticObjects : public GameObj
{
public:

	StaticObjects() = default;
	StaticObjects(const sf::Texture &, const sf::Vector2f& loc, const sf::Vector2f&);
	~StaticObjects() override= default;;
	//===================public function=================
     virtual bool isObjectDigable(const sf::Time&) =0;
     virtual bool isObjectIsStandable(Hero&) =0;
     virtual bool isObjectIsStandable(Enemy&)=0;

};

