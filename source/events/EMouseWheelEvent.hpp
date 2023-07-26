#ifndef EMOUSEWHEELEVENT_HPP
#define EMOUSEWHEELEVENT_HPP

#include <EToolkit>
#include <EEvents>
#include <EPosition>

#include "EMouseMoveEvent.hpp"

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that holds mouse middle button rotation information.
	 */
	class ETOOLKIT_API MouseWheelEvent : public MouseMoveEvent{
		public:
			/*
			 * @description: Constructor that initialize object with the given 'position', 'virtualKey' and 'wheelDelta' values.
			 * @return: None.
			 */
			MouseWheelEvent(const Position2i& position, VirtualKey::VirtualKeyType virtualKey, int wheelDelta);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~MouseWheelEvent();

		public:
			//This value is used to calculate steps rotation of mouse wheel.
			static const int MOUSE_WHEEL_DELTA;

		public:
			//Indicates the distance the wheel is rotated, expressed in multiples or divisions of MOUSE_WHEEL_DELTA. A positive value indicates that the wheel was rotated forward, away from the user; a negative value indicates that the wheel was rotated backward, toward the user.
			int wheelDelta;
	};
}

#endif /* EMOUSEWHEELEVENT_HPP */
