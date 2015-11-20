#include "NekoInstance.h"
#include "NekoException.h"
#include "NekoScript.h"
#undef main
int main(int argc, char** argv){
	try {
		NekoEngine::init_script_engine();
	} 
	catch (NekoEngine::NekoExitException) {
		return 0;
	}
	NekoEngine::cleanup_script_engine();
}