#ifndef EMOUSEBUTTON_HPP
#define EMOUSEBUTTON_HPP

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: List of mouse button information.
	 */
	class MouseButton{
		private:
			/*
			 * @description: Private default constructor that prevents object instantiation.
			 * @return: None.
			 */
			MouseButton();

		public:
			/*
			 * @description: List of mouse buttons.
			 */
			enum MouseButtonType{
				//This flag is used when the mouse button is unknown.
				MouseButton_Unknown,

				//This flag is used when the left mouse button is in use.
				MouseButton_Left,

				//This flag is used when the middle mouse button is in use.
				MouseButton_Right,

				//This flag is used when the right mouse button is down.
				MouseButton_Middle
			};
	};
}

#endif /* EMOUSEBUTTON_HPP */
