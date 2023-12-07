#ifndef EMENUPRIVATE_HPP
#define EMENUPRIVATE_HPP

#include "../containers/EDynamicArray.hpp"
#include "../menus/EMenu.hpp"

#include <windows.h>

namespace EToolkit{
	class BaseWindow;
	class MenuItemBase;

	class MenuPrivate{
		friend class BaseWindow;
		friend class BaseWindowPrivate;
		friend class Menu;
		friend class MenuBar;
		friend class MenuItem;
		friend class MenuItemPrivate;
		friend class SubMenu;

		public:
			enum class Type{
				Unknown,
				MenuBar,
				SubMenu
			};

			MenuPrivate();
			virtual ~MenuPrivate();

			void redrawMenuBar();

		private:
			BaseWindow* owner;
			HMENU hmenu;
			Type type;
			DynamicArray<MenuItemBase*> items;
	};
}

#endif /* EMENUPRIVATE_HPP */
