#include "Hero.h"
#include "Macros.h"
#include "Floor.h"
#include "Controller.h"
#include "Enemy.h"
#include "Board.h"
#include "Ladder.h"

Hero::Hero(const sf::Vector2f &loc, int HeroSelection,
           sf::Vector2f boardsize) : m_life(3), m_score(0)
{

	if (HeroSelection == HEROASJERRY)
	{
		m_sprite.setTexture(SingletonPicture::instance().getHerojerryTexture());
	}
	else if(HeroSelection == HEROASRICK)
	{
		m_sprite.setTexture(SingletonPicture::instance().getHeroRickTexture());
	}

    m_sprite.setPosition(loc);
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize() / 2u));
    m_sprite.setScale(sf::Vector2f(boardsize.x/(m_sprite.getTexture()->getSize().x+25) ,(boardsize.y/(m_sprite.getTexture()->getSize().y+25))));


    m_collectCoinSound.setBuffer(SingletonSound::instance().getMCollectCoin());
    m_collectGiftSound.setBuffer(SingletonSound::instance().getMCollectGift());
    m_collectDeadSound.setBuffer(SingletonSound::instance().getMDead());
	m_firstPosition = loc;
    m_LastPosition = loc;
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
	    //    if (m_isDownAvail)
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
   // this->m_sprite.setRotation(0.f);
}
//====================================================
void Hero::handleColision(Ladder& obj)
{
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
{   if(!obj.isIsingidedfloor())
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
void Hero::setScore(int score)
{
	m_score = score;
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
    int row,col;
    //This statement block the the option to dig more
    // then a one hole in <HERODIGDELTATIME> millisecond
    if(time.asMilliseconds()-m_lastdigtime.asMilliseconds()<HERODIGDELTATIME)
        return;

     //Check if the player want to dig otherwise the function end
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        col = 1;

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
       col =-1;
    else return;

    float pointposition= board.getCellHight();
    for ( row = 1; pointposition <= this->getSprite().getPosition().y; ++row)
        pointposition += board.getCellHight();


        pointposition = board.getCellWidth();

        for (; pointposition <= this->getSprite().getPosition().x; ++col)
            pointposition += board.getCellWidth();

         //check if start from 1 is ok
         //row++;

        if (row > 0 && col >= 0 && row < board.getHeight() && col < board.getWidth())
        {
            if(board.getStaticObjectsFromVector(row-1, col) != nullptr)return;
            auto staticobj = board.getStaticObjectsFromVector(row, col);
            if (staticobj)
            {
                if (staticobj->isObjectDigable(time))
                {
                    auto loc = staticobj->getSprite().getPosition();
                    loc.y -= board.getCellHight();
                    auto rec = sf::RectangleShape(sf::Vector2f(board.getCellWidth()*0.70,board.getCellHight()*0.70));
                    rec.setPosition(loc);
                    rec.setOrigin(board.getCellWidth()/2,board.getCellHight()/2);

                    for (int i = 0; i < board.getMovingObjecVectorSize(); ++i) {
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