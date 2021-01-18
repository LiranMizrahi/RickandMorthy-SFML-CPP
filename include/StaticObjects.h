#pragma once

#include "GameObj.h"
#include "SingletonPicture.h"


class StaticObjects : public GameObj
{
public:

	StaticObjects();
	StaticObjects(const sf::Texture &, const sf::Vector2f& loc, const sf::Vector2f&);

	 ~StaticObjects() override= default;;

	 virtual void handleColision(GiftAddingTime&) override {};
     virtual bool isObjectDigable(const sf::Time&) =0;
     virtual bool isObjectIsStandable(Hero&) =0;
     virtual bool isObjectIsStandable(Enemy&)=0;

private:

};

