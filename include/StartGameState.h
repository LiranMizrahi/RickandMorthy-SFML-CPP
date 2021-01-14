
#include "State.h"

class StartGameState:State {

    StartGameState(const sf::Texture &unnamed,
                   const sf::SoundBuffer &unnamed1);
    void openstate(sf::RenderWindow &m_window, bool isplayerwin)override;



};


