#include "../controls/EControl.hpp"
#include "../controls/EControlPrivate.hpp"
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
	owner(owner), hwnd(0), type(Control::Type::Type_None){

	//win api good practice start from 100
	static int ControlsID = 100;
	id = ++ControlsID;
}

EToolkit::ControlPrivate::~ControlPrivate(){

}

void EToolkit::ControlPrivate::processBasicEvents(UINT message, WPARAM wParam, LPARAM lParam){
	if(owner == 0){
		return;
	}

	if(type == Control::Type_Window || type == Control::Type_GLWindow){
		processBaseWindowEvents(message, wParam, lParam);
	}
}

void EToolkit::ControlPrivate::processBaseWindowEvents(UINT message, WPARAM wParam, LPARAM lParam){
	BaseWindow* baseWindow = (BaseWindow*)owner;

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
			baseWindow->onTextChanged((char*)lParam);
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
