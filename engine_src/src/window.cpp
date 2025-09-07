#include <SFML/Graphics.hpp>
#include <eng/engine.hpp>
#include <eng/window.hpp>
#include <eng/colors.hpp>
#include <cstdio>
#include <filesystem>

eng::window_t::window_t() {
	sf::VideoMode video_mode = sf::VideoMode(800, 600);
	this->create(video_mode, "Undertale 2", sf::Style::Fullscreen);
	this->setFramerateLimit(60);

	this->m_buffer.create(250, 250*3/4);
        this->m_buffer.setSmooth(false);

	this->m_font.loadFromFile("bin/fonts/BigBlue.ttf");
        this->m_fps_text.setFont(m_font);
	this->m_fps_text.setCharacterSize(32);
        this->m_fps_text.setFillColor(sf::Color(255,0,255));
        this->m_fps_text.setPosition(0,0);
}

void eng::window_t::toggle_fullscreen() {
	std::printf("%sWorking on it: toggle fullscreen%s\n", eng::red, eng::reset);
}

void eng::window_t::screenshot() {
	namespace fs = std::filesystem;

	unsigned int screenshot_id = 0; 
	for (auto file: fs::directory_iterator("./bin/screenshots/")) {
		screenshot_id++;
	}

	std::printf("Screenshot taken at %i\n", screenshot_id);

	sf::Image image = this->m_render_image.getTexture()->copyToImage();
	image.saveToFile("./bin/screenshots/" + std::to_string(screenshot_id) + ".png");
}


void eng::window_t::render() {	
	this->clear(sf::Color(100,120,150));

	this->m_buffer.clear(sf::Color::Transparent);

	this->m_render_buffer();

	this->m_buffer.display();

        this->m_render_image.setTexture(this->m_buffer.getTexture());

	this->m_render_image.setPosition(0,0);
	this->m_render_image.setScale(
		this->getSize().x / (float)this->m_buffer.getSize().x,
		this->getSize().y / (float)this->m_buffer.getSize().y);

        this->draw(this->m_render_image);

	if (eng::DEBUG) {
		this->m_fps_text.setString(
			"FPS: " + std::to_string(int(1/eng::delta_time))
		);
		this->draw(m_fps_text);	
	}

        this->display();
}
