#include "../controls/EControl.hpp"
#include "../core/EApplicationPrivate.hpp"
#include "../exceptions/EWindowsAPIException.hpp"
#include "../windows/EBaseWindow.hpp"
#include "../windows/EBaseWindowPrivate.hpp"

EToolkit::BaseWindowPrivate::BaseWindowPrivate(Control* owner) :
	ControlPrivate(owner), atom(0), hdc(0), hglrc(0){

}

EToolkit::BaseWindowPrivate::~BaseWindowPrivate(){

}

LRESULT CALLBACK EToolkit::BaseWindowPrivate::WindowMainProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	BaseWindowPrivate* entryWindow = 0;

	if(message == WM_CREATE){
		CREATESTRUCT* createStruct = (CREATESTRUCT*)lParam;
		entryWindow = (BaseWindowPrivate*)createStruct->lpCreateParams;
		::SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)entryWindow);
		entryWindow->hwnd = hwnd;
	}else{
		entryWindow = (BaseWindowPrivate*)::GetWindowLongPtr(hwnd, GWLP_USERDATA);
	}

	if(entryWindow != 0){
		return entryWindow->procedure(hwnd, message, wParam, lParam);
	}else{
		return ::DefWindowProc(hwnd, message, wParam, lParam);
	}
}


LRESULT EToolkit::BaseWindowPrivate::procedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	if(this->hwnd == hwnd){
		processBasicEvents(message, wParam, lParam);
	}

	if(message == WM_DESTROY){
		std::vector<EToolkit::BaseWindow*>& TotalWindows = ApplicationPrivate::BaseWindows();
		for(size_t i = 0; i < TotalWindows.size(); i++){
			BaseWindow* baseWindow = TotalWindows.at(i);
			if(baseWindow != 0){
				ControlPrivate* controlPrivate = baseWindow->data;
				if(controlPrivate != 0){
					if(controlPrivate->id == id){
						TotalWindows.erase(TotalWindows.begin() + i);
					}
				}
			}
		}

		::PostQuitMessage(id);
	}

	return ::DefWindowProc(hwnd, message, wParam, lParam);
}

bool EToolkit::BaseWindowPrivate::createWindow(const String& identifier){
	const char* id = identifier.getData();

	if(identifier.getLength() == 0 || id == 0){
		throw(WindowsAPIException("identifier cannot be empty"));
	}

	HINSTANCE instance = ::GetModuleHandle(0);
	if(instance == 0){
		throw(WindowsAPIException("cannot get module handle"));
	}

	WNDCLASSEX extendedAsciiWindowClass;
	extendedAsciiWindowClass.cbSize = sizeof(WNDCLASSEX);
	extendedAsciiWindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	extendedAsciiWindowClass.lpfnWndProc = BaseWindowPrivate::WindowMainProcedure;
	extendedAsciiWindowClass.cbClsExtra = 0;
	extendedAsciiWindowClass.cbWndExtra = 0;
	extendedAsciiWindowClass.hInstance = instance;
	extendedAsciiWindowClass.hIcon = 0;
	extendedAsciiWindowClass.hCursor = 0;
	extendedAsciiWindowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	extendedAsciiWindowClass.lpszMenuName = 0;
	extendedAsciiWindowClass.lpszClassName = id;
	extendedAsciiWindowClass.hIconSm = 0;

	atom = ::RegisterClassEx(&extendedAsciiWindowClass);
	if(atom == 0){
		throw(WindowsAPIException("cannot register extended window class"));
	}

	hwnd = ::CreateWindowEx(0, id, "EToolkit - Window", WS_OVERLAPPEDWINDOW | WS_DISABLED, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, instance, this);

	if(hwnd == 0){
		if(::UnregisterClass((LPCSTR)(DWORD)(WORD)atom, instance) != 0){
			atom = 0;
		}

		throw(WindowsAPIException("cannot create extended window"));
	}

	return true;
}

void EToolkit::BaseWindowPrivate::destroyWindow(){
	if(::DestroyWindow(hwnd) != 0){
		hwnd = 0;
	}

	if(atom != 0){
		HINSTANCE instance = ::GetModuleHandle(0);
		if(instance != 0 && ::UnregisterClass((LPCSTR)(DWORD)(WORD)atom, instance) != 0){
			atom = 0;
		}
	}
}

bool EToolkit::BaseWindowPrivate::createGLWindow(const String& identifier){
	const char* id = identifier.getData();

	if(identifier.getLength() == 0 || id == 0){
		throw(WindowsAPIException("identifier cannot be empty"));
	}

	HINSTANCE instance = ::GetModuleHandle(0);
	if(instance == 0){
		throw(WindowsAPIException("cannot get module handle"));
	}

	WNDCLASSEX extendedAsciiWindowClass;
	extendedAsciiWindowClass.cbSize = sizeof(WNDCLASSEX);
	extendedAsciiWindowClass.style = CS_OWNDC;
	extendedAsciiWindowClass.lpfnWndProc = BaseWindowPrivate::WindowMainProcedure;
	extendedAsciiWindowClass.cbClsExtra = 0;
	extendedAsciiWindowClass.cbWndExtra = 0;
	extendedAsciiWindowClass.hInstance = instance;
	extendedAsciiWindowClass.hIcon = 0;
	extendedAsciiWindowClass.hCursor = 0;
	extendedAsciiWindowClass.hbrBackground = 0;
	extendedAsciiWindowClass.lpszMenuName = 0;
	extendedAsciiWindowClass.lpszClassName = id;
	extendedAsciiWindowClass.hIconSm = 0;

	atom = ::RegisterClassEx(&extendedAsciiWindowClass);
	if(atom == 0){
		throw(WindowsAPIException("cannot register extended window class"));
	}

	hwnd = ::CreateWindowEx(0, id, "EToolkit - GL Window", WS_OVERLAPPEDWINDOW | WS_DISABLED, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, instance, this);
	if(hwnd == 0){
		if(::UnregisterClass((LPCSTR)(DWORD)(WORD)atom, instance) != 0){
			atom = 0;
		}

		throw(WindowsAPIException("cannot create extended window"));
	}

	hdc = ::GetDC(hwnd);
	if(hdc == 0){
		if(::UnregisterClass((LPCSTR)(DWORD)(WORD)atom, instance) != 0){
			atom = 0;
		}

		if(::DestroyWindow(hwnd) != 0){
			hwnd = 0;
		}

		throw(WindowsAPIException("cannot get device context"));
	}

	PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
	pixelFormatDescriptor.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelFormatDescriptor.nVersion = 1;
	pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
	pixelFormatDescriptor.cColorBits = 0;
	pixelFormatDescriptor.cRedBits = 0;
	pixelFormatDescriptor.cRedShift = 0;
	pixelFormatDescriptor.cGreenBits = 0;
	pixelFormatDescriptor.cGreenShift = 0;
	pixelFormatDescriptor.cBlueBits = 0;
	pixelFormatDescriptor.cBlueShift = 0;
	pixelFormatDescriptor.cAlphaBits = 0;
	pixelFormatDescriptor.cAlphaShift = 0;
	pixelFormatDescriptor.cAccumBits = 0;
	pixelFormatDescriptor.cAccumRedBits = 0;
	pixelFormatDescriptor.cAccumGreenBits = 0;
	pixelFormatDescriptor.cAccumBlueBits = 0;
	pixelFormatDescriptor.cAccumAlphaBits = 0;
	pixelFormatDescriptor.cDepthBits = 0;
	pixelFormatDescriptor.cStencilBits = 0;
	pixelFormatDescriptor.cAuxBuffers = 0;
	pixelFormatDescriptor.iLayerType = PFD_MAIN_PLANE;
	pixelFormatDescriptor.bReserved = 0;
	pixelFormatDescriptor.dwLayerMask = 0;
	pixelFormatDescriptor.dwVisibleMask = 0;
	pixelFormatDescriptor.dwDamageMask = 0;

	int pixelFormat = ::ChoosePixelFormat(hdc, &pixelFormatDescriptor);
	if(pixelFormat == 0){
		if(::UnregisterClass((LPCSTR)(DWORD)(WORD)atom, instance) != 0){
			atom = 0;
		}

		if(::DestroyWindow(hwnd) != 0){
			hwnd = 0;
		}

		if(::ReleaseDC(hwnd, hdc) == 1){
			hdc = 0;
		}

		throw(WindowsAPIException("cannot choose pixel format"));
	}

	if(::SetPixelFormat(hdc, pixelFormat, &pixelFormatDescriptor) == FALSE){
		if(::UnregisterClass((LPCSTR)(DWORD)(WORD)atom, instance) != 0){
			atom = 0;
		}

		if(::DestroyWindow(hwnd) != 0){
			hwnd = 0;
		}

		if(::ReleaseDC(hwnd, hdc) == 1){
			hdc = 0;
		}

		throw(WindowsAPIException("cannot set pixel format"));
	}

	hglrc = ::wglCreateContext(hdc);
	if(hglrc == 0){
		if(::UnregisterClass((LPCSTR)(DWORD)(WORD)atom, instance) != 0){
			atom = 0;
		}

		if(::DestroyWindow(hwnd) != 0){
			hwnd = 0;
		}

		if(::ReleaseDC(hwnd, hdc) == 1){
			hdc = 0;
		}

		throw(WindowsAPIException("cannot create open graphics library context"));
	}

	if(::wglMakeCurrent(hdc, hglrc) == FALSE){
		if(::UnregisterClass((LPCSTR)(DWORD)(WORD)atom, instance) != 0){
			atom = 0;
		}

		if(::DestroyWindow(hwnd) != 0){
			hwnd = 0;
		}

		if(::ReleaseDC(hwnd, hdc) == 1){
			hdc = 0;
		}

		if(::wglDeleteContext(hglrc) == TRUE){
			hglrc = 0;
		}

		throw(WindowsAPIException("cannot make open graphics library the current context"));
	}

	return true;
}

void EToolkit::BaseWindowPrivate::destroyGLWindow(){
	if(hglrc != 0 && ::wglMakeCurrent(0, 0) == TRUE && ::wglDeleteContext(hglrc) == TRUE){
		hglrc = 0;
	}

	if(hwnd != 0 && hdc != 0 && ::ReleaseDC(hwnd, hdc) == 1){
		hdc = 0;
	}

	if(::DestroyWindow(hwnd) != 0){
		hwnd = 0;
	}

	if(atom != 0){
		HINSTANCE instance = ::GetModuleHandle(0);
		if(instance != 0 && ::UnregisterClass((LPCSTR)(DWORD)(WORD)atom, instance) != 0){
			atom = 0;
		}
	}
}

void EToolkit::BaseWindowPrivate::swapBufferGL(){
	if(hdc == 0){
		return;
	}

	::SwapBuffers(hdc);
}

void EToolkit::BaseWindowPrivate::activeGL(bool makeCurrent){
	if(makeCurrent == true){
		if(hdc != 0 && hglrc != 0){
			::wglMakeCurrent(hdc, hglrc);
		}
	}else{
		::wglMakeCurrent(0, 0);
	}
}
