#include <SFML/Graphics.hpp>

class GameStatusBar {


public:
    GameStatusBar();
    void printGameStatus(sf::RenderWindow &, int level, const sf::Time&,const sf::Clock& , bool,
                    int score, int life);

private:
    sf::Text m_scoreText;
    sf::Text m_levelText;
    sf::Text m_lifeText;
    sf::Text m_timeTheLevel;
    int m_level,m_life;
    sf::Time m_time ,m_lifechange, m_levelchange , m_timechange;


    void printboard(sf::RenderWindow &window);

    void
    printChangeColor(int life, const sf::Clock &clock, const sf::Time &time);
};

