#pragma once

#include"Gift.h"
#include"Hero.h"
#include<iostream>

class GiftAddingScore : public Gift
{
public:
	GiftAddingScore() = default;
	GiftAddingScore(const sf::Vector2f& loc, const sf::Vector2f&);
	virtual ~GiftAddingScore() = default;

	//===================public function=================
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

};