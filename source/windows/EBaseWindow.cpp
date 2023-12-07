#include "../exceptions/EMemoryAllocationException.hpp"
#include "../menus/EMenu.hpp"
#include "../menus/EMenuPrivate.hpp"
#include "../menus/EMenuBar.hpp"
#include "../windows/EBaseWindow.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

#include <new>
#include <windows.h>

EToolkit::BaseWindow::BaseWindow() :
	Control(){
	data = new (std::nothrow) BaseWindowPrivate(this);
	if(data == nullptr){
		throw MemoryAllocationException();
	}
}

EToolkit::BaseWindow::~BaseWindow(){
	BaseWindowPrivate* dataBaseWindow = dynamic_cast<BaseWindowPrivate*>(data);
	if(dataBaseWindow == nullptr){
		return;
	}

	delete dataBaseWindow;
	data = nullptr;
}

void EToolkit::BaseWindow::setMenuBar(MenuBar* menuBar){
	BaseWindowPrivate* dataBaseWindow = dynamic_cast<BaseWindowPrivate*>(data);
	if(dataBaseWindow == nullptr || dataBaseWindow->hwnd == nullptr){
		return;
	}

	if(menuBar == nullptr || menuBar->menuPrivate == nullptr || menuBar->menuPrivate->hmenu == nullptr){
		return;
	}

	if(::SetMenu(dataBaseWindow->hwnd, menuBar->menuPrivate->hmenu) == 0){
		throw WindowsAPIException("cannot set menu bar into window");
	}

	menuBar->menuPrivate->owner = this;
	dataBaseWindow->menuBar = menuBar;
}

void EToolkit::BaseWindow::removeMenuBar(){
	BaseWindowPrivate* dataBaseWindow = dynamic_cast<BaseWindowPrivate*>(data);
	if(dataBaseWindow == nullptr || dataBaseWindow->hwnd == nullptr || dataBaseWindow->menuBar == nullptr){
		return;
	}

	::SetMenu(dataBaseWindow->hwnd, NULL);

	delete dataBaseWindow->menuBar;
	dataBaseWindow->menuBar = 0;
}

EToolkit::MenuBar* EToolkit::BaseWindow::getMenuBar() const{
	BaseWindowPrivate* dataBaseWindow = dynamic_cast<BaseWindowPrivate*>(data);
	if(dataBaseWindow != nullptr){
		return dataBaseWindow->menuBar;
	}

	return nullptr;
}

void EToolkit::BaseWindow::close(){
	if(data != nullptr && data->hwnd != nullptr){
		::SendMessage(data->hwnd, WM_CLOSE, 0, 0);
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
