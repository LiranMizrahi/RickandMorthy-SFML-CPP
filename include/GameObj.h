#pragma once
#include <SFML/Graphics.hpp>

class Rope;
class Hero;
class Floor;
class Ladder;
class MovingObjects;
class Coin;
class Enemy;
class PresentAddingLife;
class PresentAddingScore;
class PresentAddingEnemy;
class GameObj {


public:
	GameObj();
	GameObj(const sf::Texture&, const sf::Vector2f&, const sf::Vector2f &board_size);
	virtual ~GameObj() = default;;

	bool collisonWith(const GameObj&)const;
	sf::Sprite getSprite()const;

    void draw(sf::RenderWindow&, const sf::Vector2f&)const;
    virtual void handleColision(GameObj& obj) = 0;
	virtual void handleColision(Floor& obj) = 0;
	virtual void handleColision(Ladder& obj) = 0;
	virtual void handleColision(Rope& Obj) = 0;
	virtual void handleColision(Hero& Obj) = 0;
	virtual void handleColision(Coin& Obj) = 0;
	virtual void handleColision(Enemy& Obj) = 0;
	virtual void handleColision(PresentAddingLife& Obj) = 0;
	virtual void handleColision(PresentAddingScore& Obj) = 0;
	virtual void handleColision(PresentAddingEnemy& Obj) = 0;


	bool getIsOff()const;


protected:
	sf::Sprite m_sprite;
    bool m_isOff = false;

private:
};