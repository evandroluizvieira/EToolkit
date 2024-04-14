#include "../controls/EControl.hpp"
#include "../controls/EControlPrivate.hpp"
#include "../controls/EButton.hpp"
#include "../controls/ELabel.hpp"
#include "../events/EKeyboardKeyEvent.hpp"
#include "../events/EKeyboardKeyPrivate.hpp"
#include "../events/EMouseButton.hpp"
#include "../events/EMouseMoveEvent.hpp"
#include "../events/EMouseButtonEvent.hpp"
#include "../events/EMouseWheelEvent.hpp"
#include "../events/EUpDownState.hpp"
#include "../events/EVirtualKeyPrivate.hpp"
#include "../events/EResizeWindowEvent.hpp"
#include "../events/EResizeWindowPrivate.hpp"
#include "../geometry/EPosition2.hpp"
#include "../geometry/ESize2.hpp"
#include "../windows/EBaseWindow.hpp"

#include <windowsx.h>

EToolkit::ControlPrivate::ControlPrivate(Control* owner) :
	owner(owner), hwnd(NULL), type(Control::Type::Type_None){

	//win api good practice start from 100
	static unsigned int ControlsID = 100;
	id = ++ControlsID;
}

EToolkit::ControlPrivate::~ControlPrivate(){

}

void EToolkit::ControlPrivate::processAllEvents(UINT message, WPARAM wParam, LPARAM lParam){
	if(owner == nullptr){
		return;
	}

	if(type == Control::Type_Window || type == Control::Type_GLWindow){
		processBaseWindowEvents((BaseWindow*)owner, message, wParam, lParam);
	}

	if(type == Control::Type_Button){
		processButtonEvents((Button*)owner, message, wParam, lParam);
	}

	if(type == Control::Type_Label){
		processLabelEvents((Label*)owner, message, wParam, lParam);
	}
}

void EToolkit::ControlPrivate::processBaseWindowEvents(BaseWindow* baseWindow, UINT message, WPARAM wParam, LPARAM lParam){
	switch(message){
		case WM_SETFOCUS:
			baseWindow->onFocus(true);
			break;
		case WM_KILLFOCUS:
			baseWindow->onFocus(false);
			break;

		case WM_ENABLE:
			baseWindow->onEnable(true);
			break;
		case WM_CANCELMODE:
			baseWindow->onEnable(false);
			break;

		case WM_SHOWWINDOW:
			if(wParam == TRUE){
				baseWindow->onVisible(true);
			}else if(wParam == FALSE){
				baseWindow->onVisible(false);
			}
			break;

		case WM_SETTEXT:
			baseWindow->onTitleChanged((char*)lParam);
			break;

		case WM_MOVE:
			baseWindow->onMove(Position2i(LOWORD(lParam), HIWORD(lParam)));
			break;

		case WM_SIZE:
			baseWindow->onResize(ResizeWindowEvent(Size2i(LOWORD(lParam), HIWORD(lParam)), ResizeWindowPrivate::getResizeFlagFrom(wParam)));
			break;

		case WM_KEYDOWN:
			baseWindow->onKeyboardKey(KeyboardKeyEvent(KeyboardKeyPrivate::getKeyFrom(wParam), UpDownState::State_Down));
			break;
		case WM_KEYUP:
			baseWindow->onKeyboardKey(KeyboardKeyEvent(KeyboardKeyPrivate::getKeyFrom(wParam), UpDownState::State_Up));
			break;

		case WM_MOUSEMOVE:
			baseWindow->onMouseMove(MouseMoveEvent(Position2i(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)), VirtualKeyPrivate::getVirtualKeyFrom(wParam)));
			break;
		case WM_MOUSEWHEEL:
			baseWindow->onMouseWheel(MouseWheelEvent(Position2i(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)), VirtualKeyPrivate::getVirtualKeyFrom(LOWORD(wParam)), GET_WHEEL_DELTA_WPARAM(wParam)));
			break;
		case WM_LBUTTONDOWN:
			baseWindow->onMouseButton(MouseButtonEvent(Position2i(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)), VirtualKeyPrivate::getVirtualKeyFrom(wParam), MouseButton::MouseButton_Left, UpDownState::State_Down));
			break;
		case WM_LBUTTONUP:
			baseWindow->onMouseButton(MouseButtonEvent(Position2i(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)), VirtualKeyPrivate::getVirtualKeyFrom(wParam), MouseButton::MouseButton_Left, UpDownState::State_Up));
			break;
		case WM_RBUTTONDOWN:
			baseWindow->onMouseButton(MouseButtonEvent(Position2i(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)), VirtualKeyPrivate::getVirtualKeyFrom(wParam), MouseButton::MouseButton_Right, UpDownState::State_Down));
			break;
		case WM_RBUTTONUP:
			baseWindow->onMouseButton(MouseButtonEvent(Position2i(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)), VirtualKeyPrivate::getVirtualKeyFrom(wParam), MouseButton::MouseButton_Right, UpDownState::State_Up));
			break;
		case WM_MBUTTONDOWN:
			baseWindow->onMouseButton(MouseButtonEvent(Position2i(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)), VirtualKeyPrivate::getVirtualKeyFrom(wParam), MouseButton::MouseButton_Middle, UpDownState::State_Down));
			break;
		case WM_MBUTTONUP:
			baseWindow->onMouseButton(MouseButtonEvent(Position2i(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam)), VirtualKeyPrivate::getVirtualKeyFrom(wParam), MouseButton::MouseButton_Middle, UpDownState::State_Up));
			break;
	}
}

void EToolkit::ControlPrivate::processButtonEvents(Button* button, UINT message, WPARAM wParam, LPARAM lParam){
	switch(HIWORD(wParam)){
		case BN_CLICKED:
			button->onClick(false);
			break;

		case BN_DBLCLK:
			button->onClick(true);
			break;

		case BN_KILLFOCUS:
			button->onFocus(false);
			break;

		case BN_SETFOCUS:
			button->onFocus(true);
			break;
	}
}

void EToolkit::ControlPrivate::processLabelEvents(Label* label, UINT message, WPARAM wParam, LPARAM lParam){
	switch(HIWORD(wParam)){
		case STN_CLICKED:
			label->onClick(false);
			break;

		case STN_DBLCLK:
			label->onClick(true);
			break;
	}
}

bool EToolkit::ControlPrivate::hasStyle(DWORD checkStyle){
	LONG_PTR style = ::GetWindowLongPtr(hwnd, GWL_STYLE);
	return (style & checkStyle) != 0;
}

void EToolkit::ControlPrivate::addStyle(DWORD styleToAdd, bool refresh){
	if(hwnd == NULL){
		return;
	}

	LONG_PTR style = ::GetWindowLongPtr(hwnd, GWL_STYLE);
	if((style & styleToAdd) == 0){
		style |= styleToAdd;
		::SetWindowLongPtr(hwnd, GWL_STYLE, style);
		if(refresh == true){
			::RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
		}
	}
}

void EToolkit::ControlPrivate::removeStyle(DWORD styleToRemove, bool refresh){
	if(hwnd == NULL){
		return;
	}

	LONG_PTR style = ::GetWindowLongPtr(hwnd, GWL_STYLE);
	if((style & styleToRemove) != 0){
		style &= ~styleToRemove;
		::SetWindowLongPtr(hwnd, GWL_STYLE, style);
		if(refresh == true){
			::RedrawWindow(hwnd, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
		}
	}
}
