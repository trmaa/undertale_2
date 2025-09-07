#include <eng/drawable.hpp>
#include <string>

const sf::Sprite& eng::drawable_entity_t::get_sprite() {
	this->m_render_texture.clear(sf::Color::Transparent);	

	this->m_shader.setUniform("sprite", this->m_sprite);
	this->m_shader.setUniform("normal_map", this->m_normal_map);
	this->m_shader.setUniform(
			"resolution", 
			(sf::Vector2f)this->m_sprite.getSize());
	this->m_shader.setUniform("time", (float)eng::time);
	this->m_render_texture.draw(this->m_buffer, &this->m_shader);	

	this->m_render_texture.display();

	this->setPosition(this->m_position);
	return *this;
}

eng::drawable_entity_t::drawable_entity_t(sf::Vector2f& pos):
        m_position(pos) {
	this->m_sprite.loadFromFile("./bin/rooms/player/sprite.png");
	this->m_normal_map.loadFromFile("./bin/rooms/player/normal_map.png");

	this->m_buffer.setSize(
			sf::Vector2f(
				this->m_sprite.getSize().x, 
				this->m_sprite.getSize().y));
	this->m_render_texture.create(
			this->m_sprite.getSize().x,
			this->m_sprite.getSize().y);

	this->setTexture(this->m_render_texture.getTexture());

	this->m_shader.loadFromFile(
			"./shaders/lighting/main.glsl", 
			sf::Shader::Fragment);
}

sf::Text eng::drawable_text(std::string text) {
	sf::Text out;
	sf::Font font;
	font.loadFromFile("./bin/fonts/BigBlue.ttf");
        out.setFont(font);
        out.setCharacterSize(16);
	out.setFillColor(sf::Color::White);
	out.setPosition(0, 0);
        out.setString(text);
        return out;
}
