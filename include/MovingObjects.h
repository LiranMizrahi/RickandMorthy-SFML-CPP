#pragma once
#include "GameObj.h"
#include "StaticObjects.h"
class Board;
class MovingObjects : public GameObj
{
public:

	MovingObjects() = default;
	virtual ~MovingObjects() = default;
	MovingObjects(const sf::Texture& tex, const sf::Vector2f& loc, const sf::Vector2f&);

    void setIsUpAvail(bool mIsUpAvail);
    bool getIsfalling() const;
    void setIsfalling(bool);

    virtual void move(float,float);
	void SetPosition(const sf::Vector2f&);
	void DrawLeftside();
	void DrawRightside();
	virtual void UpdateLocation(float , sf::Vector2f, const  std::vector <std::vector<char>>&, Board&) = 0;
    virtual bool isObjectIsStandable(StaticObjects&) = 0;



protected:
    sf::Vector2f m_firstPosition;
    sf::Vector2f m_LastPosition;
    bool m_isfalling =false;
    bool m_isUpAvail = false;


};