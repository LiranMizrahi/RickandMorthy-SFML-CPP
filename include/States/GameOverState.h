#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "States/State.h"
const bool EXIT = true;
const bool NEWGAME = false;


class GameOverState: public State {
public:
    GameOverState();
    virtual ~GameOverState() = default;
    //===================public function=================
    void openstate(sf::RenderWindow &m_window, bool isplayerwin)override;


private:
    //=========private members ======================
    sf::Text gameexitstatus;
    sf::Text exitgame;
    sf::Text newgame;
    bool choose = EXIT;
};

