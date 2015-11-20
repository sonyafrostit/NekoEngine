#include "NekoScene.h"
#include "SDL.h"

namespace NekoEngine {
	NekoScene::NekoScene(int x, int y, std::string title) {
		vertical_res = y;
		horizontal_res = x;
		window_title = title;
	}
	void NekoScene::cleanup() {
	}
	int NekoScene::getHorizontalRes() {
		return horizontal_res;
	}
	int NekoScene::getVerticalRes() {
		return vertical_res;
	}
	std::string NekoScene::getWindowTitle() {
		return window_title;
	}
	void NekoScene::update() {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				onQuit();
			}
		}
	}

}