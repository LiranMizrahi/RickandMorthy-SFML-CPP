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

	 virtual void handleColision(GiftAddingTime&) override {};
    //virtual bool isObjectIsStandable(GameObj&) {return true;};
     virtual bool isObjectDigable(const sf::Time&) =0;
     virtual bool isObjectIsStandable(Hero&) =0;
     virtual bool isObjectIsStandable(Enemy&)=0;

private:

};

