#include "NekoInstance.h"
#include "NekoException.h"
#undef main
namespace NekoEngine {
	class MyScene : public NekoScene {
	public:
		MyScene() : NekoScene(640, 480, "NekoEngine Demo") {
			
		}
		virtual void onQuit()  { running = false; }
	};
}
int main(int argc, char** argv){
	
		NekoEngine::NekoInstance main_window;
		NekoEngine::MyScene * my_scene = new NekoEngine::MyScene();
		main_window.loadScene(my_scene);
		main_window.start();
		delete my_scene;
	

}