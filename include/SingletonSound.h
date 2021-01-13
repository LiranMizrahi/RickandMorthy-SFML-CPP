#include <SFML/Audio.hpp>

class SingletonSound
{

public:

    ~SingletonSound() =default;
    static SingletonSound& instance();

    const sf::SoundBuffer &getMJerry() const;
    const sf::SoundBuffer &getMRick() const;
    const sf::SoundBuffer &getMStartGame() const;
    const sf::SoundBuffer &getMGameOver() const;
    const sf::SoundBuffer &getMDead() const;
    const sf::SoundBuffer &getMLevelUp() const;
    const sf::SoundBuffer &getMCollectGift() ;
    const sf::SoundBuffer &getMCollectCoin() const;
    const sf::SoundBuffer &getOpenGame() const;



private:
    SingletonSound();
	sf::SoundBuffer m_jerry;
	sf::SoundBuffer m_rick;
	sf::SoundBuffer m_startGame;
    sf::SoundBuffer m_gameOver ;
	sf::SoundBuffer m_dead;
	sf::SoundBuffer m_levelUp;
	sf::SoundBuffer m_collectGift;
	sf::SoundBuffer m_collectCoin;
    sf::SoundBuffer m_openGame;


};
