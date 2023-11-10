#include "../exceptions/EMemoryAllocationException.hpp"
#include "../windows/EBaseWindow.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

#include <new>

EToolkit::BaseWindow::BaseWindow() :
	Control(){
	data = new (std::nothrow) BaseWindowPrivate(this);
	if(data == 0){
		throw MemoryAllocationException();
	}
}

EToolkit::BaseWindow::~BaseWindow(){
	if(data != 0){
		BaseWindowPrivate* baseWindowData = (BaseWindowPrivate*)data;
		delete baseWindowData;
		data = 0;
	}
}

void EToolkit::BaseWindow::onFocus(bool focus){

}

void EToolkit::BaseWindow::onEnable(bool enable){

}

void EToolkit::BaseWindow::onVisible(bool visible){

}

void EToolkit::BaseWindow::onTitleChanged(const String& newText){

}

void EToolkit::BaseWindow::onMove(const Position2i& event){

}

void EToolkit::BaseWindow::onResize(const ResizeWindowEvent& event){

}

void EToolkit::BaseWindow::onKeyboardKey(const KeyboardKeyEvent& event){

}

void EToolkit::BaseWindow::onMouseMove(const MouseMoveEvent& event){

}

void EToolkit::BaseWindow::onMouseButton(const MouseButtonEvent& event){

}

void EToolkit::BaseWindow::onMouseWheel(const MouseWheelEvent& event){

}
