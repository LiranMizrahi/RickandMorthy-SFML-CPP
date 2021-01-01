 #pragma once
        
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObj.h"
#include "Picture.h"
#include "Menu.h"
#include "Board.h"
#include "fstream"
#include "Menu.h"
					
										
class Controller {
					
				
					
public:			
	Controller();
	void run();

				
private:	

	//private members
	Board m_board;
	Picture m_pictures;
	Menu m_menu;

	sf::RenderWindow m_window;
	sf::Sprite board;	
	sf::Clock clock;
	std::ifstream m_boardfile;

	int m_level;

	//private function
	std::ifstream openlevelfile(int);		
};				