
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
#include "RandomEnemy.h"
//===============constructors ==============
Board::Board():m_height(0),m_width(0)
{

}

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
        m_enemys.push_back(std::move(std::make_unique<Enemy>(location, PlayerSelection)));
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
//============================================
void Board::moveCharacters(float deltaTime)
{       

    m_hero.setLastPosition(m_hero.GetPosition());
    m_hero.UpdateLocation(deltaTime);

    for (auto& e : m_enemys)
        e->UpdateLocation(deltaTime);

}

//========================================

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
        m_hero.is_upok =false;
      //  m_hero.move(0,100*deltaTime);

    }

    return true;
}

bool Board::isObjectIsfalling() {

    float index =0;
    int i;
    for (i = 0; index < m_hero.getSprite().getPosition().y; ++i) {
        index+=cellhight;
    }
    auto rec = sf::RectangleShape(sf::Vector2f(m_hero.getSprite().getTexture()->getSize().x,100));
    rec.setOrigin(m_hero.getSprite().getTexture()->getSize().x/2u,0.5);
    rec.setPosition(m_hero.getSprite().getPosition().x,index);
    //std::cout << i <<std::endl;

    for( auto & e : m_staticObjects[i+1])

        if(e)
        if (rec.getGlobalBounds().intersects(e->getSprite().getGlobalBounds()))

              return true;
        m_hero.move(0,0.02);
    return false;
}
