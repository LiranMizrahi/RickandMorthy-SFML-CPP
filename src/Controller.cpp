#include "Controller.h"
#include <string>
#include <iostream>

#include "Coin.h"

 int Controller::m_level = 1;

Controller::Controller(): m_window(sf::VideoMode(1600, 1080), "RICK RUNNER")
{
    m_gameOverSound.setBuffer(SingletonSound::instance().getMGameOver());
    m_levelUpSoundl.setBuffer(SingletonSound::instance().getMLevelUp());
    m_startGameSound.setBuffer(SingletonSound::instance().getMStartGame());

    m_window.setFramerateLimit(60);
	board.setTexture(*SingletonPicture::instance().getBoardTexture());
	board.setPosition(0,0);
    printStartGameScreen();

    m_boardfile = openlevelfile(m_level);
    m_herroSelect = m_menu.StartGame(m_window);
    m_board = Board(m_boardfile, m_herroSelect);



    m_boardfile.close();
}
//=============================================================

void Controller::run()
{
<<<<<<< HEAD
	int gift = 0;
=======

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

        m_board.checkIfObjectFalling(deltaTime);
        m_board.checkCollisions(deltaTime);
        m_board.moveCharacters(deltaTime);
        //m_board check if hero alive
        //m_board check if hero got gift
        //m_board check if hero took coin


        //check if there is no move available coins to get
        if(checkIfLevelDone()) {

            //check if there is move level to upgrade
            if(m_level == NUMBEROFLEVELS)
                gameOverHandler(true);
            else {
                m_level++;
                //if there is no more coins move to the next level
                upgradeLevel();
            }
        }

        if(gift == 0)
        {
            ++gift;
            m_board.fallingGift(deltaTime);
        }

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

unsigned int Controller::getLevel() {
    return m_level;
}
//=============================================================

bool Controller::checkIfLevelDone() {
    return (Coin::getNowCoins() == 0);
}
//=============================================================

void Controller::upgradeLevel() {

    {
        sf::Sprite uplevel;
       uplevel.setTexture(*SingletonPicture::instance().getMLevelUp());
       uplevel.setPosition(0,0);
       m_window.clear();
       m_window.draw(uplevel);
       m_window.display();
       sf::sleep(sf::seconds(2));


     m_boardfile = openlevelfile(m_level);
     m_levelUpSoundl.play();
     m_board = Board(m_boardfile,m_herroSelect);

    }

}
//=============================================================

void Controller::printStartGameScreen() {

 auto soundmusic = sf::Sound(SingletonSound::instance().getOpenGame());
    soundmusic.play();
    sf::Sprite openpic(*SingletonPicture::instance().getMStartGame());

    while (m_window.isOpen())
    {
        if (auto event = sf::Event{}; m_window.waitEvent(event)) {}

            m_window.clear();
            m_window.draw(openpic);
            m_window.display();

            sf::sleep(sf::seconds(4));
            return;

    }
}
//=============================================================

void Controller::gameOverHandler(bool isplyerwin)
{

    auto gameoverpic = sf::Sprite();
    gameoverpic.setTexture(*SingletonPicture::instance().getMGameOver());
    auto soundmusic = sf::Sound(SingletonSound::instance().getMDead());
    auto fonti = sf::Font();
    auto gameexitstatus = sf::Text();
    auto exitgame = sf::Text();
    auto newgame = sf::Text();
    const bool EXIT = true;
    const bool NEWGAME = false;
    bool choose = EXIT;

    fonti.loadFromFile("Nosifer-Regular.ttf");

    gameexitstatus.setFont(fonti);
    exitgame.setFont(fonti);
    newgame.setFont(fonti);
    newgame.setCharacterSize(55);
    exitgame.setCharacterSize(55);
    exitgame.setStyle(exitgame.Underlined);

    gameexitstatus.setCharacterSize(80);

    if (isplyerwin)
        gameexitstatus.setString("YOU WON");
    else
        gameexitstatus.setString("YOU LOST");

    gameexitstatus.setPosition(580, 250);

    exitgame.setString("EXIT");
    newgame.setPosition(620, 600);

    exitgame.setPosition(730, 700);
    newgame.setString("NEW GAME");
    sf::sleep(sf::seconds(3));
    soundmusic.play();
    auto event = sf::Event();
    while (m_window.isOpen())
    {
        m_window.clear();
        m_window.draw(gameoverpic);
        m_window.draw(exitgame);
        m_window.draw(newgame);
        m_window.draw(gameexitstatus);
        m_window.display();
        if (m_window.waitEvent(event)) {

            if (event.type == sf::Event::KeyReleased)
            {
                if(event.key.code ==sf::Keyboard::Up)
                {
                choose = NEWGAME;
                newgame.setStyle(exitgame.Underlined);
                exitgame.setStyle(0);
                }

            else if (event.key.code ==sf::Keyboard::Down)
            {
                choose = EXIT;
                exitgame.setStyle(exitgame.Underlined);
                newgame.setStyle(0);

            }
            else if (event.key.code ==sf::Keyboard::Enter)
            {
                if (choose == EXIT)
                {
                    m_window.close();
                    exit(EXIT_SUCCESS);
                }

                if (choose == NEWGAME)
                {
                    m_level = 1;
                    upgradeLevel();
                    return;
                }

            }


          }

        }
    }

}



//=============================================================
