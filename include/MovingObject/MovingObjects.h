#pragma once
#include "GameObj.h"
#include "StaticObjects/StaticObjects.h"
class Board;
class MovingObjects : public GameObj
{
public:

	MovingObjects() = default;
	MovingObjects(const sf::Texture& tex, const sf::Vector2f& loc, const sf::Vector2f&);
    virtual ~MovingObjects() = default;

    //===================public function=================
    void setIsUpAvail(bool);
    bool getIsfalling() const;
    void setIsfalling(bool);
    virtual void move(float,float);
	void SetPosition(const sf::Vector2f&);
	void DrawLeftside();
	void DrawRightside();
	virtual void UpdateLocation(float , sf::Vector2f, const  std::vector <std::vector<char>>&, Board&) = 0;
    virtual bool isObjectIsStandable(StaticObjects&) = 0;



protected:
    //=========protected members======================
    sf::Vector2f m_firstPosition;
    sf::Vector2f m_LastPosition;
    bool m_isfalling =false;
    bool m_isUpAvail = false;


};