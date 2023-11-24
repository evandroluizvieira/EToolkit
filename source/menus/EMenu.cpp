#include "../controls/EControlPrivate.hpp"
#include "../menus/EMenu.hpp"
#include "../menus/EMenuItem.hpp"
#include "../menus/EMenuItemBase.hpp"
#include "../menus/ESubMenu.hpp"
#include "../windows/EBaseWindow.hpp"

EToolkit::Menu::Menu() :
	owner(nullptr), hmenu(nullptr){

}

EToolkit::Menu::~Menu(){
	unsigned int itemsSize = items.getSize();
	for(unsigned int i = 0; i < itemsSize; ++i){
		MenuItemBase* current = items.get(i);
		if(current != nullptr){
			if(current->getType() == MenuItemBase::Type::MenuItem){
	            MenuItem* item = dynamic_cast<MenuItem*>(current);
	            if(item != nullptr){
	            	delete item;
	            }
			}else if(current->getType() == MenuItemBase::Type::SubMenu){
	            SubMenu* subMenu = dynamic_cast<SubMenu*>(current);
	            if(subMenu != nullptr){
	            	delete subMenu;
	            }
			}else{
				delete current;
			}
		}
	}
	items.clear();

	if(hmenu != nullptr){
		::DestroyMenu(hmenu);
		hmenu = nullptr;
	}
}

void EToolkit::Menu::add(MenuItem* menuItem){
	if(hmenu == nullptr || menuItem == nullptr){
		return;
	}

	if(::AppendMenu(hmenu, MF_STRING, menuItem->id, menuItem->getText().getData()) != 0){
		items.insertBack(menuItem);
		menuItem->parent = this;
	}
}

void EToolkit::Menu::add(SubMenu* subMenu){
	if(hmenu == nullptr || subMenu == nullptr){
		return;
	}

	if(subMenu->hmenu != nullptr){
		if(AppendMenu(hmenu, MF_POPUP, reinterpret_cast<UINT_PTR>(subMenu->hmenu), subMenu->getText().getData()) != 0){
			if(owner != nullptr && owner->data != nullptr && owner->data->hwnd != nullptr){
				::DrawMenuBar(owner->data->hwnd);
			}

			items.insertBack(subMenu);
			subMenu->parent = this;
		}else{
	        DestroyMenu(subMenu->hmenu);
	        subMenu->hmenu = nullptr;
		}
	}
}

void EToolkit::Menu::remove(MenuItem* menuItem){
	if(hmenu == nullptr || menuItem == nullptr){
		return;
	}

	int itemsCount = ::GetMenuItemCount(hmenu);
	for(int i = 0; i < itemsCount; ++i){
		UINT id = ::GetMenuItemID(hmenu, i);
		if(id == menuItem->id){
			::RemoveMenu(hmenu, i, MF_BYPOSITION);

			unsigned int itemsSize = items.getSize();
			for(unsigned int j = 0; j < itemsSize; ++j){
				if(menuItem == items.get(j)){
					items.remove(j);
					break;
				}
			}

			if(owner != nullptr && owner->data != nullptr && owner->data->hwnd != nullptr){
				::DrawMenuBar(owner->data->hwnd);
			}

			delete menuItem;
			break;
		}
	}
}

void EToolkit::Menu::remove(SubMenu* subMenu){
	if(hmenu == nullptr || subMenu == nullptr){
		return;
	}

	int itemsCount = ::GetMenuItemCount(hmenu);
	for(int i = 0; i < itemsCount; ++i){
		HMENU subMenuHandle = ::GetSubMenu(hmenu, i);
		if(subMenuHandle == subMenu->hmenu){
			::RemoveMenu(hmenu, i, MF_BYPOSITION);

			unsigned int itemsSize = items.getSize();
			for(unsigned int j = 0; j < itemsSize; ++j){
				if(subMenu == items.get(j)){
					items.remove(j);
					break;
				}
			}

			delete subMenu;

			if(owner != nullptr && owner->data != nullptr && owner->data->hwnd != nullptr){
				::DrawMenuBar(owner->data->hwnd);
			}
			break;
		}
	}
}

//void EToolkit::Menu::remove(MenuItemBase* menuItemBase){
//	if(hmenu == nullptr || menuItemBase == nullptr){
//		return;
//	}
//
//	MenuItemBase::Type type = menuItemBase->getType();
//	int itemsCount = ::GetMenuItemCount(hmenu);
//	if(type == MenuItemBase::Type::MenuItem){
//		for(int i = 0; i < itemsCount; ++i){
//			MenuItem* menuItem = dynamic_cast<MenuItem*>(menuItemBase);
//			if(menuItem != nullptr){
//				UINT id = ::GetMenuItemID(hmenu, i);
//				if(id == menuItem->id){
//					::RemoveMenu(hmenu, i, MF_BYPOSITION);
//
//					unsigned int itemsSize = items.getSize();
//					for(unsigned int j = 0; j < itemsSize; ++j){
//						if(menuItem == items.get(j)){
//							items.remove(j);
//							break;
//						}
//					}
//
//					delete menuItem;
//					break;
//				}
//			}
//		}
//	}else if(type == MenuItemBase::Type::SubMenu){
//		for(int i = 0; i < itemsCount; ++i){
//			SubMenu* subMenu = dynamic_cast<MenuItem*>(menuItemBase);
//			if(subMenu != nullptr){
//				UINT_PTR subMenuHandle = ::GetSubMenu(hmenu, i);
//				if(subMenuHandle == (UINT_PTR)subMenu->hmenu){
//					::RemoveMenu(hmenu, i, MF_BYPOSITION);
//
//					unsigned int itemsSize = items.getSize();
//					for(unsigned int j = 0; j < itemsSize; ++j){
//						if(subMenu == items.get(j)){
//							items.remove(j);
//							break;
//						}
//					}
//
//					remove(subMenu);
//
//					delete subMenu;
//					break;
//				}
//			}
//		}
//	}
//}

EToolkit::DynamicArray<EToolkit::MenuItemBase*> EToolkit::Menu::getItems() const{
	return items;
}
