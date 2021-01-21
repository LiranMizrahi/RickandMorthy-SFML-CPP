#pragma once
#include "GameObj.h"
#include "Singletons/SingletonPicture.h"
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

      Enemy() = default;
	  Enemy(const sf::Vector2f &loc, int EnemySelection,
            sf::Vector2f boardsize);
    virtual ~Enemy()  = default;
	//===================public function=================
	// handleColision for all objects
	 void handleColision(GameObj& obj) override;
	 void handleColision(Rope& Obj) override;
	 void handleColision(Hero& Obj) override ;
	 void handleColision(Floor& obj)override;
	 void handleColision(Ladder& obj) override ;
	 void handleColision(Coin&) override {};
	 void handleColision(Enemy& Obj) override {};
	 void handleColision(GiftAddingLife&) override {};
	 void handleColision(GiftAddingScore&) override {};
	 void handleColision(GiftAddingEnemy&) override {};
	 void handleColision(GiftAddingTime&) override {};
	 // if object not fell into the pit
     virtual bool isObjectIsStandable(StaticObjects &stas)override;
	 //
     bool restoreGameObj(const sf::Time &, float cellheight) override;
     void resetObj()override;
     void setDiggedfloortime(const sf::Time &diggedfloortime);
     void setIsingidedfloor(bool isingidedfloor);
     bool isIsingidedfloor() const;

//=========private members ======================
private:

     bool m_isingidedfloor =false;
    sf::Time m_diggedfloortime;



};