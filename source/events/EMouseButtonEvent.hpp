#ifndef EMOUSEBUTTONEVENT_HPP
#define EMOUSEBUTTONEVENT_HPP

#include <EToolkit>
#include <EEvents>
#include <EEventsData>
#include <EPosition>

//#include "EMouseMoveEvent.hpp"

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that holds mouse 'button' and 'state' information.
	 */
	class ETOOLKIT_API MouseButtonEvent : public MouseMoveEvent{
		public:
			/*
			 * @description: Constructor that initialize object with the given 'position', 'virtualKey', 'button' and 'state' values.
			 * @return: None.
			 */
			MouseButtonEvent(const Position2i& position, VirtualKey::VirtualKeyType virtualKey, MouseButton::MouseButtonType button, UpDownState::State state);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~MouseButtonEvent();

		public:
			//Specifies the mouse button of the requested event.
			MouseButton::MouseButtonType button;

			//Specifies the mouse button state of the requested event.
			UpDownState::State state;
	};
}

#endif /* EMOUSEBUTTONEVENT_HPP */
