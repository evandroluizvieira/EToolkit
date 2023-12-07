#ifndef EMENUITEMPRIVATE_HPP
#define EMENUITEMPRIVATE_HPP

#include "../menus/EMenuItem.hpp"
#include "../menus/EMenuItemBasePrivate.hpp"

namespace EToolkit{
	class MenuItemBase;

	class MenuItemPrivate : public MenuItemBasePrivate{
		friend class Menu;
		friend class MenuItem;

		public:
			MenuItemPrivate();
			virtual ~MenuItemPrivate();

			static void InkoveCallback(MenuItemBase* menuItemBase, unsigned int param);

		private:
			unsigned int id;
			MenuItem::OnClickEvent callback;
	};
}

#endif /* EMENUITEMPRIVATE_HPP */
