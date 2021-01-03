#pragma once
#include <SFML/Graphics.hpp>

class GameObj {


public:
	GameObj();
	GameObj(const sf::Texture&, const sf::Vector2f&);
	~GameObj();

	bool collisonWith(const GameObj&)const;

  void draw(sf::RenderWindow&, const sf::Vector2f&)const;


  /*virtual void handleColision(Floor& obj);
	virtual void handleColision(Ladder& obj);
	virtual void handleColision(Rope& obj);*/

protected:
	sf::Sprite m_sprite;

private:
	

};