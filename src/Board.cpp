#include "Board.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include "SingletonPicture.h"
#include "Floor.h"
#include "Ladder.h"
#include "Rope.h"
#include <iostream>
#include "Coin.h"
#include "SingletonSound.h"
#include <string>
#include "RandomEnemy.h"
#include "SmartEnemy.h"
#include "HorizontalEnemy.h"
#include "Gift.h"
#include"GiftAddingLife.h"
#include"GiftAddingEnemy.h"
#include"GiftAddingScore.h"
#include "SingletonFont.h"
#include "GiftAddingTime.h"
//===============constructor ==============

Board::Board():m_width(0), m_height(0), m_cellHight(0), m_cellWidth(0), m_hero()
{
}

Board::Board(std::vector<std::vector<char>> file, int PlayerSelection,
             int level)
{
    m_height = file.size();
    m_width = file[1].size();
    readFile(file, PlayerSelection, level);
}
//====================================================
void Board::draw(sf::RenderWindow& window)const
{
    //draw static object
    for (auto& e : m_staticObjects)
        for (auto& d : e) {
            if(d)
            d->draw(window);
        }
    //draw mov object
    for (auto& movObj : m_movingObjects)
    {
        movObj->draw(window);
    }

}


//====================================================
void Board::createObject(char input, const sf::Vector2f &location,
                         int PlayerSelection, int i, int level)
{
    sf::Vector2f boardsize((float)m_height, (float)m_width);
    
    switch (input)
    {
       
    case ENEMY:
        createEnemysVector(location, PlayerSelection);
        break;

    case FLOOR:
       
      m_staticObjects[i].push_back(std::move(std::make_unique<Floor>(location, boardsize)));
        
       break;

    case ROPE:
        m_staticObjects[i].push_back(std::move(std::make_unique<Rope>(location, boardsize)));
        break;

    case COIN:
        m_staticObjects[i].push_back(std::move(std::make_unique<Coin>(location, boardsize,level)));

        break;

    case LADDER:
        m_staticObjects[i].push_back(std::move(std::make_unique<Ladder>(location, boardsize)));
        break;
    case GIFT:
        addGiftToStaticVector(location, boardsize, i);
    }

}
//============================================
//there is ENEMYTYPES (set as 3 for now ) of enemy types
//this function add the vector enemy
//the type of the enemy will be randomly
//============================================

void Board::createEnemysVector(const sf::Vector2f& location, int PlayerSelection)
{

    sf::Vector2f boaradsize(m_cellWidth,m_cellWidth);
   int ChooseEnemy = std::rand() % (ENEMYTYPES-1)+1;
   //int ChooseEnemy = 0;


    switch (ChooseEnemy)
    {
    case RANDOM:
        m_movingObjects.push_back(std::move(std::make_unique<RandomEnemy>(location, PlayerSelection,boaradsize)));

        break;
    case Horizontal:
        m_movingObjects.push_back(std::move(std::make_unique<HorizontalEnemy>(location, PlayerSelection,boaradsize)));

        break;
    case SMART:
        m_movingObjects.push_back(std::move(std::make_unique<SmartEnemy>(location, PlayerSelection,boaradsize)));

        break;
    }



}
//============================================
void Board::moveCharacters(float deltaTime, const  std::vector <std::vector<char>>& file) {

    for (auto &movObj : m_movingObjects) {
        if (!movObj->getIsfalling()) {
            {
                //m_hero->GetPosition();
                movObj->UpdateLocation(deltaTime, m_hero->getSprite().getPosition(), file, *this);
            }
        }
    }

}
//============================================

bool Board::checkIfObjectFalling(float deltatime) {

    for(auto& movingobj : m_movingObjects)
        isObjectIsFalling(deltatime,*movingobj.get());
    return true;
}

//============================================
void Board::readFile(const std::vector<std::vector<char>> &file, int PlayerSelection,
                int level)
{
    sf::Vector2f location;
    m_staticObjects.clear();
    m_movingObjects.clear();

    m_cellWidth = (BOARDWIDTH / float(m_width));
    m_cellHight = (BOARDHEIGHT / float(m_height));

    m_staticObjects.resize(m_height);

    //calculate the size of the middle of singal cell
    // sub the size of the image frame
    float tx = (BOARDWIDTH / float(m_width) / 2);
    float ty = (BOARDHEIGHT / float(m_height) / 2);
    location.x = tx;
    location.y = ty;
    sf::Vector2f heroloc;
    // take char with the file and put vector
    for (int i = 0; i < m_height; ++i)
    {

        for (int j = 0; j < m_width; ++j)
        {

            if (file[i][j] == SPACE)
                m_staticObjects[i].push_back(nullptr);
            else if (file[i][j] == HERO)
                heroloc = location;
            else
                createObject(file[i][j], location, PlayerSelection, i, level);

            location.x += (2 * tx);
        }

        location.x = tx;
        location.y += (2 * ty);

    }

    m_movingObjects.push_back(std::move(std::make_unique<Hero>(heroloc, PlayerSelection,sf::Vector2f(m_cellWidth,m_cellHight))));
    m_hero = (Hero*)m_movingObjects[m_movingObjects.size() - 1].get();


}



//==========================================

int Board::checkCollisions(float deltaTime)
{

    for(auto & mov:m_movingObjects)
        handleCollisions(*mov);

    if(m_hero->getIsOff())
    return true;

    return false;

}
//==================================================

bool Board::isObjectIsFalling(float deltaTime,MovingObjects& movingobject )
{

    float index = m_cellHight;
    int i;
        for (i = 0;index < movingobject.getSprite().getPosition().y; ++i) {
            index += m_cellHight;
        }


        sf::Sprite checkdown = movingobject.getSprite();
        checkdown.move(0, FALLINGSPEED * deltaTime);

        for (int j = i; j < m_staticObjects.size(); ++j)
        {
            for (auto &d : m_staticObjects[j])
            {
                if (d) {
                    if(!movingobject.isObjectIsStandable(*d))
                            continue;
                    else
                        if (checkdown.getGlobalBounds().intersects(d->getSprite().getGlobalBounds())) {
                            movingobject.setIsfalling(false);

                            return false;
                        }
                }

            }
        }
        movingobject.move(0, FALLINGSPEED * deltaTime);
        movingobject.setIsfalling(true);




    return true;
}


//==================================================
void Board::ResetMap()
{

    for(auto& staticObj : m_staticObjects)
        for (auto& rowStaticObj : staticObj)
        {
            if (rowStaticObj)
                rowStaticObj->resetObj();
        }

    for (auto& movObj : m_movingObjects)
        movObj->resetObj();
    m_hero->resetTime();
}
//==================================================

float Board::getCellHight() const {
    return m_cellHight;
}
//==================================================

float Board::getCellWidth() const {
    return m_cellWidth;
}

//==================================================

void Board::addGiftToStaticVector(const sf::Vector2f& location, sf::Vector2f boardsize, int i )
{
    int ChoosEnemy = std::rand() % TYPESOFGIFS;

    switch (ChoosEnemy)
    {
    case AddLife:
         m_staticObjects[i].push_back(std::move(std::make_unique <GiftAddingLife>(location, boardsize)));
         break;
    case AddScore:
        m_staticObjects[i].push_back(std::move(std::make_unique <GiftAddingScore>(location, boardsize)));
        break;
    case AddEnemy:
         m_staticObjects[i].push_back(std::move(std::make_unique <GiftAddingEnemy>(location, boardsize)));
        break;
    case AddTime:
        m_staticObjects[i].push_back(std::move(std::make_unique <GiftAddingTime>(location, boardsize)));
            break;
    } 
}
//==================================================
void Board::handleCollisions(GameObj &obj)
{

 for(auto & movingobject :m_movingObjects)
 {
     if(obj.collisonWith(*movingobject))
     {
         if (m_hero->getIsOff())
             return;

         obj.handleColision(*movingobject);
         
     }
 }

    for (auto& staticObjects : m_staticObjects) {
        for (auto &stsobj : staticObjects) {

            if (stsobj)
                if (!stsobj->getIsOff())
                {
                    if (obj.collisonWith(*stsobj))
                    {
                        obj.handleColision(*stsobj);
                    }
                }

        }
    }
    
}
//==================================================
void Board::checkIfHeroDig(const sf::Time &time) {

    m_hero->digHole(*this, time);

}
//==================================================

void Board::andEnemyRandomly(int playerselect) {

    int i,j;
    do {
         i = rand() % m_height;
         j = rand() %m_width;
    }
    while(m_staticObjects[i][j] != nullptr);

    createEnemysVector(sf::Vector2f( m_cellWidth/2+j*m_cellWidth,
                                     m_cellHight/2+m_cellHight*i),playerselect);


}
//==================================================

void Board::restroreGameObjects(const sf::Time &time) {

    for(auto &staticObjects : m_staticObjects)
        for(auto& staticObjectsi : staticObjects )
            if(staticObjectsi)
                staticObjectsi->restoreGameObj(time, 0);
    for(auto&  movi : m_movingObjects)
        movi->restoreGameObj(time, m_cellHight);

}
//==================================================

int Board::getHeroScore() {
   return m_hero->getScore();
}
//==================================================

int Board::getHerolife() {
    return m_hero->getLife();
}
//==================================================

MovingObjects * Board::getSMovingObjectsFromVector(int i) {
    return m_movingObjects[i].get();
}
//==================================================

StaticObjects *Board::getStaticObjectsFromVector(int i, int j) {
    return m_staticObjects[i][j].get();
}
//==================================================

size_t Board::getHeight() {
    return m_height;
}
//==================================================

size_t Board::getWidth() {
    return m_width;
}
//==================================================

int Board::getMovingObjecVectorSize() {
    return m_movingObjects.size();
}
//==================================================

void Board::setHeroLife(int life) {
    m_hero->setLife(life);

}
//==================================================
void Board::setHeroScore(int score ) {
        m_hero->setScore(score);
}

//==================================================
