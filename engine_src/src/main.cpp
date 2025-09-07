#include <SFML/Graphics.hpp>
#include <eng/engine.hpp>

eng::window_t eng::window;

float eng::delta_time;
float eng::time;

int main() {
	sf::Event event;
	sf::Clock clock;
	while (eng::window.isOpen()) {
                while (eng::window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				eng::window.close();	
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        eng::window.close();	
                }

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4)) {
			eng::window.toggle_fullscreen();	
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
                        eng::window.screenshot();	
                }

                eng::delta_time = clock.restart().asSeconds();
                eng::time += 0.05;

		eng::window.render();

		eng::loop();
        }

	eng::start();
}
