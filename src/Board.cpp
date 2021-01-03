
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
    float tx = (1600 / float(m_width) / 2);
    float ty = (899 / float(m_height) / 2);

    location.x = 115 + tx;
    location.y = 30 + ty;
    float x_location = location.x;
    // take char with the file and put vector
    for (int i = 0; i < m_width; ++i)
    {

        for (int j = 0; j < m_height; ++j)
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

void Board::draw(sf::RenderWindow& window)const
{   
    float tx = (1600 / float(m_width));
    float ty = (899 / float(m_height));
    sf::Vector2f size(tx, ty);
    
    for (auto& e : m_staticObjects)
        e->draw(window,size);
    
    for (auto& e : m_enemys)
        e->draw(window, size);

    m_hero.draw(window, size);
}   
    
    

void Board::createObject( Picture & pic,char input, const sf::Vector2f & location, int PlayerSelection)
{

    
    switch (input)
    {
       
    case ENEMY:
        m_enemys.push_back(std::move(std::make_unique<Enemy>(pic, location, PlayerSelection)));
        break;

    case HERO:
       m_hero = Hero(pic, location, PlayerSelection);

        break;

    case FLOOR:
       
       m_staticObjects.push_back(std::move(std::make_unique<Floor>(pic, location)));


        break;

    case ROPE:
        m_staticObjects.push_back(std::move(std::make_unique<Rope>(pic, location)));
        break;

    case GUN:


        break;

    case LADDER:
        m_staticObjects.push_back(std::move(std::make_unique<Ladder>(pic, location)));
        break;

    }

}

void Board::moveCharacters(float deltaTime)
{
    m_hero.UpdateLocation(deltaTime);

    for (auto& staticObjects : m_staticObjects)
    {
        if (staticObjects->collisonWith(m_hero))
        {
            std::cout << "liron\n";
            break;
        }
    }
    


    for (auto& e : m_enemys)
        e->UpdateLocation(deltaTime);

   
}

  




//========================================