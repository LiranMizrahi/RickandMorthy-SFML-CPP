#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.h"
const bool EXIT = true;
const bool NEWGAME = false;


class GameOverState: public State {
public:
    GameOverState();
    virtual ~GameOverState() = default;
    void openstate(sf::RenderWindow &m_window, bool isplayerwin)override;


private:

    sf::Text gameexitstatus;
    sf::Text exitgame;
    sf::Text newgame;
    bool choose = EXIT;
};

