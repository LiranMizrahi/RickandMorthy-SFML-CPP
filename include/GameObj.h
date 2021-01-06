#pragma once
#include <SFML/Graphics.hpp>

class Rope;
class Hero;
class Floor;
class Ladder;
class MovingObjects;
class Coin;
class GameObj {


public:
	GameObj();
	GameObj(const sf::Texture&, const sf::Vector2f&, const sf::Vector2f &board_size);
	virtual ~GameObj() = default;;

	bool collisonWith(const GameObj&)const;

  void draw(sf::RenderWindow&, const sf::Vector2f&)const;

    virtual void handleColision(GameObj& obj) = 0;
	virtual void handleColision(Floor& obj) = 0;
	virtual void handleColision(Ladder& obj) = 0;
	virtual void handleColision(Rope& Obj) = 0;
	virtual void handleColision(Hero& Obj) = 0;
	virtual void handleColision(Coin& Obj) = 0;



protected:
	sf::Sprite m_sprite;

private:
	

};