#include "../controls/EControl.hpp"
#include "../controls/EControlPrivate.hpp"
#include "../exceptions/EWindowsAPIException.hpp"
#include "../string/EStringPrivate.hpp"

#include <windows.h>

EToolkit::Control::Control() :
	data(0){

}

EToolkit::Control::~Control(){

}

EToolkit::Control::Type EToolkit::Control::getType() const{
	Type type = Type::Type_None;
	if(data != 0){
		type = (Type)data->type;
	}
	return type;
}

bool EToolkit::Control::hasFocus() const{
	if(data != 0){
		return ::GetFocus() == data->hwnd;
	}else{
		return false;
	}
}

void EToolkit::Control::setFocusability(bool active){
	if(data == 0 || data->hwnd == 0){
		return;
	}

	if(active == true){
		::SetFocus(data->hwnd);
	}else{
		::SetFocus(0);
	}
}

bool EToolkit::Control::isEnable() const{
	if(data != 0 && data->hwnd != 0 && ::IsWindowEnabled(data->hwnd) != 0){
		return true;
	}else{
		return false;
	}
}

void EToolkit::Control::setEnability(bool enable){
	if(data == 0 || data->hwnd == 0){
		return;
	}

	if(enable == true){
		::EnableWindow(data->hwnd, TRUE);
	}else{
		::EnableWindow(data->hwnd, FALSE);
	}
}

bool EToolkit::Control::isVisible() const{
	if(data != 0 && data->hwnd != 0 && ::IsWindowVisible(data->hwnd) != 0){
		return true;
	}else{
		return false;
	}
}

void EToolkit::Control::setVisibility(bool visible){
	if(data == 0 || data->hwnd == 0){
		return;
	}

	if(visible == true){
		::ShowWindow(data->hwnd, SW_SHOW);
	}else{
		::ShowWindow(data->hwnd, SW_HIDE);
	}
}

EToolkit::String EToolkit::Control::getText() const{
	String text;
	if(data != 0 && data->hwnd != 0){
		int textLength = ::GetWindowTextLength(data->hwnd);
		if(textLength > 0){
			textLength++;
			char buffer[textLength];
			if(::GetWindowText(data->hwnd, buffer, textLength) > 0){
				text = buffer;
			}
		}
	}
	return text;
}

void EToolkit::Control::setText(const String& text){
	if(data != 0 && data->hwnd != 0){
		if(::SetWindowText(data->hwnd, text.data->data) == 0){
			throw WindowsAPIException("invalid 'SetWindowText'");
		}
	}
}

EToolkit::Position2i EToolkit::Control::getPosition() const{
	return getBounds();
}

void EToolkit::Control::setPosition(const Position2i& position){
	Bounds2i bounds = getBounds();
	bounds.x = position.x;
	bounds.y = position.y;
	setBounds(bounds);
}

void EToolkit::Control::setPosition(int x, int y){
	Bounds2i bounds = getBounds();
	bounds.x = x;
	bounds.y = y;
	setBounds(bounds);
}

EToolkit::Size2i EToolkit::Control::getSize() const{
	return getBounds();
}

void EToolkit::Control::setSize(const Size2i& size){
	Bounds2i bounds = getBounds();
	bounds.width = size.width;
	bounds.height = size.height;
	setBounds(bounds);
}

void EToolkit::Control::setSize(int width, int height){
	Bounds2i bounds = getBounds();
	bounds.width = width;
	bounds.height = height;
	setBounds(bounds);
}

EToolkit::Bounds2i EToolkit::Control::getBounds() const{
	Bounds2i bounds;
	if(data != 0 && data->hwnd != 0){
		RECT rect = {0, 0, 0, 0};
		if(::GetWindowRect(data->hwnd, &rect) == 0){
			throw WindowsAPIException("invalid 'GetWindowRect'");
		}else{
			bounds = Bounds2i(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);
		}
	}
	return bounds;
}

void EToolkit::Control::setBounds(const Bounds2i& bounds){
	if(data != 0 && data->hwnd != 0){
		if(::MoveWindow(data->hwnd, bounds.x, bounds.y, bounds.width, bounds.height, TRUE) == 0){
			throw WindowsAPIException("invalid 'MoveWindow'");
		}
	}
}

void EToolkit::Control::setBounds(int x, int y, int width, int height){
	Bounds2i newBounds(x, y, width, height);
	setBounds(newBounds);
}
