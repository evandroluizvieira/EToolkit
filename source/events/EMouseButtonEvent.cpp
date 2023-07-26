#include "../events/EMouseButtonEvent.hpp"

EToolkit::MouseButtonEvent::MouseButtonEvent(const Position2i& position, VirtualKey::VirtualKeyType virtualKey, MouseButton::MouseButtonType button, UpDownState::State state) :
	MouseMoveEvent(position, virtualKey), button(button), state(state){

}

EToolkit::MouseButtonEvent::~MouseButtonEvent(){

}
