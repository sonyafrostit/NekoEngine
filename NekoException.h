#ifndef NEKOEXCEPTION_H
#define NEKOEXCEPTION_H
#include <exception>

namespace NekoEngine {
	class NekoInitFailException : public std::exception {
	
		virtual const char* what() const throw()
		{
			return "SDL failed to initialize";
		}
	};
	class NekoExitException : public std::exception {
		virtual const char* what() const throw()
		{
			return "Exit Signal Recieved";
		}
	};
	class NekoNoSceneException : public std::exception {
		virtual const char* what() const throw()
		{
			return "Engine cannot be started without a valid NekoScene!";
		}
	};
}
#endif