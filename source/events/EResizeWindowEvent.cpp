#include "../events/EResizeWindowEvent.hpp"

EToolkit::ResizeWindowEvent::ResizeWindowEvent(const Size2i& size, ResizeWindow::ResizeWindowType resizeWindow) :
	size(size), resizeWindow(resizeWindow){

}

EToolkit::ResizeWindowEvent::~ResizeWindowEvent(){

}
