#ifndef EBASEWINDOW_HPP
#define EBASEWINDOW_HPP

#include <EToolkit>
#include <EControl>
#include <EPosition>
#include <EString>

#include "../events/EKeyboardKeyEvent.hpp"
#include "../events/EMouseMoveEvent.hpp"
#include "../events/EMouseButtonEvent.hpp"
#include "../events/EMouseWheelEvent.hpp"
#include "../events/EResizeWindowEvent.hpp"

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{
	//forward declaration of private class
	class BaseWindowPrivate;

	/*
	 * @description: Base window class.
	 */
	class ETOOLKIT_API BaseWindow : public Control{
			friend class ControlPrivate;
			friend class GLWindow;
			friend class Window;

		private:
			/*
			 * @description: Private default constructor what prevent object instantiation.
			 * @return: None.
			 */
			BaseWindow();

		public:
			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~BaseWindow();

			/*
			 * @description: Get the title of the window.
			 * @return: Copy of text value.
			 * @note: Same as 'getText' from base class;
			 */
			inline String getTitle() const{
					return getText();
			}

			/*
			 * @description: Set the window title with the given 'title' value.
			 * @return: None.
			 * @note: Same as 'setText' from base class;
			 */
			inline void setTitle(const String& title){
				setText(title);
			}

		protected:
			/*
			 * @description: Default inheritable function called whenever the windows gains or looses focus, gains when 'focus' is true and looses otherwise.
			 * @return: None.
			 */
			virtual void onFocus(bool focus);

			/*
			 * @description: Default inheritable function called whenever the windows is being enabled or disabled, enabled when 'enable' is true and disabled otherwise.
			 * @return: None.
			 */
			virtual void onEnable(bool enable);

			/*
			 * @description: Default inheritable function called whenever the windows is being shown or hidden, shown when 'visible' is true and hidden otherwise.
			 * @return: None.
			 */
			virtual void onVisible(bool visible);

			/*
			 * @description: Default inheritable function called in every time text is changed.
			 * @return: None.
			 */
			virtual void onTextChanged(const String& newText);

			/*
			 * @description: Default inheritable function called in every movimentation event.
			 * @return: None.
			 */
			virtual void onMove(const Position2i& newPosition);

			/*
			 * @description: Default inheritable function called in every resize event.
			 * @return: None.
			 */
			virtual void onResize(const ResizeWindowEvent& event);

			/*
			 * @description: Default inheritable function called in every keyboard event.
			 * @return: None.
			 */
			virtual void onKeyboardKey(const KeyboardKeyEvent& event);

			/*
			 * @description: Default inheritable function called in every mouse movement event.
			 * @return: None.
			 */
			virtual void onMouseMove(const MouseMoveEvent& event);

			/*
			 * @description: Default inheritable function called in every mouse button event.
			 * @return: None.
			 */
			virtual void onMouseButton(const MouseButtonEvent& event);

			/*
			 * @description: Default inheritable function called in every mouse wheel button event.
			 * @return: None.
			 */
			virtual void onMouseWheel(const MouseWheelEvent& event);
	};
}

#endif /* EBASEWINDOW_HPP */
