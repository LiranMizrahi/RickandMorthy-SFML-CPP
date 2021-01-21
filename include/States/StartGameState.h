
#include "State.h"

class StartGameState:State {

public:
    StartGameState();
    //===================public function=================
    void openstate(sf::RenderWindow &m_window, bool isplayerwin)override;
};


