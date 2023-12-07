#include "../controls/EControlPrivate.hpp"
#include "../menus/EMenuPrivate.hpp"
#include "../windows/EBaseWindow.hpp"

#include <windows.h>

EToolkit::MenuPrivate::MenuPrivate() :
	owner(nullptr), hmenu(nullptr), type(Type::Unknown){

}

EToolkit::MenuPrivate::~MenuPrivate(){

}


void EToolkit::MenuPrivate::redrawMenuBar(){
	if(owner != nullptr && owner->data != nullptr && owner->data->hwnd != nullptr){
		if(type == Type::MenuBar){
			::DrawMenuBar(owner->data->hwnd);
		}
	}
}
