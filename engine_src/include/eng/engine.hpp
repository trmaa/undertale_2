#ifndef ENG_ENGINE_HPP
#define ENG_ENGINE_HPP

#include <eng/window.hpp>

namespace eng {
	extern window_t window;

	extern float delta_time;
	extern float time;

	void loop();
	void start();
}

#endif
