#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObj.h"
#include "Picture.h"
#include "Menu.h"
#include "Board.h"
#include "fstream"


class Controller {
					
				
					
public:			
	Controller();
	void run();

				
private:	

	//private members
	Board m_board;
	sf::RenderWindow m_window;
	Picture m_pictures;
	sf::Sprite board;	
	//Menu m_menu;
	std::ifstream m_boardfile;
	int m_level;

	//private function

	std::ifstream openlevelfile(int);

				
				
};				