#ifndef NEKOSCENE_H
#define NEKOSCENE_H
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <vector>
#include "NekoEntity.h"

namespace NekoEngine {
	class NekoScene {
	public:
		NekoScene(int, int, std::string);
		int getVerticalRes();
		int getHorizontalRes();
		void cleanup();
		std::string getWindowTitle();
		void update();
		void render(SDL_Surface* target) {};
		virtual void onQuit() {};
		bool isRunning() { return running; };
	protected:
		int vertical_res;
		int horizontal_res;
		std::string window_title;
		bool running;
		std::vector<NekoEntity> entities;
	};
}



#endif