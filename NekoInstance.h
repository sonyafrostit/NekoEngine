#ifndef NekoInstance_H
#define NekoInstance_H

#include <SDL.h>
#include "NekoScene.h"
#include <string>

namespace NekoEngine {

	class NekoInstance {
	public:
		NekoInstance();
		~NekoInstance();
		void loadScene(NekoScene*);
		void start();
		void update();
		void render();
		void stop();
	private:
		SDL_Window* mainWindow;
		NekoScene* current_scene;
		bool running;
	};

}
#endif