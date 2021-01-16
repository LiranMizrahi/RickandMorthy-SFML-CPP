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

Board::Board(std::vector <std::vector<char>> file , int PlayerSelection)
{
    m_height = file.size();
    m_width = file[1].size();
    readFile(file, PlayerSelection);
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
void Board::createObject(char input, const sf::Vector2f & location,int PlayerSelection, int i)
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
        m_staticObjects[i].push_back(std::move(std::make_unique<Coin>(location, boardsize)));

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
    srand((unsigned int)time(NULL));
    int ChooseEnemy = std::rand() % ENEMYTYPES;



    switch (ChooseEnemy)
    {
    case RANDOM:
        m_movingObjects.push_back(std::move(std::make_unique<RandomEnemy>(location, PlayerSelection)));

        break;
    case Horizontal:
        m_movingObjects.push_back(std::move(std::make_unique<HorizontalEnemy>(location, PlayerSelection)));

        break;
    case SMART:
        m_movingObjects.push_back(std::move(std::make_unique<SmartEnemy>(location, PlayerSelection)));

        break;
    }


}
//============================================
void Board::moveCharacters(float deltaTime) {

    for (auto &movObj : m_movingObjects) {
        if (!movObj->getIsfalling()) {

            movObj->UpdateLocation(deltaTime);
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
void Board::readFile(std::vector <std::vector<char>> file, int PlayerSelection)
{
    sf::Vector2f location;
    m_staticObjects.clear();
    m_movingObjects.clear();


    // m_cellWidth = (BOARDHEIGHT / float(m_height));
  //   m_cellHight = (BOARDWIDTH / float(m_width));

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
        //   m_staticObjects[i];
        for (int j = 0; j < m_width; ++j)
        {

            if (file[i][j] == ' ')
                m_staticObjects[i].push_back(nullptr);
            else if (file[i][j] == HERO)
                heroloc = location;
            else
                createObject(file[i][j], location, PlayerSelection, i);

            location.x += (2 * tx);
        }

        location.x = tx;
        location.y += (2 * ty);

    }

    m_movingObjects.push_back(std::move(std::make_unique<Hero>(heroloc, PlayerSelection)));

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
                    if(!d->isObjectIsStandable(movingobject))
                            continue;

                    if (!d->getIsOff())
                        if (checkdown.getGlobalBounds().intersects(
                                d->getSprite().getGlobalBounds())) {
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
void Board::printGameStatus(sf::RenderWindow & window, int levelnum, sf::Time timeLevel, sf::Clock time , bool m_isOnTime)
{
    initGamestatusbar();

    std::string scorestr = "000000";
    if(m_hero->getScore()>=1000000)
        scorestr+="0";

    scorestr.replace(scorestr.size()-std::to_string(m_hero->getScore()).size(),
                     std::to_string(m_hero->getScore()).size(),std::to_string(m_hero->getScore()));
    m_scoreText.setString("Score:"+scorestr);
    m_levelText.setString("Level:000" + std::to_string(levelnum));
    m_lifeText.setString("Life:000"+std::to_string(m_hero->getLife()));

    if (m_isOnTime)
    {
        m_timeTheLevel.setString("Time:" + std::to_string(timeLevel.asSeconds() - time.getElapsedTime().asSeconds()));
    }
    else
    {
        m_timeTheLevel.setString("Time: 9999");
    }


    m_lifeText.setOutlineColor(sf::Color::White);
    m_scoreText.setPosition(30,BOARDHEIGHT);
    m_levelText.setPosition(m_scoreText.getPosition().x+m_scoreText.getGlobalBounds().width +30,BOARDHEIGHT);
    m_lifeText.setPosition(m_levelText.getPosition().x+m_levelText.getGlobalBounds().width+30,BOARDHEIGHT);
    m_timeTheLevel.setPosition(m_lifeText.getPosition().x + m_lifeText.getGlobalBounds().width + 30, BOARDHEIGHT);

    window.draw(m_lifeText);
    window.draw(m_scoreText);
    window.draw(m_levelText);
   // if(false)
    window.draw(m_timeTheLevel);

}
//==================================================

void Board::initGamestatusbar()
{

    m_scoreText.setFont(SingletonFont::instance().getMBoardstatus());
    m_levelText.setFont(SingletonFont::instance().getMBoardstatus());
    m_lifeText.setFont(SingletonFont::instance().getMBoardstatus());
    m_timeTheLevel.setFont(SingletonFont::instance().getMBoardstatus());

    m_lifeText.setCharacterSize(50);
    m_scoreText.setCharacterSize(50);
    m_levelText.setCharacterSize(50);
    m_timeTheLevel.setCharacterSize(50);

}

//==================================================
void Board::ResetMap()
{

    for(auto& staticObj : m_staticObjects)
        for (auto& rowStaticObj : staticObj)
        {
            if(rowStaticObj)
            rowStaticObj->setIsOff(false);
        }

    for (auto& movObj : m_movingObjects)
        movObj->setStartPosion();


        m_hero->setIsOff(false);
}

//==================================================

void Board::addGiftToStaticVector(const sf::Vector2f& location, sf::Vector2f boardsize, int i )
{
    int ChoosEnemy = 2; //std::rand() % TYPESOFGIFS;

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
void Board::checkIfHeroDig() {

    m_hero->digHole(m_staticObjects,m_cellHight,m_cellWidth,m_height,m_width);

}
//==================================================

void Board::andEnemyRandomly(int playerselect) {

    int i,j;
    do {
         i = rand()% m_height;
         j = rand() %m_width;
    }
    while(m_staticObjects[i][j] != nullptr);

    createEnemysVector(sf::Vector2f( m_cellWidth/2+j*m_cellWidth,m_cellHight/2+m_cellHight*i),playerselect);




}
//==================================================
