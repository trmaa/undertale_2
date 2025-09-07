#include <SFML/Graphics.hpp>
#include <eng/engine.hpp>
#include <player.hpp>

extern player_t player;

void eng::window_t::render() {	
	this->clear(sf::Color(100,120,150));

	this->m_buffer.clear(sf::Color::Transparent);

//pipeline
	sf::Sprite player_sprite = player.get_sprite();
        this->m_buffer.draw(player_sprite);
//pipeline end

	this->m_buffer.display();

        this->m_render_image.setTexture(this->m_buffer.getTexture());

	this->m_render_image.setPosition(0,0);
	this->m_render_image.setScale(
		this->getSize().x / (float)this->m_buffer.getSize().x,
		this->getSize().y / (float)this->m_buffer.getSize().y);

        this->draw(this->m_render_image);

        this->display();
}
