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

				
private:	

	//private members
	//Board m_board;
	sf::RenderWindow m_window;
	Picture m_pictures;
	sf::Sprite board;	
	//Menu m_menu;
	std::fstream level;

	//private function

	std::fstream openlevelfile(int);

				
				
};				