#ifndef EBUTTON_HPP
#define EBUTTON_HPP

#include <EToolkit>
#include <EControl>
#include <EString>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{
	class Window;

	/*
	 * @description: This class represents a button used in a window.
	 * @note: Control objects need to be pointers to be released by the owner window when necessary.
	 */
	class ETOOLKIT_API Button : public Control{
		friend class ControlPrivate;

		public:
			/*
			 * @description: List of horizontal possible text positions.
			 */
			enum class TextHorizontalPosition{
				//Non defined horizontal position of the text.
				Unknown,

				//Places text in the middle horizontally in the button rectangle.
				Center,

				//Places text in the left of the button rectangle.
				Left,

				//Places text in the rightof the button rectangle.
				Right
			};

			/*
			 * @description: List of vertical possible text positions.
			 */
			enum class TextVerticalPosition{
				//Non defined vertical position of the text.
				Unknown,

				//Places text in the middle vertically in the button rectangle.
				Center,

				//Places text at the top of the button rectangle.
				Top,

				//Places text at the bottom of the button rectangle.
				Bottom
			};

			/*
			 * @description: Constructor that create the button with the given 'text' and then add to the given 'parent' window.
			 * @return: None.
			 */
			Button(Window& parent);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Button();

			/*
			 * @description: Get the text horizontal position type from 'TextHorizontalPosition' list.
			 * @return: Copy of control type.
			 */
			TextHorizontalPosition getTextHorizontalPosition() const;

			/*
			 * @description: Get the text vertical position type from 'TextVerticalPosition' list.
			 * @return: Copy of control type.
			 */
			TextVerticalPosition getTextVerticalPosition() const;

			/*
			 * @description: Set where the text in the button is to be placed with given 'horizontal' position and 'vertical' position.
			 * @return: None.
			 * @note: If 'TextHorizontalPosition::Unknown' or 'TextVerticalPosition::Unknown' they are ignored.
			 */
			void setTextPosition(TextHorizontalPosition horizontal, TextVerticalPosition vertical);

			/*
			 * @description: Check if the button text to multiple lines is set.
			 * @return: true if yes and false otherwise.
			 */
			bool isSetTextMultipleLines() const;

			/*
			 * @description: Wraps the button text to multiple lines if the text string is too long to fit on a single line in the button rectangle.
			 * @return: None.
			 */
			void setTextMultipleLines();

			/*
			 * @description: Unset the button text to multiple lines.
			 * @return: None.
			 */
			void unsetTextMultipleLines();

			/*
			 * @description: Check if the button flat design is set.
			 * @return: true if yes and false otherwise.
			 */
			bool isSetFlatDesign() const;

			/*
			 * @description: Specifies that the button is flat designed, a 2D GUI, it does not use the default shading to create a 3D image.
			 * @return: None.
			 */
			void setFlatDesign();

			/*
			 * @description: Unset that the button flat design.
			 * @return: None.
			 */
			void unsetFlatDesign();

		protected:
			/*
			 * @description: Inheritable function called when triggered by keyboard key space bar or mouse button release.
			 * @return: None.
			 * @note: When the second consecutive mouse button release occurs 'doubleClick' is true.
			 */
			virtual void onClick(bool doubleClick);

			/*
			 * @description: Inheritable function called whenever this control gains or looses focus, gains when 'focus' is true and looses otherwise.
			 * @return: None.
			 */
			virtual void onFocus(bool focus);
	};
}

#endif /* EBUTTON_HPP */
