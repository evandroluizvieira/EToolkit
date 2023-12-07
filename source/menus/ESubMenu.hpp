#ifndef ESUBMENU_HPP
#define ESUBMENU_HPP

#include <EToolkit>
#include <EMenu>
#include <EString>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Menu bar that serves as a navigation and organizational tool to be used in a window.
	 */
	class ETOOLKIT_API SubMenu : public Menu, public MenuItemBase{
		public:
			/*
			 * @description: Constructor that initializes the object with a copy of the the given 'text'.
			 * @return: None.
			 */
			SubMenu(const String& text);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~SubMenu();

			/*
			 * @description: Get the text of the menu page.
			 * @return: Copy of text value.
			 */
			String getText();
	};
}

#endif /* ESUBMENU_HPP */
