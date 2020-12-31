#include "Controller.h"
#include <string>
#include <iostream>
Controller::Controller(): m_window(sf::VideoMode(1800, 1080), "RICK RUNNER")
{	
	int m_level = 1;
	board.setTexture(*m_pictures.GetBoardTexture());
	board.setPosition(120.f, 120.f);
	m_boardfile = openlevelfile(1);
    m_board = Board(m_boardfile, m_pictures);
	
}

void Controller::run()
{
	while (m_window.isOpen())
	{
		m_board.draw(m_window);
		m_window.draw(board);
		m_window.clear();
		m_window.draw(board);
		m_window.display();
	}

}




std::ifstream Controller::openlevelfile(int level)
{
	std::string filename = "level";
		filename += std::to_string(level);
		std::ifstream file;
		file.open(filename);
		if(file.bad())
			std::cout << "Error while open level file";
		return file;
}

