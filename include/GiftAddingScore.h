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


	virtual void handleColision(GameObj& obj) override ;
	virtual void handleColision(Rope& Obj) override {};
	virtual void handleColision(Hero& Obj) override ;
	virtual void handleColision(Floor& obj)override {};
	virtual void handleColision(Ladder& obj) override {};
	virtual void handleColision(Coin&) override {};
	virtual void handleColision(Enemy&) override {};
	virtual void handleColision(GiftAddingLife&) override {};
	virtual void handleColision(GiftAddingScore&) override {};
	virtual void handleColision(GiftAddingEnemy&) override {};
	void handleColision(GiftAddingTime&) override {};

private:

};