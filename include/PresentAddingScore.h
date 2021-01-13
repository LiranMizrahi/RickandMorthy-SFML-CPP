#pragma once

#include"Present.h"
#include"Hero.h"
#include<iostream>

class PresentAddingScore : public Present
{
public:
	PresentAddingScore(const sf::Vector2f& loc, const sf::Vector2f&);
	~PresentAddingScore()override = default;


	virtual void handleColision(GameObj& obj) override {};
	virtual void handleColision(Rope& Obj) override {};
	virtual void handleColision(Hero& Obj) override ;
	virtual void handleColision(Floor& obj)override {};
	virtual void handleColision(Ladder& obj) override {};
	virtual void handleColision(Coin&) override {};
	virtual void handleColision(PresentAddingLife&) override {};
	virtual void handleColision(PresentAddingScore&) override {};
	virtual void handleColision(PresentAddingEnemy&) override {};

private:

};