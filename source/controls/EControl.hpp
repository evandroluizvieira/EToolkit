#ifndef ECONTROL_HPP
#define ECONTROL_HPP

#include <EToolkit>
#include <EBounds>
#include <EPosition>
#include <ESize>
#include <EString>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{
	class ControlPrivate;

	/*
	 * @description: This class is the base class of all user interface objects.
	 */
	class ETOOLKIT_API Control{
		friend class ApplicationPrivate;
		friend class BaseWindow;
		friend class BaseWindowPrivate;
		friend class GLWindow;
		friend class Window;
		friend class Menu;
		friend class MenuPrivate;
		friend class MenuBar;
		friend class MenuItem;
		friend class Button;
		friend class Label;

		public:
			/*
			 * @description: List of all possibles controls and windows.
			 */
			enum Type{
				Type_None,
				Type_Window,
				Type_GLWindow,
				Type_Button,
				Type_Label
			};

		public:
			/*
			 * @description: Default constructor.
			 * @return: None.
			 */
			Control();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Control();

			/*
			 * @description: Get the control type from 'Type' list.
			 * @return: Copy of control type.
			 */
			Type getType() const;

			/*
			 * @description: Check if this container have the keyboard focus.
			 * @return: true if have it and false otherwise.
			 */
			bool hasFocus() const;

			/*
			 * @description: Set the keyboard focus to the component if 'active' is true and looses otherwise.
			 * @return: None.
			 */
			void setFocusability(bool active);

			/*
			 * @description: Check if this container is enabled.
			 * @return: true if enable and false otherwise.
			 */
			bool isEnable() const;

			/*
			 * @description: Enable the input of this container if 'enable' value is true and disable otherwise.
			 * @return: None.
			 */
			void setEnability(bool enable);

			/*
			 * @description: Check if this container is visible.
			 * @return: true if visible and false otherwise.
			 */
			bool isVisible() const;

			/*
			 * @description: Set the container visible if 'visible' value is true and hide otherwise.
			 * @return: None.
			 */
			void setVisibility(bool visible);

			/*
			 * @description: Get the text of the component.
			 * @return: Copy of text value.
			 */
			String getText() const;

			/*
			 * @description: Set the text of the component with the given 'text' value.
			 * @return: None.
			 */
			void setText(const String& text);

			/*
			 * @description: Get the position of the control.
			 * @return: A copy of the position values.
			 */
			Position2i getPosition() const;

			/*
			 * @description: Set the position with the 'position' value.
			 * @return: None.
			 */
			void setPosition(const Position2i& position);

			/*
			 * @description: Set the position with the 'x' and 'y' value.
			 * @return: None.
			 */
			void setPosition(int x, int y);

			/*
			 * @description: Get the size of the control.
			 * @return: A copy of the size values.
			 */
			Size2i getSize() const;

			/*
			 * @description: Set the size with the 'size' value.
			 * @return: None.
			 */
			void setSize(const Size2i& size);

			/*
			 * @description: Set the size with the 'width' and 'height' value.
			 * @return: None.
			 */
			void setSize(int width, int height);

			/*
			 * @description: Get the position and size of the window.
			 * @return: A copy of the boundary values.
			 */
			Bounds2i getBounds() const;

			/*
			 * @description: Set the boundary with the 'bounds' value.
			 * @return: None.
			 */
			void setBounds(const Bounds2i& bounds);

			/*
			 * @description: Set the boundary with the 'x', 'y', 'width' and 'height' values.
			 * @return: None.
			 */
			void setBounds(int x, int y, int width, int height);

		private:
			ControlPrivate* data;
	};
}

#endif /* ECONTROL_HPP */
