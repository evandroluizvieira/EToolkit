#include "../containers/EDynamicArray.hpp"
#include "../menus/EMenu.hpp"
#include "../menus/EMenuPrivate.hpp"
#include "../menus/EMenuItem.hpp"
#include "../menus/EMenuItemPrivate.hpp"
#include "../menus/EMenuItemBase.hpp"
#include "../menus/EMenuItemBasePrivate.hpp"
#include "../menus/ESubMenu.hpp"

#include <windows.h>

EToolkit::Menu::Menu() :
	menuPrivate(nullptr){

}

EToolkit::Menu::~Menu(){
	if(menuPrivate == nullptr){
		return;
	}

	unsigned int itemsSize = menuPrivate->items.getSize();
	for(unsigned int i = 0; i < itemsSize; ++i){
		MenuItemBase* current = menuPrivate->items.get(i);
		if(current != nullptr && current->menuItemBasePrivate != nullptr){
			if(current->menuItemBasePrivate->type == MenuItemBasePrivate::Type::MenuItem){
	            MenuItem* item = dynamic_cast<MenuItem*>(current);
	            if(item != nullptr){
	            	delete item;
	            }
			}else if(current->menuItemBasePrivate->type == MenuItemBasePrivate::Type::SubMenu){
	            SubMenu* subMenu = dynamic_cast<SubMenu*>(current);
	            if(subMenu != nullptr){
	            	delete subMenu;
	            }
			}else{
				delete current;
			}
		}
	}
	menuPrivate->items.clear();

	if(menuPrivate->hmenu != nullptr){
		::DestroyMenu(menuPrivate->hmenu);
		menuPrivate->hmenu = nullptr;
	}

	delete menuPrivate;
	menuPrivate = nullptr;
}

void EToolkit::Menu::add(MenuItem* menuItem){
	if(menuPrivate == nullptr || menuPrivate->hmenu == nullptr || menuItem == nullptr || menuItem->menuItemBasePrivate == nullptr){
		return;
	}

	MenuItemPrivate* menuItemPrivate = dynamic_cast<MenuItemPrivate*>(menuItem->menuItemBasePrivate);
	if(menuItemPrivate != nullptr){
		if(::AppendMenu(menuPrivate->hmenu, MF_STRING, menuItemPrivate->id, menuItem->getText().getData()) != 0){
			menuPrivate->redrawMenuBar();

			menuPrivate->items.insertBack(menuItem);
			menuItem->menuItemBasePrivate->parent = this;
		}
	}
}

void EToolkit::Menu::remove(MenuItem* menuItem){
	if(menuPrivate == nullptr || menuPrivate->hmenu == nullptr || menuItem == nullptr || menuItem->menuItemBasePrivate == nullptr){
		return;
	}

	MenuItemPrivate* menuItemPrivate = dynamic_cast<MenuItemPrivate*>(menuItem->menuItemBasePrivate);
	if(menuItemPrivate == nullptr){
		return;
	}

	int itemsCount = ::GetMenuItemCount(menuPrivate->hmenu);
	for(int i = 0; i < itemsCount; ++i){
		UINT id = ::GetMenuItemID(menuPrivate->hmenu, i);
		if(id == menuItemPrivate->id){
			::RemoveMenu(menuPrivate->hmenu, i, MF_BYPOSITION);

			unsigned int itemsSize = menuPrivate->items.getSize();
			for(unsigned int j = 0; j < itemsSize; ++j){
				if(menuItem == menuPrivate->items.get(j)){
					menuPrivate->items.remove(j);
					break;
				}
			}

			delete menuItem;

			menuPrivate->redrawMenuBar();

			break;
		}
	}
}

void EToolkit::Menu::add(SubMenu* subMenu){
	if(menuPrivate == nullptr || menuPrivate->hmenu == nullptr || subMenu == nullptr ||
		subMenu->menuPrivate == nullptr || subMenu->menuPrivate->hmenu == nullptr ||
		subMenu->menuItemBasePrivate == nullptr){
		return;
	}

	if(AppendMenu(menuPrivate->hmenu, MF_POPUP, (UINT_PTR)(subMenu->menuPrivate->hmenu), subMenu->getText().getData()) != 0){
		menuPrivate->redrawMenuBar();

		menuPrivate->items.insertBack(subMenu);
		subMenu->menuItemBasePrivate->parent = this;
	}else{
		::DestroyMenu(subMenu->menuPrivate->hmenu);
		subMenu->menuPrivate->hmenu = nullptr;
	}
}

void EToolkit::Menu::remove(SubMenu* subMenu){
	if(menuPrivate == nullptr || menuPrivate->hmenu == nullptr || subMenu == nullptr){
		return;
	}

	int itemsCount = ::GetMenuItemCount(menuPrivate->hmenu);
	for(int i = 0; i < itemsCount; ++i){
		HMENU subMenuHandle = ::GetSubMenu(menuPrivate->hmenu, i);
		if(subMenuHandle == subMenu->menuPrivate->hmenu){
			::RemoveMenu(menuPrivate->hmenu, i, MF_BYPOSITION);

			unsigned int itemsSize = menuPrivate->items.getSize();
			for(unsigned int j = 0; j < itemsSize; ++j){
				if(subMenu == menuPrivate->items.get(j)){
					menuPrivate->items.remove(j);
					break;
				}
			}

			delete subMenu;

			menuPrivate->redrawMenuBar();

			break;
		}
	}
}

EToolkit::DynamicArray<EToolkit::MenuItemBase*> EToolkit::Menu::getItems() const{
	DynamicArray<MenuItemBase*> result;
	if(menuPrivate != nullptr){
		unsigned int itemsSize = menuPrivate->items.getSize();
		for(unsigned int i = 0; i < itemsSize; ++i){
			result.insertBack(menuPrivate->items.get(i));
		}
	}
	return result;
}
