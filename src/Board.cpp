#include "Board.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include "SingletonPicture.h"
#include "Floor.h"
#include "Ladder.h"
#include "Rope.h"
#include <iostream>
#include "Coin.h"
#include "Sound.h"
#include <string>
#include "RandomEnemy.h"
#include "SmartEnemy.h"
#include "HorizontalEnemy.h"
//===============constructor ==============

Board::Board(std::ifstream& file , int PlayerSelection)
{

    sf::Vector2f location;
    char input;
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
    // take char with the file and put vector
    for (int i = 0; i < m_height; ++i)
    {
         //   m_staticObjects[i];
        for (int j = 0; j < m_width; ++j)
        {
               input = file.get();
               if(input == ' ')
                   m_staticObjects[i].push_back(nullptr);
               else
                   createObject(input, location, PlayerSelection, i);

                   location.x += (2 * tx);
        }
            file.get();
            location.x = x_location;
            location.y += (2 * ty);

    }


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
    for (auto& e : m_enemys)
        e->draw(window, size);

    m_hero.draw(window, size);
}

//====================================================
void Board::createObject(char input, const sf::Vector2f & location,int PlayerSelection, int i)
{
    sf::Vector2f boardsize((float)m_height, (float)m_width);
    
    switch (input)
    {
       
    case ENEMY:
        createEnemysVector(location, PlayerSelection);
        //m_enemys.push_back(std::move(std::make_unique<Enemy>(location, PlayerSelection)));
        break;

    case HERO:
       m_hero = Hero(location, PlayerSelection);

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


    }

}
void Board::createEnemysVector(const sf::Vector2f& location, int PlayerSelection)
{

    srand((unsigned int)time(NULL));
    int ChoosEnemy = std::rand() % 2;
    

    switch (ChoosEnemy)
    {
    case LEFT:
        m_enemys.push_back(std::move(std::make_unique<RandomEnemy>(location, PlayerSelection)));
        break;
    case RIGHT:
        m_enemys.push_back(std::move(std::make_unique<HorizontalEnemy>(location, PlayerSelection)));
        break;
    case UP:
        m_enemys.push_back(std::move(std::make_unique<SmartEnemy>(location, PlayerSelection)));
        break;
    }


}
//============================================
void Board::moveCharacters(float deltaTime)
{       
    if(!m_hero.getIsfalling()) {
        m_hero.setLastPosition(m_hero.GetPosition());
        m_hero.UpdateLocation(deltaTime);
    }
    for (auto& e : m_enemys)
    {
        if (!e->getIsfalling()) {
            e->setLastPosition(e->GetPosition());
            e->UpdateLocation(deltaTime);
        } 
    }
        

}

//==========================================

int Board::checkCollisions(float deltaTime)
{

    bool ok =false;
    for (auto& staticObjects : m_staticObjects)
        for (auto& staticObjectsi : staticObjects)
    {
        if(staticObjectsi)
        if (staticObjectsi->collisonWith(m_hero))
        {
           ok = true;
            staticObjectsi->handleColision(m_hero);
        }
    }
    if(!ok)
    {
    m_hero.setIsDownAvail(true);
    m_hero.setIsUpAvail(false);

    }



    
    for (auto& enemyobj : m_enemys)
    {
        bool okenemy = false;
        for (auto& staticObjects : m_staticObjects)
            for (auto& staticObjectsi : staticObjects)
            {
                if (staticObjectsi)
                    if (staticObjectsi->collisonWith(*enemyobj))
                    {
                        ok = true;
                        staticObjectsi->handleColision(*enemyobj);
                    }
            }

        if (!okenemy)
        {
            enemyobj->setIsDownAvail(true);
            enemyobj->setIsUpAvail(false);

        }
    }
    return true;
}
//==================================================

bool Board::isObjectIsfalling(float deltaTime) {

        float index =cellhight/2;
        int i;
        for (i = 0; index < m_hero.getSprite().getPosition().y; ++i)
        {
            index+=cellhight;
        }

        sf::Sprite checkdown = m_hero.getSprite();
        checkdown.move(0,300*deltaTime);

        for (int j = i; j < m_staticObjects.size(); ++j) {
            for(auto &d : m_staticObjects[j])
        {
            if(d)
            {
                if(Coin* coinptr = dynamic_cast<Coin*>(d.get()))
                    continue;

                if(!d->getIsOff())
                if(checkdown.getGlobalBounds().intersects(d->getSprite().getGlobalBounds()))
            {
                m_hero.setIsfalling(false);
                return false;
            }
        }
        }
    }

    m_hero.move(0,300*deltaTime);
    m_hero.setIsfalling(true);
    return true;


    for (auto& enemyobj : m_enemys)
    {
        index = cellhight / 2;
        
        for (i = 0; index < enemyobj->getSprite().getPosition().y; ++i)
        {
            index += cellhight;
        }

        sf::Sprite checkdown = enemyobj->getSprite();
        checkdown.move(0, 300 * deltaTime);

        for (int j = i; j < m_staticObjects.size(); ++j) {
            for (auto& d : m_staticObjects[j])
            {
                if (d)
                {
                    if (Coin* coinptr = dynamic_cast<Coin*>(d.get()))
                        continue;

                    if (!d->getIsOff())
                        if (checkdown.getGlobalBounds().intersects(d->getSprite().getGlobalBounds()))
                        {
                            enemyobj->setIsfalling(false);
                            return false;
                        }
                }
            }
        }

        enemyobj->move(0, 300 * deltaTime);
        enemyobj->setIsfalling(true);
       // return true;

    }

}
//==================================================
void Board::printGameStatus(sf::RenderWindow & window, int levelnum) {


    initGamestatusbar();


    m_scoreText.setString("Score:"+std::to_string(m_hero.getScore()));
    m_levelText.setString("Level:00" + std::to_string(levelnum));
    m_lifeText.setString("Life:00"+std::to_string(m_hero.getLife()));

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

void Board::fallingGift(float)
{
    //m_staticObjects
    for (auto& e : m_staticObjects)
    {
        for (auto& d : e)
        {
            if (NULL == d)
            {
                std::cout << m_staticObjects[1][1];

            }
        }
    }
}
//==================================================
