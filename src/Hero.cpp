#include "Hero.h"
#include "Macros.h"
#include "Floor.h"
#include "Controller.h"
#include "Enemy.h"
#include "Board.h"
#include "Ladder.h"
#include <cmath>

Hero::Hero(const sf::Vector2f &loc, int HeroSelection,
           sf::Vector2f boardsize) : m_life(3), m_score(0)
{

	if (HeroSelection == HEROASJERRY)
		m_sprite.setTexture(SingletonPicture::instance().getHerojerryTexture());

	else if(HeroSelection == HEROASRICK)
		m_sprite.setTexture(SingletonPicture::instance().getHeroRickTexture());


    m_sprite.setPosition(loc);
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));
    m_sprite.setScale(sf::Vector2f(boardsize.x/(m_sprite.getTexture()->getSize().x+FACTORSCAL) ,(boardsize.y/(m_sprite.getTexture()->getSize().y+FACTORSCAL))));


    m_collectCoinSound.setBuffer(SingletonSound::instance().getMCollectCoin());
    m_collectGiftSound.setBuffer(SingletonSound::instance().getMCollectGift());
    m_collectDeadSound.setBuffer(SingletonSound::instance().getMDead());
	m_firstPosition = loc;
    m_LastPosition = loc;
    m_lastdigtime = sf::Time::Zero;
}
//====================================================

int Hero::getLife()
{
	return m_life;
}
//====================================================

int Hero::getScore()
{
	return m_score;
}
//====================================================

void Hero::setLife(int life)
{
    if(m_life > life)playCollectDeadSound();
	m_life = life;
}

//====================================================
void Hero::UpdateLocation(float time, sf::Vector2f, const  std::vector <std::vector<char>>&, Board&)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
	    if(m_isUpAvail)
		this->move( 0,-HEROSPEED * time);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
        this->move(0,HEROSPEED * time);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->move(-HEROSPEED *time, 0);
		this->DrawLeftside();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->move(HEROSPEED *time, 0);
		this->DrawRightside();
	}
}
//====================================================
void Hero::handleColision(GameObj& obj)
{
	obj.handleColision(*this);
}
//====================================================
void Hero::handleColision(Rope& Obj) 
{
    m_isUpAvail =false;

}
//====================================================
void Hero::handleColision(Floor& obj)
{
    m_sprite.setPosition(m_LastPosition);
    m_isUpAvail =false;
}
//====================================================
void Hero::handleColision(Ladder& obj)
{
    if (std::abs(m_sprite.getPosition().x -obj.getSprite().getPosition().x )
            < this->m_sprite.getTexture()->getSize().x/2u)

        m_isUpAvail =true;

}
//====================================================
void Hero::handleColision(Coin&obj)
{
    m_isUpAvail =false;
	m_score+= obj.getValue();
	playCollectCoinSound();

}
//====================================================

void Hero::handleColision(Enemy& obj )
{   //if(!obj.isIsingidedfloor())
{       m_isOff = true;
        m_life--;
        playCollectDeadSound();
    }
}
//====================================================

void Hero::handleColision(GiftAddingLife&)
{
    playCollectGiftSound();
	m_life++;
}
//====================================================

void Hero::handleColision(GiftAddingScore& gift)
{
    playCollectGiftSound();
	m_score += 300;
}

//====================================================
void Hero::addScore(int score)
{
	m_score += score;
}
//====================================================
void Hero::playCollectGiftSound() {
    m_collectGiftSound.play();

}
//====================================================
void Hero::playCollectCoinSound() {

    m_collectCoinSound.play();

}
//====================================================

void Hero::playCollectDeadSound() {

    m_collectDeadSound.play();

}
//======================================================

void Hero::handleColision(Hero &) {

}
//======================================================
void Hero::digHole(Board& board,const sf::Time &time)
{
    float coll;
    //This statement block the the option to dig more
    // then a one hole in <HERODIGDELTATIME> millisecond
    if(time.asMilliseconds()-m_lastdigtime.asMilliseconds()<HERODIGDELTATIME)
        return;

     //Check if the player want to dig otherwise the function end
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        coll = 1;

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
       coll =-1;
    else return;

        auto index = board.mapPixelToIndexes(getSprite().getPosition());

         index.x+=coll;

        if (index.y >0 && index.x >= 0 && index.y < board.getHeight() && index.x < board.getWidth())
        {
            std::cout <<index.x  <<" "<<index.y << std::endl;
            if(board.getStaticObjectsFromVector((int)index.y-1, (int)index.x) != nullptr &&
            !board.getStaticObjectsFromVector((int)index.y-1, (int)index.x)->getIsOff())return;
            auto staticobj = board.getStaticObjectsFromVector((int)index.y,(int) index.x);
            if (staticobj)
            {
                if (staticobj->isObjectDigable(time))
                {
                    auto loc = staticobj->getSprite().getPosition();
                    loc.y -= board.getCellHight();
                    auto rec = sf::RectangleShape(sf::Vector2f(board.getCellWidth()/2,board.getCellHight()/2));
                   // auto rec = sf::RectangleShape(sf::Vector2f(m_sprite.getGlobalBounds().width,m_sprite.getGlobalBounds().height));
                    //rec.setScale(m_sprite.getScale());
                    rec.setPosition(loc);
                    rec.setOrigin(board.getCellWidth()/4,board.getCellHight()/2);

                    for (int i = 0; i < board.getMovingObjecVectorSize(); ++i)
                    {
                       if(rec.getGlobalBounds().intersects( board.getSMovingObjectsFromVector(i)->getSprite().getGlobalBounds()))
                        return;
                    }

                    m_lastdigtime = time;
                    staticobj->setIsOff(true);
                }

            }
        }
    }
//====================================================
bool Hero::isObjectIsStandable(StaticObjects &stas) {
    return stas.isObjectIsStandable(*this);
}
//====================================================
void Hero::resetObj()
{
	this->SetPosition(m_firstPosition);
	this->setIsOff(false);
}
//====================================================
void Hero::resetTime()
{
	m_lastdigtime = sf::seconds(0);
}
//====================================================
void Hero::handleColision(GiftAddingTime &) {
    playCollectGiftSound();

}
//====================================================
void Hero::handleColision(GiftAddingEnemy &) {
    playCollectGiftSound();
}
//====================================================