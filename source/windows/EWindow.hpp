#ifndef EWINDOW_HPP
#define EWINDOW_HPP

#include <EToolkit>
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
	};
}

#endif /* EWINDOW_HPP */
