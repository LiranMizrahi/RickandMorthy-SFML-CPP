#pragma once

#include"Present.h"
#include"Hero.h"

class PresentAddingLife : public Present
{
public:
	PresentAddingLife(const sf::Vector2f& loc, const sf::Vector2f&);;
	~PresentAddingLife()override = default;


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
