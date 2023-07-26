#include "../events/EMouseWheelEvent.hpp"

#include <windows.h>

const int EToolkit::MouseWheelEvent::MOUSE_WHEEL_DELTA = WHEEL_DELTA;

EToolkit::MouseWheelEvent::MouseWheelEvent(const Position2i& position, VirtualKey::VirtualKeyType virtualKey, int wheelDelta) :
	MouseMoveEvent(position, virtualKey), wheelDelta(wheelDelta){

}

EToolkit::MouseWheelEvent::~MouseWheelEvent(){

}
