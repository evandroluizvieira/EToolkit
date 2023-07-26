#ifndef ERESIZEWINDOWEVENT_HPP
#define ERESIZEWINDOWEVENT_HPP

#include <EToolkit>
#include <EEvents>
#include <ESize>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that holds window 'size' and 'resize' type event.
	 */
	class ETOOLKIT_API ResizeWindowEvent{
		public:
			/*
			 * @description: Constructor that initialize object with the given 'size' and 'resizeWindow' values.
			 * @return: None.
			 */
			ResizeWindowEvent(const Size2i& size, ResizeWindow::ResizeWindowType resizeWindow);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~ResizeWindowEvent();

		public:
			//Specifies the new width and height of the client area.
			Size2i size;

			//Specifies the type of resizing requested. This can be one of the previously values.
			ResizeWindow::ResizeWindowType resizeWindow;
	};
}

#endif /* ERESIZEWINDOWEVENT_HPP */
