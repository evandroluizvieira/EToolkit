#ifndef EKEYBOARDKEYEVENT_HPP
#define EKEYBOARDKEYEVENT_HPP

#include <EToolkit>
#include <EEventsData>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that holds keyboard 'key' and 'state' information.
	 */
	class ETOOLKIT_API KeyboardKeyEvent{
		public:
			/*
			 * @description: Constructor that initialize object with the given 'key' and 'state' values.
			 * @return: None.
			 */
			KeyboardKeyEvent(KeyboardKey::Key key, UpDownState::State state);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~KeyboardKeyEvent();

		public:
			//Specifies the keyboard key of the requested event. This can be one of the event key type values.
			KeyboardKey::Key key;

			//Specifies the keyboard key state of the requested event. This can be one of the event state type values.
			UpDownState::State state;
	};
}

#endif /* EKEYBOARDKEYEVENT_HPP */
