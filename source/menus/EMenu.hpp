#ifndef EMENU_HPP
#define EMENU_HPP

#include <EToolkit>
#include <EContainer>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{
	class MenuPrivate;
	class MenuItemBase;
	class MenuItem;
	class SubMenu;

	/*
	 * @description: Generic menu  that serves base of MenuBar and SubMenu.
	 * @note: MenuItem and SubMenu objects added here need to be pointers.
	 *
	 */
	class ETOOLKIT_API Menu{
		friend class BaseWindow;
		friend class BaseWindowPrivate;
		friend class MenuBar;
		friend class MenuItem;
		friend class MenuItemPrivate;
		friend class SubMenu;

		public:
			/*
			 * @description: Default window constructor.
			 * @return: None.
			 */
			Menu();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Menu();

			/*
			 * @description: Function that insert the 'menuItem' into the menu bar.
			 * @return: None.
			 */
			void add(MenuItem* menuItem);

			/*
			 * @description: Function that remove (and deletes) the 'menuItem' from the menu.
			 * @return: None.
			 */
			void remove(MenuItem* menuItem);

			/*
			 * @description: Function that insert the 'subMenu' into the menu.
			 * @return: None.
			 */
			void add(SubMenu* subMenu);

			/*
			 * @description: Function that remove (and deletes) the 'subMenu' from the menu.
			 * @return: None.
			 */
			void remove(SubMenu* subMenu);

			/*
			 * @description: Function to get all pointers of the menu items base.
			 * @return: An array with all items pointers in the menu.
			 */
			DynamicArray<MenuItemBase*> getItems() const;

		private:
			MenuPrivate* menuPrivate;
	};
}

#endif /* EMENU_HPP */
