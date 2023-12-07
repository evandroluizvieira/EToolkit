#include "../controls/ELabel.hpp"
#include "../controls/EControlPrivate.hpp"
#include "../exceptions/EMemoryAllocationException.hpp"
#include "../exceptions/EWindowsAPIException.hpp"
#include "../windows/EWindow.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

#include <new>
#include <windows.h>
#include <commctrl.h>

EToolkit::Label::Label(Window& parent, const String& text, bool addSunkenBorder) :
	Control(){
	if(parent.data == 0 || parent.data->hwnd == 0){
		throw(WindowsAPIException("invalid window parent"));
	}

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

	const char* labelText = 0;
	if(text.getLength() > 0){
		labelText = text.getData();
	}else{
		labelText = "Label";
	}

	DWORD style = WS_CHILD | SS_NOTIFY;
	if(addSunkenBorder == true){
		style |= SS_SUNKEN;
	}

	data->hwnd = ::CreateWindowEx(0, WC_STATIC, labelText, style, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, parent.data->hwnd, (HMENU)data->id, instance, 0);
	if(data->hwnd == 0){
		delete data;
		data = 0;

		throw(WindowsAPIException("cannot create push button"));
	}

	data->type = Control::Type::Type_Label;

	BaseWindowPrivate* baseWindowData = (BaseWindowPrivate*)parent.data;
	baseWindowData->addControl(this);
}

EToolkit::Label::~Label(){
	if(data != 0){
		::DestroyWindow(data->hwnd);
		data->hwnd = 0;

		delete data;
		data = 0;
	}
}

bool EToolkit::Label::isSetTextAlignment(TextAlignment alignment) const{
	if(data != 0){
		if(alignment == TextAlignment::Left){
			return data->hasStyle(SS_LEFT);
		}else if(alignment == TextAlignment::Center){
			return data->hasStyle(SS_CENTER);
		}else if(alignment == TextAlignment::Right){
			return data->hasStyle(SS_RIGHT);
		}
	}
	return false;
}

void EToolkit::Label::setTextAlignment(TextAlignment alignment){
	if(data != 0){
		data->removeStyle(SS_LEFT | SS_CENTER | SS_RIGHT, true);

		if(alignment == TextAlignment::Left){
			data->addStyle(SS_LEFT);
		}else if(alignment == TextAlignment::Center){
			data->addStyle(SS_CENTER);
		}else if(alignment == TextAlignment::Right){
			data->addStyle(SS_RIGHT);
		}
	}
}

bool EToolkit::Label::isSetTextEllipsis(TextEllipsis type) const{
	if(data != 0){
		if(type == TextEllipsis::End){
			return data->hasStyle(SS_ENDELLIPSIS);
		}else if(type == TextEllipsis::Word){
			return data->hasStyle(SS_WORDELLIPSIS);
		}else if(type == TextEllipsis::Path){
			return data->hasStyle(SS_PATHELLIPSIS);
		}
	}
	return false;
}

void EToolkit::Label::setTextEllipsis(TextEllipsis type){
	if(data != 0){
		if(type == TextEllipsis::End){
			data->addStyle(SS_ENDELLIPSIS);
		}else if(type == TextEllipsis::Word){
			data->addStyle(SS_WORDELLIPSIS);
		}else if(type == TextEllipsis::Path){
			data->addStyle(SS_PATHELLIPSIS);
		}
	}
}

void EToolkit::Label::unsetTextEllipsis(TextEllipsis type){
	if(data != 0){
		if(type == TextEllipsis::End){
			data->removeStyle(SS_ENDELLIPSIS);
		}else if(type == TextEllipsis::Word){
			data->removeStyle(SS_WORDELLIPSIS);
		}else if(type == TextEllipsis::Path){
			data->removeStyle(SS_PATHELLIPSIS);
		}
	}
}

void EToolkit::Label::onClick(bool doubleClick){

}
