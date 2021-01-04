#include <SFML/Audio.hpp>

class Sound 
{

public:

private:
	sf::SoundBuffer m_jerry;
	sf::Sound m_jerrySound;

	sf::SoundBuffer m_rick;
	sf::Sound m_rickSound;

	sf::SoundBuffer m_startGame;
	sf::Sound m_startGameSound;

	sf::SoundBuffer m_gameOver ;
	sf::Sound m_gameOverSound;

	sf::SoundBuffer m_dead;
	sf::Sound m_deadSound;

	sf::SoundBuffer m_levelUp;
	sf::Sound m_levelUpSound;

};
