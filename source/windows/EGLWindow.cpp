#include "../core/EApplicationPrivate.hpp"
#include "../controls/EControlPrivate.hpp"
#include "../windows/EGLWindow.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

EToolkit::GLWindow::GLWindow() :
	BaseWindow(){

	if(data == 0){
		return;
	}

	data->type = Control::Type_GLWindow;
	data->owner = this;

	String identifier = String::valueOfInteger(data->id);
	BaseWindowPrivate* privateData = (BaseWindowPrivate*)data;
	if(privateData->createGLWindow(identifier) == true){
		ApplicationPrivate::BaseWindows().insertBack(this);
	}
}

EToolkit::GLWindow::~GLWindow(){
	if(data == 0){
		return;
	}

	BaseWindowPrivate* privateData = (BaseWindowPrivate*)data;
	privateData->destroyGLWindow();
}

void EToolkit::GLWindow::glInitialize(){

}

void EToolkit::GLWindow::glFinalize(){

}

void EToolkit::GLWindow::glPaint(){

}
