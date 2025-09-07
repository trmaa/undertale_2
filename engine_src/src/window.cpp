#include <SFML/Graphics.hpp>
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

	sf::Image image = this->m_buffer.getTexture().copyToImage();
	image.saveToFile("./bin/screenshots/" + std::to_string(screenshot_id) + ".png");
}
