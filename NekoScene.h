#ifndef NEKOSCENE_H
#define NEKOSCENE_H
#include <stdio.h>
#include <string>


namespace NekoEngine {
	class NekoScene {
	public:
		NekoScene(int, int, std::string);
		~NekoScene();
		int getVerticalRes();
		int getHorizontalRes();
		void cleanup();
		std::string getWindowTitle();
		virtual void update();
		virtual void onQuit() {};
	protected:
		int vertical_res;
		int horizontal_res;
		std::string window_title;
	};
}



#endif