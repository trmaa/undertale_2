#include <SFML/Graphics.hpp>
#include <eng/engine.hpp>
#include <eng/drawable.hpp>
#include "gamestate.hpp"

void eng::window_t::m_render_buffer() {
	if (g_GAMESTATE == MENU) {
        	this->m_buffer.clear(sf::Color::Black);
		/*sf::Text title = eng::drawable_text("Undertale 2");
                title.setPosition(
			(float)this->m_buffer.getSize().x/2 - title.getGlobalBounds().width/2, 
			(float)this->m_buffer.getSize().y/4 - title.getGlobalBounds().height/2);
                this->m_buffer.draw(title);*/
        }
}
