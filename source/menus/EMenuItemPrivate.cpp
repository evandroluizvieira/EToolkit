#include "../menus/EMenuPrivate.hpp"
#include "../menus/EMenuItemPrivate.hpp"
#include "../menus/EMenuItemBase.hpp"
#include "../menus/EMenuItemBasePrivate.hpp"
#include "../menus/ESubMenu.hpp"

EToolkit::MenuItemPrivate::MenuItemPrivate() :
	MenuItemBasePrivate(), callback(nullptr){

	static unsigned int ID = 500;
	id = ++ID;
}

EToolkit::MenuItemPrivate::~MenuItemPrivate(){

}

void EToolkit::MenuItemPrivate::InkoveCallback(MenuItemBase* menuItemBase, unsigned int param){
	if(menuItemBase != nullptr && menuItemBase->menuItemBasePrivate != nullptr){
		MenuItemBasePrivate::Type type = menuItemBase->menuItemBasePrivate->type;
		if(type == MenuItemBasePrivate::Type::MenuItem){
			MenuItem* currentMenuItem = dynamic_cast<MenuItem*>(menuItemBase);
			if(currentMenuItem != nullptr && currentMenuItem->menuItemBasePrivate != nullptr){
				MenuItemPrivate* currentMenuItemPrivate = dynamic_cast<MenuItemPrivate*>(currentMenuItem->menuItemBasePrivate);
				if(currentMenuItemPrivate != nullptr){
					if(param == currentMenuItemPrivate->id){
						currentMenuItemPrivate->callback();
					}
				}
			}
		}else if(type == MenuItemBasePrivate::Type::SubMenu){
			SubMenu* subMenu = dynamic_cast<SubMenu*>(menuItemBase);
			if(subMenu != nullptr && subMenu->menuItemBasePrivate != nullptr && subMenu->menuPrivate != nullptr){
				unsigned int itemsSize = subMenu->menuPrivate->items.getSize();
				for(unsigned int i = 0; i < itemsSize; ++i){
					MenuItemBase* currentMenuItemInSubMenu = subMenu->menuPrivate->items.get(i);
					if(currentMenuItemInSubMenu != nullptr && currentMenuItemInSubMenu->menuItemBasePrivate != nullptr){
						MenuItemPrivate::InkoveCallback(currentMenuItemInSubMenu, param);
					}
				}
			}
		}
	}
}
