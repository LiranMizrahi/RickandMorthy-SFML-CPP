
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class State {
public:

    State(const sf::Texture& ,const sf::SoundBuffer&);
    virtual void openstate(sf::RenderWindow &m_window, bool isplayerwin) = 0;



protected:
    sf::Sprite m_stateBackround;
    sf::Sound m_stateSound;

};

