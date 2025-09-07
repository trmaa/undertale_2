#ifndef ENG_DRAWABLE_HPP
#define ENG_DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <eng/engine.hpp>
#include <string>

namespace eng {
	class drawable_entity_t: public sf::Sprite {
	private:
		sf::Vector2f& m_position;

		sf::RectangleShape m_buffer;

		sf::Texture m_sprite;
		sf::Texture m_normal_map;
		sf::Shader m_shader;

		sf::RenderTexture m_render_texture;
	public:
		const sf::Sprite& get_sprite();

	public:
		drawable_entity_t(sf::Vector2f& pos);
	};

	sf::Text drawable_text(std::string text);
}

#endif
