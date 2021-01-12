#include "Controller.h"
#include <string>
#include <iostream>

 int Controller::m_level = 1;

Controller::Controller(): m_window(sf::VideoMode(1600, 1080), "RICK RUNNER")
{

    m_window.setFramerateLimit(60);
	board.setTexture(*SingletonPicture::instance().getBoardTexture());
	board.setPosition(0,0);
	m_boardfile = openlevelfile(m_level);
	m_choes = m_menu.StartGame(m_window);
    m_board = Board(m_boardfile, m_choes);
	m_gameOverSound.setBuffer(Sound::instance().getMGameOver());
	m_levelUpSoundl.setBuffer(Sound::instance().getMLevelUp());
	m_startGameSound.setBuffer(Sound::instance().getMStartGame());

}
//=============================================================

void Controller::run()
{
    m_startGameSound.play();
	while (m_window.isOpen())
	{
        float deltaTime = clock.restart().asSeconds();
		m_window.clear();
		m_window.draw(board);
		m_board.draw(m_window);
        m_board.printGameStatus(m_window,m_level);
        m_window.display();

		sf::Event event;
		while(m_window.pollEvent(event))
			if (sf::Keyboard::isKeyPressed(sf:: Keyboard::Escape)|| event.type == sf::Event::Closed)
			{
				m_window.close();
				break;
			}

      //  m_board.checkIfObjectFalling(deltaTime);
        m_board.checkCollisions(deltaTime);
        m_board.moveCharacters(deltaTime);


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

unsigned int Controller::getLevel() {
    return m_level;
}


//=============================================================
