#ifndef ELABEL_HPP
#define ELABEL_HPP

#include <EToolkit>
#include <EControl>
#include <EString>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{
	class Window;

	/*
	 * @description: This class represents a Label used in a window.
	 * @note: Control objects need to be pointers to be released by the owner window when necessary.
	 */
	class ETOOLKIT_API Label : public Control{
			friend class ControlPrivate;

		public:
			/*
			 * @description: List of possible text alignments.
			 */
			enum class TextAlignment{
				//Left-aligns the text in the rectangle. Words that extend past the end of a line are automatically wrapped to the beginning of the next left-aligned line. Words that are longer than the width of the control are truncated.
				Left,

				//Centers the text in the rectangle. Words that extend past the end of a line are automatically wrapped to the beginning of the next centered line. Words that are longer than the width of the control are truncated.
				Center,

				//Right-aligns the text in the rectangle. Words that extend past the end of a line are automatically wrapped to the beginning of the next right-aligned line. Words that are longer than the width of the control are truncated.
				Right
			};

			/*
			 * @description: List of usage of text ellipsis.
			 */
			enum class TextEllipsis{
				//If the end of a string does not fit in the rectangle, it is truncated and ellipses are added, if a word that is not at the end of the string goes beyond the limits of the rectangle, it is truncated without ellipses. Using this style will force the text to be on one line with no word wrap.
				End,

				//Truncates any word that does not fit in the rectangle and adds ellipses. Using this flag will force the text to be on one line with no word wrap.
				Word,

				//Replaces characters in the middle of the string with ellipses so that the result fits in the specified rectangle, if the string contains backslash (\) characters, this flag preserves as much as possible of the text after the last backslash. Using this style will force the text to be on one line with no word wrap.
				Path
			};

			/*
			 * @description: Constructor that create the label with the given 'text' and with a sunken border if the given 'addSunkenBorder' are true and then add to the given 'parent' window.
			 * @return: None.
			 * @note: Only constructor can handle sunken border design.
			 */
			Label(Window& parent, const String& text = "", bool addSunkenBorder = false);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Label();

			/*
			 * @description: Check if the text alignment with the given 'alignment' is set.
			 * @return: true if yes and false otherwise.
			 */
			bool isSetTextAlignment(TextAlignment alignment) const;

			/*
			 * @description: Set text alignment with the given 'alignment'.
			 * @return: None.
			 * @note: They are exclusive, can set one by time.
			 */
			void setTextAlignment(TextAlignment alignment);

			/*
			 * @description: Check if the text ellipsis with the given 'type' is set.
			 * @return: true if yes and false otherwise.
			 */
			bool isSetTextEllipsis(TextEllipsis type) const;

			/*
			 * @description: Set text ellipsis with the given 'type'.
			 * @return: None.
			 * @note: They are not exclusive, can set many as you want.
			 */
			void setTextEllipsis(TextEllipsis type);

			/*
			 * @description: Unset text ellipsis of the given 'type'.
			 * @return: None.
			 */
			void unsetTextEllipsis(TextEllipsis type);

		protected:
			/*
			 * @description: Inheritable function called when triggered by left mouse button press.
			 * @return: None.
			 * @note: When the second consecutive mouse button release  occurs 'doubleClick' is true.
			 */
			virtual void onClick(bool doubleClick);
	};
}

#endif /* ELABEL_HPP */
