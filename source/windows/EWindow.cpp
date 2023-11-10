#include "../core/EApplicationPrivate.hpp"
#include "../controls/EControlPrivate.hpp"
#include "../string/EString.hpp"
#include "../windows/EWindow.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

EToolkit::Window::Window() :
	BaseWindow(){

	if(data == 0){
		return;
	}

	data->type = Control::Type_Window;
	data->owner = this;

	String identifier = String::valueOfInteger(data->id);
	BaseWindowPrivate* privateData = (BaseWindowPrivate*)data;
	if(privateData->createWindow(identifier) == true){
		ApplicationPrivate::BaseWindows().insertBack(this);
	}
}

EToolkit::Window::~Window(){
	if(data == 0){
		return;
	}

	BaseWindowPrivate* privateData = (BaseWindowPrivate*)data;
	privateData->destroyWindow();
}


void EToolkit::Window::remove(Control* control){
	if(data == 0 || control == 0){
		return;
	}

	BaseWindowPrivate* baseWindowData = (BaseWindowPrivate*)data;
	baseWindowData->removeControl(control);
}

EToolkit::DynamicArray<EToolkit::Control*> EToolkit::Window::getControls(){
	DynamicArray<Control*> result;
	BaseWindowPrivate* baseWindowData = (BaseWindowPrivate*)data;
	if(baseWindowData != 0){
		unsigned int controlsSize = baseWindowData->controls.getSize();
		for(unsigned int i = 0; i < controlsSize; ++i){
			result.insertBack(baseWindowData->controls.get(i));
		}
	}
	return result;
}

