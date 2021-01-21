#pragma once

#include"Gift.h"
#include"MovingObject/Hero.h"

class GiftAddingEnemy : public Gift
{
public:
	GiftAddingEnemy() = default;
	 GiftAddingEnemy(const sf::Vector2f& loc, const sf::Vector2f&);
	 virtual ~GiftAddingEnemy() = default;

	 //=========static function======================
	 static int getNumberOfGiftAddingRnemy();
	 static void redeemGift();
	 //=========public function======================
	 void handleColision(GameObj& obj) override ;
	 void handleColision(Rope& Obj) override {};
	 void handleColision(Hero& Obj) override ;
     void handleColision(Floor& obj)override {};
	 void handleColision(Ladder& obj) override {};
	 void handleColision(Coin&) override {};
	 void handleColision(Enemy&) override {};
	 void handleColision(GiftAddingLife&) override {};
	 void handleColision(GiftAddingScore&) override {};
	 void handleColision(GiftAddingEnemy&) override {};
	 void handleColision(GiftAddingTime&) override {};

private:
	//=========static members======================
        static int m_numberofgiftaddingenemy;
};