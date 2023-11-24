#ifndef EMENUBAR_HPP
#define EMENUBAR_HPP

#include <EToolkit>
#include <EContainer>

#include "../menus/EMenu.hpp"

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Menu bar that serves as a navigation and organizational tool to be used in a window.
	 * @note: Menu bar objects need to be pointers to be released by the owner window when necessary.
	 *
	 */
	class ETOOLKIT_API MenuBar : public Menu{

		public:
			/*
			 * @description: Default window constructor.
			 * @return: None.
			 */
			MenuBar();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~MenuBar();
	};
}

#endif /* EMENUBAR_HPP */
