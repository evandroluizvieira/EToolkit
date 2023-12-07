#ifndef EMENUITEMBASEPRIVATE_HPP
#define EMENUITEMBASEPRIVATE_HPP

#include "../menus/EMenuItemBase.hpp"
#include "../string/EString.hpp"

namespace EToolkit{
	class Menu;

	class MenuItemBasePrivate{
		friend class Menu;
		friend class MenuItem;
		friend class MenuItemPrivate;
		friend class SubMenu;

		public:
			enum class Type{
				Unknown,
				MenuItem,
				SubMenu
			};

			MenuItemBasePrivate();
			virtual ~MenuItemBasePrivate();

		private:

			Menu* parent;
			Type type;
			String text;
	};
}

#endif /* EMENUITEMBASEPRIVATE_HPP */
