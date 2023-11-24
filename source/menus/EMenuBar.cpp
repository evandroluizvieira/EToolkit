#include "../controls/EControl.hpp"
#include "../controls/EControlPrivate.hpp"
#include "../exceptions/EMemoryAllocationException.hpp"
#include "../exceptions/EWindowsAPIException.hpp"
#include "../menus/EMenuBar.hpp"
#include "../menus/EMenuItem.hpp"
#include "../windows/EBaseWindow.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

#include <windows.h>

EToolkit::MenuBar::MenuBar() :
	Menu(){

	hmenu = ::CreateMenu();
	if(hmenu == nullptr){
		throw WindowsAPIException("cannot create menu bar");
	}
}

EToolkit::MenuBar::~MenuBar(){

}
