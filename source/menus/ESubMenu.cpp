#include "../exceptions/EMemoryAllocationException.hpp"
#include "../menus/EMenuItemBase.hpp"
#include "../menus/ESubMenu.hpp"

#include <windows.h>

EToolkit::SubMenu::SubMenu(const String& text) :
	Menu(), MenuItemBase(){
	this->type = MenuItemBase::Type::SubMenu;
	this->text = text;

	hmenu = ::CreatePopupMenu();
	if(hmenu == nullptr){
		throw WindowsAPIException("cannot create sub menu");
	}
}

EToolkit::SubMenu::~SubMenu(){

}

EToolkit::String EToolkit::SubMenu::getText(){
	if(hmenu != nullptr){
		int textLength = ::GetMenuString(hmenu, 0, nullptr, 0, MF_BYCOMMAND);
		if(textLength > 0){
			char* subMenuText = new char[textLength + 1];
			::GetMenuString(hmenu, 0, subMenuText, textLength + 1, MF_BYCOMMAND);
			this->text = subMenuText;
			delete[] subMenuText;
		}
	}
	return text;
}
