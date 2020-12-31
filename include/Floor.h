#pragma once


class Floor : public StaticObjects {

public:
	Floor() {};
	Floor(const sf::Texture* tex, const sf::Vector2f& loc) {
		m_sprite.setTexture(*tex);
		m_sprite.setPosition(loc);
	};


};