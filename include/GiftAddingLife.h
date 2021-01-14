#pragma once

#include"Gift.h"
#include"Hero.h"

class GiftAddingLife : public Gift
{
public:
	GiftAddingLife(const sf::Vector2f& loc, const sf::Vector2f&);;
	~GiftAddingLife()override = default;


	virtual void handleColision(GameObj& obj) override;
	virtual void handleColision(Rope& Obj) override {};
	virtual void handleColision(Hero& Obj) override ;
	virtual void handleColision(Floor& obj)override {};
	virtual void handleColision(Ladder& obj) override {};
	virtual void handleColision(Coin&) override {};
	virtual void handleColision(Enemy&) override {};
	virtual void handleColision(GiftAddingLife&) override {};
	virtual void handleColision(GiftAddingScore&) override {};
	virtual void handleColision(GiftAddingEnemy&) override {};
private:

};
