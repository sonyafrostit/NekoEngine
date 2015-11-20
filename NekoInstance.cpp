#include "NekoException.h"
#include "NekoInstance.h"
#include <iostream>

int screen_width = 0;
int screen_height = 0;



namespace NekoEngine {
	NekoInstance::NekoInstance() {
			if (SDL_Init(SDL_INIT_VIDEO) != 0){
				throw NekoInitFailException();
			}
			current_scene = NULL;
	}
	NekoInstance::~NekoInstance() {
		
		SDL_Quit();

	}
	void NekoInstance::start() {
		if (current_scene == NULL) {
			throw NekoNoSceneException();
		}
		running = true;
		while (running) {
			update();
			render();
		}
	}
	void NekoInstance::update() {
		current_scene->update();
	}
	void NekoInstance::render() {
	}
	void NekoInstance::stop() {
	}
	void NekoInstance::loadScene(NekoScene next_scene) {
		if (current_scene != NULL) {
			if (next_scene.getHorizontalRes() != current_scene->getHorizontalRes() ||
				next_scene.getVerticalRes() != current_scene->getVerticalRes()) {
				mainWindow = SDL_CreateWindow(next_scene.getWindowTitle().c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, next_scene.getHorizontalRes(), next_scene.getVerticalRes(), SDL_WINDOW_SHOWN);
			}
			current_scene->cleanup();
		}
		else {
			mainWindow = SDL_CreateWindow(next_scene.getWindowTitle().c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, next_scene.getHorizontalRes(), next_scene.getVerticalRes(), SDL_WINDOW_SHOWN);
		}
		current_scene = &next_scene;
		std::cout << current_scene->getHorizontalRes();
	}


}

