#ifndef EBASEWINDOW_HPP
#define EBASEWINDOW_HPP

#include <EToolkit>
#include <EControl>
#include <EMenu>
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
	class BaseWindowPrivate;

	/*
	 * @description: Base window class.
	 * @note: Can't use, instead use 'Window' or 'GLWindow'.
	 *
	 */
	class ETOOLKIT_API BaseWindow : public Control{
			friend class ControlPrivate;
			friend class GLWindow;
			friend class Window;

		private:
			/*
			 * @description: Private default constructor that prevents object instantiation.
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

			/*
			 * @description: Function that set menu bar for the window.
			 * @return: None.
			 */
			void setMenuBar(MenuBar* menuBar);

			/*
			 * @description: Function that removes (and deletes) the menu bar from the window if there is any.
			 * @return: None.
			 */
			void removeMenuBar();

			/*
			 * @description: Function to get the menu bar if exists or null pointer otherwise.
			 * @return: An pointer in the window.
			 */
			MenuBar* getMenuBar() const;

			/*
			 * @description: Function that closes the window.
			 * @return: None.
			 * @note: After closing everything in the window will be deleted.
			 */
			void close();

		protected:
			/*
			 * @description: Default inheritable function called whenever this window gains or looses focus, gains when 'focus' is true and looses otherwise.
			 * @return: None.
			 */
			virtual void onFocus(bool focus);

			/*
			 * @description: Default inheritable function called whenever this window is being enabled or disabled, enabled when 'enable' is true and disabled otherwise.
			 * @return: None.
			 */
			virtual void onEnable(bool enable);

			/*
			 * @description: Default inheritable function called whenever this window is being shown or hidden, shown when 'visible' is true and hidden otherwise.
			 * @return: None.
			 */
			virtual void onVisible(bool visible);

			/*
			 * @description: Default inheritable function called in every time title is changed.
			 * @return: None.
			 */
			virtual void onTitleChanged(const String& newText);

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
