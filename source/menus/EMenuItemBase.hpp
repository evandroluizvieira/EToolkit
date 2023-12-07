#ifndef EMENUITEMBASE_HPP
#define EMENUITEMBASE_HPP

#include <EToolkit>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{
	class MenuItemBasePrivate;

	/*
	 * @description: Menu generic item that serves base of MenuItem and SubMenu.
	 */
	class ETOOLKIT_API MenuItemBase{
		friend class Menu;
		friend class MenuItem;
		friend class MenuItemPrivate;
		friend class SubMenu;

		private:
			/*
			 * @description: Private default constructor that prevents object instantiation.
			 * @return: None.
			 */
			MenuItemBase();

		public:
			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~MenuItemBase();

		private:
			MenuItemBasePrivate* menuItemBasePrivate;
	};
}

#endif /* EMENUITEMBASE_HPP */
