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
#include "Present.h"
#include"PresentAddingLife.h"
#include"PresentAddingEnemy.h"
#include"PresentAddingScore.h"

//===============constructor ==============

Board::Board(std::ifstream& file , int PlayerSelection)
{

    sf::Vector2f location;
    char input;
    m_staticObjects.clear();
    m_movingObjects.clear();
	file >> m_width >> m_height; // take size map
	file.get();

    cellwidth = (BOARDHEIGHT / float(m_height));
    cellhight = (BOARDWIDTH/ float(m_width));
    m_staticObjects.resize(m_height);

    //calculate the size of the middle of singal cell 
    // sub the size of the image frame
    float tx = (BOARDWIDTH / float(m_width) / 2);
    float ty = (BOARDHEIGHT / float(m_height) / 2);
    location.x = tx;
    location.y = ty;
    float x_location = location.x;
    sf::Vector2f heroloc;
    // take char with the file and put vector
    for (int i = 0; i < m_height; ++i)
    {
         //   m_staticObjects[i];
        for (int j = 0; j < m_width; ++j)
        {
               input = file.get();
               if(input == ' ')
                   m_staticObjects[i].push_back(nullptr);
               else if(input == '@')
                heroloc = location;
               else
                   createObject(input, location, PlayerSelection, i);

                   location.x += (2 * tx);
        }
            file.get();
            location.x = x_location;
            location.y += (2 * ty);

    }
    m_movingObjects.push_back(std::move(std::make_unique<Hero>(heroloc, PlayerSelection)));
    m_hero = dynamic_cast<Hero*>(m_movingObjects[m_movingObjects.size()-1].get());
    if(!m_boardFont.loadFromFile("Pixel Emulator.otf"))
            std::cout << "Cant open Font file";



}
//====================================================
void Board::draw(sf::RenderWindow& window)const
{   
    float tx = (BOARDWIDTH/ float(m_width));
    float ty = (BOARDHEIGHT / float(m_height));
    sf::Vector2f size(tx, ty);

    for (auto& e : m_staticObjects)
        for (auto& d : e) {
            if(d)
            d->draw(window, size);
        }

    for (auto& movObj : m_movingObjects)
    {
        movObj->draw(window,size);
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

//    case HERO:
//        //m_movingObjects.push_back(std::move(std::make_unique<Hero>(location, PlayerSelection)));
//       m_hero = Hero(location, PlayerSelection);
//
//        break;
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

//==========================================

int Board::checkCollisions(float deltaTime)
{

    for(auto & mov:m_movingObjects)
        handleCollisions(*mov);

    return true;

}
//==================================================

bool Board::isObjectIsFalling(float deltaTime,MovingObjects& movingobject )
{

    float index = cellhight / 2;
    int i;
        for (i = 0;index < movingobject.getSprite().getPosition().y; ++i) {
            index += cellhight;
        }


        sf::Sprite checkdown = movingobject.getSprite();
        checkdown.move(0, 300 * deltaTime);

        for (int j = i; j < m_staticObjects.size(); ++j)
        {
            for (auto &d : m_staticObjects[j])
            {
                if (d) {
                    if(Coin *coinptr = dynamic_cast<Coin *>(d.get()))
                            continue;

                    if(Rope *Rhope = dynamic_cast<Rope *>(d.get()))
                        if(movingobject.getSprite().getPosition().y-d->getSprite().getPosition().y < 15)
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

        movingobject.move(0, 300 * deltaTime);
        movingobject.setIsfalling(true);



//
    return true;
}
//==================================================
void Board::printGameStatus(sf::RenderWindow & window, int levelnum)
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

    m_lifeText.setOutlineColor(sf::Color::White);
    m_scoreText.setPosition(50,BOARDHEIGHT);
    m_levelText.setPosition(m_scoreText.getPosition().x+m_scoreText.getGlobalBounds().width +50,BOARDHEIGHT);
    m_lifeText.setPosition(m_levelText.getPosition().x+m_levelText.getGlobalBounds().width+50,BOARDHEIGHT);


    window.draw(m_lifeText);
    window.draw(m_scoreText);
    window.draw(m_levelText);


}
//==================================================

void Board::initGamestatusbar()
{

    m_scoreText.setFont(m_boardFont);
    m_levelText.setFont(m_boardFont);
    m_lifeText.setFont(m_boardFont);

    m_lifeText.setCharacterSize(60);
    m_scoreText.setCharacterSize(60);
    m_levelText.setCharacterSize(60);


}
//==================================================

void Board::fallingGift(float deltaTime)
{
    sf::Vector2f boardsize((float)m_height, (float)m_width);
    srand((unsigned int)time(NULL));
    int i = (std::rand() % (m_width/2));
    int j = (std::rand() % (m_height/2));
    sf::Vector2f location;

    for ( i; i < m_staticObjects.size(); ++i)
    {
        for ( j; j < m_staticObjects[i].size(); ++j)
        {
            if (NULL == m_staticObjects[i][j])
            {
                if (NULL != m_staticObjects[i+1][j])
                    {
                    location.y = ((cellwidth / 2) + (cellwidth * i));
                    location.x = ((cellhight / 2) + (cellhight * j));




                    srand((unsigned int)time(NULL));
                    int ChoosEnemy = std::rand() % 2;


                    switch (ChoosEnemy)
                    {
                    case 0:
                        m_staticObjects[i][j] = std::move(std::make_unique <PresentAddingLife>(location, boardsize));
                        break;
                    case 1:
                        m_staticObjects[i][j] = std::move(std::make_unique <PresentAddingScore>(location, boardsize));
                        break;
                    case 3:
                        m_staticObjects[i][j] = std::move(std::make_unique <PresentAddingEnemy>(location, boardsize));
                        break;
                    }

                    return;
                }
            }
        }
    }
}
//==================================================
bool Board::handleCollisions(GameObj &obj)
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
    return false;
}
//==================================================
