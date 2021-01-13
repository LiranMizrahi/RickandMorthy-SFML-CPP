#pragma once
#include "GameObj.h"
#include "SingletonPicture.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"
#include "Macros.h"
#include"Hero.h"

const int ENEMYTYPES =3;

enum e_Enemy {
    SMART =1,RANDOM,Horizontal
};
class Enemy : public MovingObjects {
public:


	  Enemy(const sf::Vector2f&, int);
     ~Enemy() override = default;

      void UpdateLocation(float time) override{};

	 void handleColision(GameObj& obj) override;
	 void handleColision(Rope& Obj) override;
	 void handleColision(Hero& Obj) override ;
	 void handleColision(Floor& obj)override;
	 void handleColision(Ladder& obj) override ;
	 void handleColision(Coin&) override {};
	 void handleColision(Enemy& Obj) override {};
	

private:
	
};