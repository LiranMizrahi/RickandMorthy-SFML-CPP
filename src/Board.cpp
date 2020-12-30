
#include "Board.h"
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include "Picture.h"
//===============constructors ==============
Board::Board():m_height(0),m_width(0)
{
    m_hero = Hero();
}

Board::Board(std::fstream file , Picture * pic )
{
    sf::Vector2f location;


    //calculate the size of the middle of singal cell 
    // sub the size of the image frame
    float tx = (1180 / float(m_width) / 2);
    float ty = (880 / float(m_height) / 2);

    location.x = 230 - tx;
    location.y = 35 + ty;

    float x_location = location.x;

    
    char input;
	file >> m_width >> m_height; // take size map
	file.get();
   
    // take char with the file and put vector
    for (int i = 0; i < m_width; ++i)
    {

        for (int j = 0; j < m_height; ++j)
        {
           
            input = file.get();
         

                switch (input)
                {

                case ENEMY:
               
                    break;

                case HERO:
                    m_hero = Hero();

                    break;

                case FLOOR:
                    

                    break;

                case ROPE:
                    
                    break;

                case GUN:
                   

                    break;

                case LADDER:
                    
                    break;

                }
                location.x += (2 * tx);
            }
            file.get();
            location.x = x_location;
            location.y += (2 * ty);

        }
    }


  




//================ ========================