#include "../core/EApplication.hpp"
#include "../core/EApplicationPrivate.hpp"
#include "../exceptions/EMemoryAllocationException.hpp"

#include <new>
#include <windows.h>

EToolkit::Application::Application(){
	data = new (std::nothrow) ApplicationPrivate();
	if(data == 0){
		throw MemoryAllocationException();
	}
}

EToolkit::Application::~Application(){
	if(data != 0){
		delete data;
		data = 0;
	}
}

int EToolkit::Application::execute(){
	int exitCode = -1;

	if(data != 0){
		MSG msg = {0, 0, 0, 0, 0, {0, 0}};

		bool& running = data->running;
		running = true;

		ApplicationPrivate::GLWindowsInitialize();

		while(running == true && ApplicationPrivate::BaseWindows().size() > 0){
			if(::GetMessage(&msg, 0, 0, 0) == -1){
				running = false;
			}else{
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}

			ApplicationPrivate::GLWindowsPaint();
		}

		ApplicationPrivate::GLWindowsFinalize();

		exitCode = msg.wParam;
	}

	return exitCode;
}

int EToolkit::Application::execute(Game& game){
	int exitCode = -1;

	if(data == 0){
		return exitCode;
	}

	bool& running = data->running;
	running = true;

	MSG msg = {0, 0, 0, 0, 0, {0, 0}};

	DWORD previousTickCount;
	DWORD currentTickCount = ::GetTickCount();

	ApplicationPrivate::GLWindowsInitialize();

	game.onInitializing();

	while(running == true && ApplicationPrivate::BaseWindows().size() > 0){
		previousTickCount = currentTickCount;
		currentTickCount = ::GetTickCount();

		while(::PeekMessage(&msg, 0, 0, 0, PM_REMOVE) != 0){
			::DispatchMessage(&msg);
		}

		ApplicationPrivate::GLWindowsPaint();
		game.onUpdate(currentTickCount - previousTickCount);
	}

	ApplicationPrivate::GLWindowsFinalize();

	game.onFinalizing();

	exitCode = msg.wParam;

	return exitCode;
}

void EToolkit::Application::interrupt(){
	if(data != 0){
		data->running = false;
	}
}
