#include "../controls/EButton.hpp"
#include "../controls/EControlPrivate.hpp"
#include "../exceptions/EMemoryAllocationException.hpp"
#include "../exceptions/EWindowsAPIException.hpp"
#include "../windows/EWindow.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

#include <windows.h>
#include <commctrl.h>
#include <new>

EToolkit::Button::Button(Window& parent) :
	Control(){

	data = new (std::nothrow) ControlPrivate(this);
	if(data == 0){
		throw MemoryAllocationException();
	}

	HINSTANCE instance = ::GetModuleHandle(0);
	if(instance == 0){
		delete data;
		data = 0;

		throw(WindowsAPIException("cannot get module handle"));
	}

	if(parent.data == 0 || parent.data->hwnd == 0){
		throw(WindowsAPIException("invalid window parent"));
	}

	data->hwnd = ::CreateWindowEx(0, WC_BUTTON, "Button",  WS_CHILD | BS_PUSHBUTTON | BS_NOTIFY | BS_TEXT | BS_CENTER | BS_VCENTER, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, parent.data->hwnd, (HMENU)data->id, instance, 0);
	if(data->hwnd == 0){
		delete data;
		data = 0;

		throw(WindowsAPIException("cannot create push button"));
	}

	data->type = Control::Type::Type_Button;

	BaseWindowPrivate* baseWindowData = (BaseWindowPrivate*)parent.data;
	baseWindowData->addControl(this);
}

EToolkit::Button::~Button(){
	if(data != 0){
		::DestroyWindow(data->hwnd);
		data->hwnd = 0;

		delete data;
		data = 0;
	}
}

EToolkit::Button::TextHorizontalPosition EToolkit::Button::getTextHorizontalPosition() const{
	if(data != 0){
		if(data->hasStyle(BS_CENTER) == true){
			return TextHorizontalPosition::Center;
		}

		if(data->hasStyle(BS_LEFT) == true){
			return TextHorizontalPosition::Left;
		}

		if(data->hasStyle(BS_RIGHT) == true){
			return TextHorizontalPosition::Right;
		}
	}
	return TextHorizontalPosition::Unknown;
}

EToolkit::Button::TextVerticalPosition EToolkit::Button::getTextVerticalPosition() const{
	if(data != 0){
		if(data->hasStyle(BS_VCENTER) == true){
			return TextVerticalPosition::Center;
		}

		if(data->hasStyle(BS_TOP) == true){
			return TextVerticalPosition::Top;
		}

		if(data->hasStyle(BS_BOTTOM) == true){
			return TextVerticalPosition::Bottom;
		}
	}
	return TextVerticalPosition::Unknown;
}

void EToolkit::Button::setTextPosition(TextHorizontalPosition horizontal, TextVerticalPosition vertical){
	if(data != 0){
		if(horizontal != TextHorizontalPosition::Unknown){
			data->removeStyle(BS_CENTER | BS_LEFT | BS_RIGHT, false);

			if(horizontal == TextHorizontalPosition::Center){
				data->addStyle(BS_CENTER);
			}else if(horizontal == TextHorizontalPosition::Left){
				data->addStyle(BS_LEFT);
			}else if(horizontal == TextHorizontalPosition::Right){
				data->addStyle(BS_RIGHT);
			}
		}

		if(vertical != TextVerticalPosition::Unknown){
			data->removeStyle(BS_VCENTER | BS_TOP | BS_BOTTOM, false);

			if(vertical == TextVerticalPosition::Center){
				data->addStyle(BS_VCENTER);
			}else if(vertical == TextVerticalPosition::Top){
				data->addStyle(BS_TOP);
			}else if(vertical == TextVerticalPosition::Bottom){
				data->addStyle(BS_BOTTOM);
			}
		}
	}
}

bool EToolkit::Button::isSetTextMultipleLines() const{
	if(data != 0){
		return data->hasStyle(BS_MULTILINE);
	}

	return false;
}

void EToolkit::Button::setTextMultipleLines(){
	if(data != 0){
		data->addStyle(BS_MULTILINE);
	}
}

void EToolkit::Button::unsetTextMultipleLines(){
	if(data != 0){
		data->removeStyle(BS_MULTILINE);
	}
}

bool EToolkit::Button::isSetFlatDesign() const{
	if(data != 0){
		return data->hasStyle(BS_FLAT);
	}

	return false;
}

void EToolkit::Button::setFlatDesign(){
	if(data != 0){
		data->addStyle(BS_FLAT);
	}
}

void EToolkit::Button::unsetFlatDesign(){
	if(data != 0){
		data->removeStyle(BS_FLAT);
	}
}

void EToolkit::Button::onClick(bool doubleClick){

}

void EToolkit::Button::onFocus(bool focus){

}

