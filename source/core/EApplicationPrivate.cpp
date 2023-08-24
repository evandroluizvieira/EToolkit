#include "../core/EApplicationPrivate.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

EToolkit::ApplicationPrivate::ApplicationPrivate() :
	running(false){

}

EToolkit::ApplicationPrivate::~ApplicationPrivate(){
	running = false;
}

EToolkit::DynamicArray<EToolkit::BaseWindow*>& EToolkit::ApplicationPrivate::BaseWindows(){
	static DynamicArray<BaseWindow*> windows;
	return windows;
}

EToolkit::DynamicArray<EToolkit::GLWindow*> EToolkit::ApplicationPrivate::GLWindows(){
	DynamicArray<GLWindow*> glWindows;
	unsigned int totalWindows = BaseWindows().getSize();
	for(unsigned int i = 0; i < totalWindows; i++){
		BaseWindow* baseWindow = BaseWindows().get(i);
		if(baseWindow != 0 && baseWindow->getType() == Control::Type_GLWindow){
			glWindows.insertBack(reinterpret_cast<GLWindow*>(baseWindow));
		}
	}

	return glWindows;
}

void EToolkit::ApplicationPrivate::GLWindowsInitialize(){
	unsigned int totalWindows = BaseWindows().getSize();
	for(unsigned int i = 0; i < totalWindows; i++){
		BaseWindow* baseWindow = BaseWindows().get(i);
		if(baseWindow != 0 && baseWindow->getType() == Control::Type_GLWindow){
			GLWindow* glWindow = reinterpret_cast<GLWindow*>(baseWindow);
			if(glWindow != 0){
				glWindow->glInitialize();
			}
		}
	}
}

void EToolkit::ApplicationPrivate::GLWindowsFinalize(){
	unsigned int totalWindows = BaseWindows().getSize();
	for(unsigned int i = 0; i < totalWindows; i++){
		BaseWindow* baseWindow = BaseWindows().get(i);
		if(baseWindow != 0 && baseWindow->getType() == Control::Type_GLWindow){
			GLWindow* glWindow = reinterpret_cast<GLWindow*>(baseWindow);
			if(glWindow != 0){
				glWindow->glFinalize();
			}
		}
	}
}

void EToolkit::ApplicationPrivate::GLWindowsPaint(){
	unsigned int totalWindows = BaseWindows().getSize();
	for(unsigned int i = 0; i < totalWindows; i++){
		BaseWindow* baseWindow = BaseWindows().get(i);
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
