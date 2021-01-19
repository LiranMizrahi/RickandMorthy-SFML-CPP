
#include "State.h"

class StartGameState:State {

public:
    StartGameState();
    void openstate(sf::RenderWindow &m_window, bool isplayerwin)override;



};


