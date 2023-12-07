#include "../exceptions/EMemoryAllocationException.hpp"
#include "../exceptions/EWindowsAPIException.hpp"
#include "../menus/EMenuPrivate.hpp"
#include "../menus/EMenuBar.hpp"

#include <new>
#include <windows.h>

EToolkit::MenuBar::MenuBar() :
	Menu(){

	menuPrivate = new (std::nothrow) MenuPrivate();
	if(menuPrivate == nullptr){
		throw MemoryAllocationException();
	}

	menuPrivate->hmenu = ::CreateMenu();
	if(menuPrivate->hmenu == nullptr){
		throw WindowsAPIException("cannot create menu bar");
	}

	menuPrivate->type = MenuPrivate::Type::MenuBar;
}

EToolkit::MenuBar::~MenuBar(){

}
