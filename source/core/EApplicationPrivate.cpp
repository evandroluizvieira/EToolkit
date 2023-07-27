#include "../core/EApplicationPrivate.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

EToolkit::ApplicationPrivate::ApplicationPrivate() :
	running(false){

}

EToolkit::ApplicationPrivate::~ApplicationPrivate(){
	running = false;
}

std::vector<EToolkit::BaseWindow*>& EToolkit::ApplicationPrivate::BaseWindows(){
	static std::vector<BaseWindow*> windows;
	return windows;
}

std::vector<EToolkit::GLWindow*> EToolkit::ApplicationPrivate::GLWindows(){
	std::vector<GLWindow*> glWindows;

	int totalWindows = BaseWindows().size();
	for(int i = 0; i < totalWindows; i++){
		BaseWindow* baseWindow = BaseWindows().at(i);
		if(baseWindow != 0 && baseWindow->getType() == Control::Type_GLWindow){
			glWindows.push_back(reinterpret_cast<GLWindow*>(baseWindow));
		}
	}

	return glWindows;
}

void EToolkit::ApplicationPrivate::GLWindowsInitialize(){
	int totalWindows = BaseWindows().size();
	for(int i = 0; i < totalWindows; i++){
		BaseWindow* baseWindow = BaseWindows().at(i);
		if(baseWindow != 0 && baseWindow->getType() == Control::Type_GLWindow){
			GLWindow* glWindow = reinterpret_cast<GLWindow*>(baseWindow);
			if(glWindow != 0){
				glWindow->glInitialize();
			}
		}
	}
}

void EToolkit::ApplicationPrivate::GLWindowsFinalize(){
	int totalWindows = BaseWindows().size();
	for(int i = 0; i < totalWindows; i++){
		BaseWindow* baseWindow = BaseWindows().at(i);
		if(baseWindow != 0 && baseWindow->getType() == Control::Type_GLWindow){
			GLWindow* glWindow = reinterpret_cast<GLWindow*>(baseWindow);
			if(glWindow != 0){
				glWindow->glFinalize();
			}
		}
	}
}

void EToolkit::ApplicationPrivate::GLWindowsPaint(){
	int totalWindows = BaseWindows().size();
	for(int i = 0; i < totalWindows; i++){
		BaseWindow* baseWindow = BaseWindows().at(i);
		if(baseWindow != 0 && baseWindow->getType() == Control::Type_GLWindow){
			BaseWindowPrivate* baseWindowPrivate = reinterpret_cast<BaseWindowPrivate*>(baseWindow->data);
			if(baseWindowPrivate != 0){
				GLWindow* glWindow = reinterpret_cast<GLWindow*>(baseWindow);
				if(glWindow != 0){
					baseWindowPrivate->activeGL(true);
					glWindow->glPaint();
					baseWindowPrivate->activeGL(false);
					baseWindowPrivate->swapBufferGL();
				}
			}
		}
	}
}
