#include "../events/EVirtualKeyPrivate.hpp"

#include <windows.h>

EToolkit::VirtualKey::VirtualKeyType EToolkit::VirtualKeyPrivate::getVirtualKeyFrom(unsigned int wParam){
	VirtualKey::VirtualKeyType type = VirtualKey::VirtualKey_Unknonw;

	if(MK_CONTROL == wParam){
		type = VirtualKey::VirtualKey_Control;
	}else if(MK_LBUTTON == wParam){
		type = VirtualKey::VirtualKey_LeftMouseButton;
	}else if(MK_MBUTTON == wParam){
		type = VirtualKey::VirtualKey_MiddleMouseButton;
	}else if(MK_RBUTTON == wParam){
		type = VirtualKey::VirtualKey_RightMouseButton;
	}else if(MK_SHIFT == wParam){
		type = VirtualKey::VirtualKey_Shift;
	}

	return type;
}
