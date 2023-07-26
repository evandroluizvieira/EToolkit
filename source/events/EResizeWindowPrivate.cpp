#include "../events/EResizeWindowPrivate.hpp"

#include <windows.h>

EToolkit::ResizeWindow::ResizeWindowType EToolkit::ResizeWindowPrivate::getResizeFlagFrom(unsigned int wParam){
	ResizeWindow::ResizeWindowType type = ResizeWindow::ResizeWindow_Unknonw;

	if(wParam == SIZE_MAXIMIZED){
		type = ResizeWindow::ResizeWindow_Maximized;
	}else if(wParam == SIZE_MAXHIDE){
		type = ResizeWindow::ResizeWindow_MaximizedHide;
	}else if(wParam == SIZE_MAXSHOW){
		type = ResizeWindow::ResizeWindow_MaximizedShow;
	}else if(wParam == SIZE_MINIMIZED){
		type = ResizeWindow::ResizeWindow_Minimized;
	}else if(wParam == SIZE_RESTORED){
		type = ResizeWindow::ResizeWindow_Restored;
	}

	return type;
}
