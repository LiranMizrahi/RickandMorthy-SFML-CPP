#pragma once
#include "GameObj.h"
#include "StaticObjects.h"

class MovingObjects : public GameObj
{
public:

	MovingObjects();
	~MovingObjects()  override = default;
	MovingObjects(const sf::Texture& tex, const sf::Vector2f& loc, const sf::Vector2f&);
	virtual void move(float,float);
	void SetPosition(const sf::Vector2f&);
	void DrawLeftside();
	void DrawRightside();
    void setLastPosition(sf::Vector2f);
    virtual void UpdateLocation(float) = 0;
    void setStartPosion();
    virtual bool isObjectIsStandable(StaticObjects&) = 0;
    bool isIsUpAvail() const;
    void setIsUpAvail(bool mIsUpAvail);
    bool getIsfalling() const;
    void setIsfalling(bool);
    const sf::Vector2f &getLastPosition() const;


protected:
    sf::Vector2f m_firstPosition;
    sf::Vector2f m_LastPosition;
    bool m_isfalling =false;
    bool m_isUpAvail = false;



};