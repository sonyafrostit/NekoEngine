#include "NekoScript.h"
#include "NekoInstance.h"

#include <boost/python.hpp>
#include <boost/python/exec.hpp>

namespace py = boost::python;

namespace NekoEngine {

	BOOST_PYTHON_MODULE(neko)
	{
		py::class_<NekoInstance>("NekoInstance")
			.def("loadScene", &NekoInstance::loadScene, py::arg("new_scene"))
			.def("update", &NekoInstance::update, py::arg("scene"))
			.def("render", &NekoInstance::render, py::arg("scene"));

		py::class_<NekoScene>("NekoScene", py::init<int, int, std::string>())
			.def("getWindowTitle", &NekoScene::getWindowTitle)
			.def("onQuit", &NekoScene::onQuit);
	}
	void init_script_engine() {
		Py_Initialize();
		try {
			py::object main_module = py::import("__main__");
			py::object main_namespace = main_module.attr("__dict__");
			py::dict global, local;
			global["__builtins__"] = main_namespace["__builtins__"];
			initneko();
			exec_file("main.py", global, local);
		}
		catch (const py::error_already_set&) {
			PyErr_Print();
		}
	
	}
	void cleanup_script_engine() {
#ifdef _DEBUG
		system("PAUSE");
#endif
	}
}