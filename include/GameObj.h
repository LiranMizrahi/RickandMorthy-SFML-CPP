#pragma once
#include <SFML/Graphics.hpp>

class Rope;
class Hero;
class Floor;
class Ladder;
class MovingObjects;
class Coin;
class Enemy;
class GiftAddingLife;
class GiftAddingScore;
class GiftAddingEnemy;
class GiftAddingTime;

class GameObj {


public:
	GameObj();
	GameObj(const sf::Texture&, const sf::Vector2f&, const sf::Vector2f &board_size);
	virtual ~GameObj() = default;;

	bool collisonWith(const GameObj&)const;
	sf::Sprite getSprite()const;

    void draw(sf::RenderWindow&)const;
    virtual void handleColision(GameObj& obj) = 0;
	virtual void handleColision(Floor& obj) = 0;
	virtual void handleColision(Ladder& obj) = 0;
	virtual void handleColision(Rope& Obj) = 0;
	virtual void handleColision(Hero& Obj) = 0;
	virtual void handleColision(Coin& Obj) = 0;
	virtual void handleColision(Enemy& Obj) = 0;
	virtual void handleColision(GiftAddingLife& Obj) = 0;
	virtual void handleColision(GiftAddingScore& Obj) = 0;
	virtual void handleColision(GiftAddingEnemy& Obj) = 0;
	virtual void handleColision(GiftAddingTime& Obj) = 0;
    virtual void restoreGameObj(const sf::Time &);



	bool getIsOff()const;
	virtual void setIsOff(bool isoff);


protected:
	sf::Sprite m_sprite;
    bool m_isOff = false;

private:
};