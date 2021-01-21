
#include "States/State.h"
class LevelUpState:  State {
public:
    LevelUpState();
    //===================public function=================
    void openstate(sf::RenderWindow &m_window, bool isplayerwin)override;


};

