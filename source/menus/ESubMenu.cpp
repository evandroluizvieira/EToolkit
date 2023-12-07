#include "../exceptions/EMemoryAllocationException.hpp"
#include "../exceptions/EWindowsAPIException.hpp"
#include "../menus/EMenu.hpp"
#include "../menus/EMenuPrivate.hpp"
#include "../menus/EMenuItemBase.hpp"
#include "../menus/EMenuItemBasePrivate.hpp"
#include "../menus/ESubMenu.hpp"

#include <new>
#include <windows.h>

EToolkit::SubMenu::SubMenu(const String& text) :
	Menu(), MenuItemBase(){

	menuPrivate = new (std::nothrow) MenuPrivate();
	if(menuPrivate == nullptr){
		throw MemoryAllocationException();
	}

	menuItemBasePrivate = new (std::nothrow) MenuItemBasePrivate();
	if(menuItemBasePrivate == nullptr){
		throw MemoryAllocationException();
	}

	menuPrivate->hmenu = ::CreatePopupMenu();
	if(menuPrivate->hmenu == nullptr){
		throw WindowsAPIException("cannot create sub menu");
	}

	menuPrivate->type = MenuPrivate::Type::SubMenu;
	menuItemBasePrivate->type = MenuItemBasePrivate::Type::SubMenu;
	menuItemBasePrivate->text = text;
}

EToolkit::SubMenu::~SubMenu(){
	if(menuPrivate != nullptr){
		delete menuPrivate;
		menuPrivate = nullptr;
	}

	if(menuItemBasePrivate != nullptr){
		delete menuItemBasePrivate;
		menuItemBasePrivate = nullptr;
	}
}

EToolkit::String EToolkit::SubMenu::getText(){
	String result;
	if(menuItemBasePrivate != nullptr){
		if(menuPrivate != nullptr && menuPrivate->hmenu != nullptr){
			if(menuItemBasePrivate->text.isEmpty() == true){
				int textLength = ::GetMenuString(menuPrivate->hmenu, 0, nullptr, 0, MF_BYCOMMAND);
				if(textLength > 0){
					char* subMenuText = new char[textLength + 1];
					::GetMenuString(menuPrivate->hmenu, 0, subMenuText, textLength + 1, MF_BYCOMMAND);
					menuItemBasePrivate->text = subMenuText;
					delete[] subMenuText;
				}
			}
		}
		result = menuItemBasePrivate->text;
	}
	return result;
}
