#pragma once
#include "GameObj.h"
#include "SingletonPicture.h"
#include <SFML/Graphics.hpp>
#include "MovingObjects.h"
#include "Macros.h"
#include"Hero.h"

const int ENEMYTYPES =3;

enum e_Enemy {
    SMART =0,RANDOM,Horizontal
};
class Enemy : public MovingObjects {
public:


	  Enemy(const sf::Vector2f &loc, int EnemySelection,
            sf::Vector2f boardsize);
     ~Enemy() override = default;

      void UpdateLocation(float time) override{};

	 void handleColision(GameObj& obj) override;
	 void handleColision(Rope& Obj) override;
	 void handleColision(Hero& Obj) override ;
	 void handleColision(Floor& obj)override;
	 void handleColision(Ladder& obj) override ;
	 void handleColision(Coin&) override {};
	 void handleColision(Enemy& Obj) override {};
	 virtual void handleColision(GiftAddingLife&) override {};
	 virtual void handleColision(GiftAddingScore&) override {};
	 virtual void handleColision(GiftAddingEnemy&) override {};
	 virtual void handleColision(GiftAddingTime&) override {};
     virtual bool isObjectIsStandable(StaticObjects &stas)override;
     virtual void restoreGameObj(const sf::Time &, float cellheight) override;
     virtual void resetObj()override;
    const sf::Time &getDiggedfloortime() const;
    void setDiggedfloortime(const sf::Time &diggedfloortime);
    void setIsingidedfloor(bool isingidedfloor);
private:

     bool m_isingidedfloor =false;
    sf::Time m_diggedfloortime = sf::Time::Zero;



};