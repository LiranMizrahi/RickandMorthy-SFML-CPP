#pragma once
#include "GameObj.h"


class MovingObjects : public GameObj
{
public:

	MovingObjects();
	~MovingObjects() override = default;
	MovingObjects(const sf::Texture& tex, const sf::Vector2f& loc, const sf::Vector2f&);
	void move(float,float);
	sf::Vector2f GetPosition()const;
	void SetPosition(const sf::Vector2f&);
	void DrawLeftside();
	void DrawRightside();
    void setLastPosition(sf::Vector2f);
    virtual void UpdateLocation(float) = 0;
    void setStartPosion();



protected:
    sf::Vector2f m_firstPosition;
    sf::Vector2f m_LastPosition;
    bool m_isfalling =false;
    bool m_isUpAvail = false;
    bool m_isDownAvail = false;
public:
    bool isIsUpAvail() const;
    void setIsUpAvail(bool mIsUpAvail);
    bool isIsDownAvail() const;
    void setIsDownAvail(bool mIsDownAvail);


public:
    bool getIsfalling() const;

    void setIsfalling(bool);

public:
    const sf::Vector2f &getLastPosition() const;


};