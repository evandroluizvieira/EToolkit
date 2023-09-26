#ifndef EMOUSEMOVEEVENT_HPP
#define EMOUSEMOVEEVENT_HPP

#include <EToolkit>
#include <EEventsData>
#include <EPosition>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that holds mouse position and virtual key information.
	 */
	class ETOOLKIT_API MouseMoveEvent{
		public:
			/*
			 * @description: Constructor that initialize object with the given 'position' and 'virtualKey' value.
			 * @return: None.
			 */
			MouseMoveEvent(const Position2i& position, VirtualKey::VirtualKeyType virtualKey);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~MouseMoveEvent();

		public:
			//Specifies the position x and y coordinate of the cursor. The coordinate is relative to the upper-left corner of the client area.
			Position2i position;

			//Indicates whether various virtual key are down.
			VirtualKey::VirtualKeyType virtualKey;
	};
}

#endif /* EMOUSEMOVEEVENT_HPP */
