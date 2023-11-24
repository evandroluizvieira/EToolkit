#include "../menus/EMenuItem.hpp"
#include "../menus/EMenuItemBase.hpp"
#include "../menus/ESubMenu.hpp"

EToolkit::MenuItem::MenuItem(const String& text, const OnClickEvent& callback) :
	MenuItemBase(){

	static unsigned int ID = 500;
	this->id = ++ID;
	this->type = MenuItemBase::Type::MenuItem;
	this->text = text;
	this->callback = callback;
}

EToolkit::MenuItem::~MenuItem(){

}

void EToolkit::MenuItem::setCallback(const OnClickEvent& callback){
	this->callback = callback;
}

EToolkit::String EToolkit::MenuItem::getText(){
	if(parent != nullptr){
		int textLength = ::GetMenuString(parent->hmenu, id, nullptr, 0, MF_BYCOMMAND);

		if(textLength > 0){
			char* menuItemText = new char[textLength + 1];
			::GetMenuString(parent->hmenu, id, menuItemText, textLength + 1, MF_BYCOMMAND);
			text = menuItemText;
			delete[] menuItemText;
		}
	}
	return text;
}

void EToolkit::MenuItem::setText(const String& text){
	if(parent != nullptr && parent->hmenu != nullptr){
		::ModifyMenu(parent->hmenu, id, MF_BYCOMMAND | MF_STRING, id, text.getData());
	}
	this->text = text;
}

void EToolkit::MenuItem::InkoveCallback(MenuItemBase* menuItemBase, unsigned int param){
	if(menuItemBase != nullptr){
		MenuItemBase::Type t = menuItemBase->getType();
		if(t == MenuItemBase::Type::MenuItem){
			MenuItem* menuItem = dynamic_cast<MenuItem*>(menuItemBase);
			if(menuItem != nullptr){
				if(param == menuItem->id){
					menuItem->callback();
				}
			}
		}else if(t == MenuItemBase::Type::SubMenu){
			SubMenu* subMenu = dynamic_cast<SubMenu*>(menuItemBase);
			if(subMenu != nullptr){
				unsigned int itemsSize = subMenu->items.getSize();
				for(unsigned int i = 0; i < itemsSize; ++i){
					MenuItem::InkoveCallback(subMenu->items.get(i), param);
				}
			}
		}
	}
}
