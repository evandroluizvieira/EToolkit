#include "../events/EMouseMoveEvent.hpp"

EToolkit::MouseMoveEvent::MouseMoveEvent(const Position2i& position, VirtualKey::VirtualKeyType virtualKey) :
	position(position), virtualKey(virtualKey){

}

EToolkit::MouseMoveEvent::~MouseMoveEvent(){

}
