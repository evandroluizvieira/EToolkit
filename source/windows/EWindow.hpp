#ifndef EWINDOW_HPP
#define EWINDOW_HPP

#include <EToolkit>
#include <EControl>
#include <EContainer>
#include <EWindow>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Main window.
	 */
	class ETOOLKIT_API Window : public BaseWindow{
		public:
			/*
			 * @description: Default window constructor.
			 * @return: None.
			 */
			Window();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Window();

			/*
			 * @description: Function that remove (and deletes) the 'control' from the window.
			 * @return: None.
			 * @note: Have to be one of the controls in the window.
			 */
			void remove(Control* control);

			/*
			 * @description: Function to get all pointers of the controls from the window.
			 * @return: An array with all pointers in the window.
			 */
			DynamicArray<Control*> getControls();
	};
}

#endif /* EWINDOW_HPP */
