#include "../menus/EMenuItemBase.hpp"

EToolkit::MenuItemBase::MenuItemBase() :
	parent(nullptr), type(Type::Unknown){

}

EToolkit::MenuItemBase::~MenuItemBase(){

}

EToolkit::MenuItemBase::Type EToolkit::MenuItemBase::getType() const{
	return type;
}
