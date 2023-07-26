#include "../events/EKeyboardKeyEvent.hpp"

EToolkit::KeyboardKeyEvent::KeyboardKeyEvent(KeyboardKey::Key key, UpDownState::State state) :
	key(key), state(state){

}

EToolkit::KeyboardKeyEvent::~KeyboardKeyEvent(){

}
