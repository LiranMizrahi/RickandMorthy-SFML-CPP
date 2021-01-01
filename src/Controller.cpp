#include "Controller.h"
#include <string>
#include <iostream>
Controller::Controller(): m_window(sf::VideoMode(1800, 1080), "RICK RUNNER")
{	
	int m_level = 1;
	board.setTexture(*m_pictures.GetBoardTexture());
	board.setPosition(130.f,30.f);
	m_boardfile = openlevelfile(1);
	

    m_board = Board(m_boardfile, m_pictures, m_menu.StartGame(m_window));
	
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_window.draw(board);
		m_board.draw(m_window);
		m_window.display();
		sf::Event event;
		while (m_window.pollEvent(event))
			
		{
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				m_window.close();
				break;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			{
				m_menu.StartGame(m_window);
			}

		}
	}
}




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

