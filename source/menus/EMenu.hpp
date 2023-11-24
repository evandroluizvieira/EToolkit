#ifndef EMENU_HPP
#define EMENU_HPP

#include <EToolkit>
#include <EContainer>

#include <windows.h>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{
	class BaseWindow;
	class MenuItemBase;
	class MenuItem;
	class SubMenu;

	class ETOOLKIT_API Menu{
		friend class BaseWindow;
		friend class BaseWindowPrivate;
		friend class MenuBar;
		friend class MenuItem;
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
			 * @description: Function that remove (and deletes) the 'menuItemBase' from the menu.
			 * @return: None.
			 * @note: If 'menuItemBase.getType()' is 'MenuItemBase::Type::SubMenu'this will remove all its MenuItemBase recursively.
			 */
			//void remove(MenuItemBase* menuItemBase);

			/*
			 * @description: Function to get all pointers of the menu items base.
			 * @return: An array with all items pointers in the menu.
			 */
			DynamicArray<MenuItemBase*> getItems() const;

		private:
			BaseWindow* owner;
			HMENU hmenu;
			DynamicArray<MenuItemBase*> items;
	};
}

#endif /* EMENU_HPP */
