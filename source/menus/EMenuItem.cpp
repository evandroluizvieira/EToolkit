#include "../menus/EMenuPrivate.hpp"
#include "../menus/EMenuItem.hpp"
#include "../menus/EMenuItemPrivate.hpp"
#include "../menus/EMenuItemBase.hpp"

#include <new>

EToolkit::MenuItem::MenuItem(const String& text, const OnClickEvent& callback) :
	MenuItemBase(){

	MenuItemPrivate* menuItemPrivate = new (std::nothrow) MenuItemPrivate();
	if(menuItemPrivate == nullptr){
		throw MemoryAllocationException();
	}

	menuItemPrivate->type = MenuItemBasePrivate::Type::MenuItem;
	menuItemPrivate->text = text;
	menuItemPrivate->callback = callback;

	menuItemBasePrivate = menuItemPrivate;
}

EToolkit::MenuItem::~MenuItem(){
	MenuItemPrivate* menuItemPrivate = dynamic_cast<MenuItemPrivate*>(menuItemBasePrivate);
	if(menuItemPrivate != nullptr){
		delete menuItemPrivate;
	}
	menuItemBasePrivate = nullptr;
}

void EToolkit::MenuItem::setCallback(const OnClickEvent& callback){
	if(menuItemBasePrivate != nullptr){
		MenuItemPrivate* menuItemPrivate = dynamic_cast<MenuItemPrivate*>(menuItemBasePrivate);
		if(menuItemPrivate != nullptr){
			menuItemPrivate->callback = callback;
		}
	}
}

EToolkit::String EToolkit::MenuItem::getText(){
	String result;
	if(menuItemBasePrivate != nullptr){
		if(menuItemBasePrivate->parent != nullptr && menuItemBasePrivate->parent->menuPrivate != nullptr && menuItemBasePrivate->parent->menuPrivate->hmenu != nullptr){
			MenuItemPrivate* menuItemPrivate = dynamic_cast<MenuItemPrivate*>(menuItemBasePrivate);
			if(menuItemPrivate != nullptr){
				if(menuItemPrivate->text.isEmpty() == true){
					int textLength = ::GetMenuString(menuItemBasePrivate->parent->menuPrivate->hmenu, menuItemPrivate->id, nullptr, 0, MF_BYCOMMAND);
					if(textLength > 0){
						char* menuItemText = new char[textLength + 1];
						::GetMenuString(menuItemBasePrivate->parent->menuPrivate->hmenu, menuItemPrivate->id, menuItemText, textLength + 1, MF_BYCOMMAND);
						menuItemPrivate->text = menuItemText;
						delete[] menuItemText;
					}
				}
			}
		}
		result = menuItemBasePrivate->text;
	}
	return result;
}

void EToolkit::MenuItem::setText(const String& text){
	if(menuItemBasePrivate != nullptr){
		if(menuItemBasePrivate->parent != nullptr && menuItemBasePrivate->parent->menuPrivate != nullptr && menuItemBasePrivate->parent->menuPrivate->hmenu != nullptr){
			MenuItemPrivate* menuItemPrivate = dynamic_cast<MenuItemPrivate*>(menuItemBasePrivate);
			if(menuItemPrivate != nullptr){
				::ModifyMenu(menuItemBasePrivate->parent->menuPrivate->hmenu, menuItemPrivate->id, MF_BYCOMMAND | MF_STRING, menuItemPrivate->id, text.getData());
			}
		}
		menuItemBasePrivate->text = text;
	}
}
