#pragma once
#include "StaticObjects.h"
class SingletonPicture;
#include <SFML/Graphics.hpp>
#include<MovingObject/Hero.h>
#include<MovingObject/Enemy.h>
class Floor : public StaticObjects {

public:
	Floor()  = default;
	Floor(const sf::Vector2f& loc, const sf::Vector2f&);
    virtual ~Floor()  = default;

	//===================public function=================
	 void handleColision(Rope& )override  {};
	 void handleColision(Hero& )override ;
	 void handleColision(Floor& ) override {};
	 void handleColision(Ladder& ) override {};
	 void handleColision(GameObj& ) override;
	 void handleColision(Coin&) override {};
	 void handleColision(Enemy&) override;
	 void handleColision(GiftAddingLife&) override {};
	 void handleColision(GiftAddingScore&) override {};
	 void handleColision(GiftAddingEnemy&) override {};
	 void handleColision(GiftAddingTime&) override {};

     bool isObjectIsStandable(Hero&)override;
     bool isObjectIsStandable(Enemy&)override;

     bool isObjectDigable(const sf::Time &) override;
     bool restoreGameObj(const sf::Time &, float cellheight) override;

     void setIsOff(bool isoff)override;
	 void resetObj()override;

private:
	//=========private members ======================
    sf::Time m_digtimestamp = sf::Time::Zero;
    bool m_isfull;
};