#include "../controls/EButton.hpp"
#include "../controls/EControlPrivate.hpp"
#include "../exceptions/EMemoryAllocationException.hpp"
#include "../exceptions/EWindowsAPIException.hpp"
#include "../windows/EWindow.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

#include <new>
#include <windows.h>
#include <commctrl.h>

EToolkit::Button::Button(Window& parent) :
	Control(){
	if(parent.data == nullptr || parent.data->hwnd == NULL){
		throw(WindowsAPIException("invalid window parent"));
	}

	data = new (std::nothrow) ControlPrivate(this);
	if(data == nullptr){
		throw MemoryAllocationException();
	}

	HINSTANCE instance = ::GetModuleHandle(NULL);
	if(instance == NULL){
		delete data;
		data = nullptr;

		throw(WindowsAPIException("cannot get module handle"));
	}

	data->hwnd = ::CreateWindowEx(0, WC_BUTTON, "Button",  WS_CHILD | BS_PUSHBUTTON | BS_NOTIFY | BS_TEXT | BS_CENTER | BS_VCENTER, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, parent.data->hwnd, (HMENU)data->id, instance, 0);
	if(data->hwnd == NULL){
		delete data;
		data = nullptr;

		throw(WindowsAPIException("cannot create push button"));
	}

	data->type = Control::Type::Type_Button;

	BaseWindowPrivate* baseWindowData = (BaseWindowPrivate*)parent.data;
	baseWindowData->addControl(this);
}

EToolkit::Button::~Button(){
	if(data != nullptr){
		::DestroyWindow(data->hwnd);
		data->hwnd = NULL;

		delete data;
		data = nullptr;
	}
}

EToolkit::Button::TextHorizontalPosition EToolkit::Button::getTextHorizontalPosition() const{
	if(data != nullptr){
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
	if(data != nullptr){
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
	if(data != nullptr){
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
	if(data != nullptr){
		return data->hasStyle(BS_MULTILINE);
	}

	return false;
}

void EToolkit::Button::setTextMultipleLines(){
	if(data != nullptr){
		data->addStyle(BS_MULTILINE);
	}
}

void EToolkit::Button::unsetTextMultipleLines(){
	if(data != nullptr){
		data->removeStyle(BS_MULTILINE);
	}
}

bool EToolkit::Button::isSetFlatDesign() const{
	if(data != nullptr){
		return data->hasStyle(BS_FLAT);
	}

	return false;
}

void EToolkit::Button::setFlatDesign(){
	if(data != nullptr){
		data->addStyle(BS_FLAT);
	}
}

void EToolkit::Button::unsetFlatDesign(){
	if(data != nullptr){
		data->removeStyle(BS_FLAT);
	}
}

void EToolkit::Button::onClick(bool doubleClick){

}

void EToolkit::Button::onFocus(bool focus){

}

