
#include "Board.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include "Picture.h"
#include "Floor.h"
#include "Ladder.h"
#include "Rope.h"
#include <iostream>

//===============constructors ==============
Board::Board():m_height(0),m_width(0)
{
   
}

Board::Board(std::ifstream& file ,  Picture& pic , int PlayerSelection)
{
   
    sf::Vector2f location;

    char input;
	file >> m_width >> m_height; // take size map
	file.get();
   

    //calculate the size of the middle of singal cell 
    // sub the size of the image frame
    float tx = (BOARDWIDTH / float(m_width) / 2);
    float ty = (BOARDHEIGHT / float(m_height) / 2);

    location.x = 130 + tx;
    location.y = 30 + ty;
    float x_location = location.x;
    // take char with the file and put vector
    for (int i = 0; i < m_height; ++i)
    {

        for (int j = 0; j < m_width; ++j)
        {
               input = file.get();
               createObject(pic,input,location , PlayerSelection);
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
        e->draw(window,size);
    
    for (auto& e : m_enemys)
        e->draw(window, size);

    m_hero.draw(window, size);
}   
    
    

void Board::createObject( Picture & pic,char input, const sf::Vector2f & location, int PlayerSelection)
{
    sf::Vector2f boardsize((float)m_height, (float)m_width);
    
    switch (input)
    {
       
    case ENEMY:
        m_enemys.push_back(std::move(std::make_unique<Enemy>(pic, location, PlayerSelection)));
        break;

    case HERO:
       m_hero = Hero(pic, location, PlayerSelection);


        break;

    case FLOOR:
       
       m_staticObjects.push_back(std::move(std::make_unique<Floor>(pic, location, boardsize)));
        
       break;

    case ROPE:
        m_staticObjects.push_back(std::move(std::make_unique<Rope>(pic, location, boardsize)));
        break;

    case GUN:

        break;

    case LADDER:
        m_staticObjects.push_back(std::move(std::make_unique<Ladder>(pic, location, boardsize)));
        break;

    }

}
//============================================
void Board::moveCharacters(float deltaTime)
{       
    sf::Vector2f oldlocation = m_hero.GetPosition();
    m_hero.UpdateLocation(deltaTime);
        
    for (auto& staticObjects : m_staticObjects)
    {
        if (staticObjects->collisonWith(m_hero))
        {
           
            m_hero.SetPosition(oldlocation);
            break;
        }
    }
    


    for (auto& e : m_enemys)
        e->UpdateLocation(deltaTime);

   
}

//========================================