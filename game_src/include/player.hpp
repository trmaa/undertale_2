#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <eng/engine.hpp>

class player_t {
public:
	glm::vec2 position;

	sf::RectangleShape buffer;

	sf::Texture sprite;
	sf::Texture normal_map;
	sf::Shader shader;

        sf::RenderTexture render_texture;
	sf::Sprite render_image;

	const sf::Sprite& get_sprite() {
		this->render_texture.clear(sf::Color::Transparent);	
		
		this->shader.setUniform("sprite", this->sprite);
		this->shader.setUniform("normal_map", this->normal_map);
		this->shader.setUniform("resolution", (sf::Vector2f)this->sprite.getSize());

		this->shader.setUniform("time", (float)eng::time);

		this->render_texture.draw(this->buffer, &this->shader);	

		this->render_texture.display();
		
		return this->render_image;
	}

	void setup_render_image() {
		this->sprite.loadFromFile("./bin/rooms/player/sprite.png");
		this->normal_map.loadFromFile("./bin/rooms/player/normal_map.png");

		this->buffer.setSize(sf::Vector2f(sprite.getSize().x, sprite.getSize().y));
                this->render_texture.create(sprite.getSize().x, sprite.getSize().y);

		this->render_image.setTexture(this->render_texture.getTexture());

		this->shader.loadFromFile("./shaders/lighting/main.glsl", sf::Shader::Fragment);
	}

	player_t() {
		setup_render_image();	
	}
};

#endif
