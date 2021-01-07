#include "Controller.h"
#include <string>
#include <iostream>


Controller::Controller(): m_window(sf::VideoMode(1600, 1080), "RICK RUNNER")
{	
	int m_level = 1;
	board.setTexture(*m_pictures.getBoardTexture());
	board.setPosition(0,0);
	m_boardfile = openlevelfile(m_level);
    m_board = Board(m_boardfile, m_pictures, m_menu.StartGame(m_window, m_pictures,m_sound));
	m_sound.playStartGameSound();
	
}
//=============================================================

void Controller::run()
{

	while (m_window.isOpen())
	{
        float deltaTime = clock.restart().asSeconds();
		m_window.clear();
		m_window.draw(board);
		m_board.draw(m_window);
		m_window.display();
		

		
		sf::Event event;
		while(m_window.pollEvent(event))
			if (sf::Keyboard::isKeyPressed(sf:: Keyboard::Escape)|| event.type == sf::Event::Closed)
			{
				m_window.close();
				break;
			}

			m_board.moveCharacters(deltaTime);
            m_board.checkCollisions(deltaTime);


		
	}
}

//=============================================================

std::ifstream Controller::openlevelfile(int level)
{
	std::string filename = "level";
		filename += std::to_string(level);
		filename += ".txt";
		std::ifstream file;
		file.open(filename);
		if(!file.is_open())
			std::cout << "Error while open level file";
		return file;
}
//=============================================================
