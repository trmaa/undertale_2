#ifndef ENG_WINDOW_HPP
#define ENG_WINDOW_HPP

#include <SFML/Graphics.hpp>

namespace eng {
	class window_t: public sf::RenderWindow {
	private:
		sf::Font m_font;
		sf::Text m_fps_text;

		sf::RenderTexture m_buffer;
		sf::Sprite m_render_image;

	private:
                void m_render_buffer();
	public:
		void toggle_fullscreen();
		void screenshot();
		void render();

        public:
		window_t();
	};
}

#endif
