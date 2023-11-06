#include "../synchronization/ERunnable.hpp"
#include "../synchronization/EThread.hpp"
#include "../synchronization/EThreadPrivate.hpp"

#include <new>
#include <windows.h>

EToolkit::Thread::Thread() :
	data(new (std::nothrow) ThreadPrivate()){

}

EToolkit::Thread::Thread(Runnable* runnable) :
	data(new (std::nothrow) ThreadPrivate()){
	if(data != nullptr){
		data->runnable = runnable;
	}
}

EToolkit::Thread::~Thread(){
	terminate();

	if(data != nullptr){
		if(data->runnable != nullptr){
			delete data->runnable;
		}

		delete data;
		data = nullptr;
	}
}

unsigned int EToolkit::Thread::getID() const{
	return data != nullptr ? data->id : 0;
}

bool EToolkit::Thread::isRunning() const{
	return data != nullptr ? data->handle != nullptr : false;
}

EToolkit::Runnable* EToolkit::Thread::getRunnable() const{
	if(data != nullptr){
		return data->runnable;
	}else{
		return nullptr;
	}
}

void EToolkit::Thread::setRunnable(Runnable* runnable){
	if(isRunning() == true){
		return;
	}

	if(data != nullptr){
		if(data->runnable != nullptr){
			delete data->runnable;
		}

		data->runnable = runnable;
	}
}

void EToolkit::Thread::start(){
	if(data != nullptr){
		if(data->handle == nullptr){
			data->handle = ::CreateThread(0, 0, ThreadPrivate::ThreadMainProcedure, this, 0, reinterpret_cast<PDWORD>(&data->id));
		}
	}
}

void EToolkit::Thread::terminate(){
	if(isRunning() == true){
		::TerminateThread(data->handle, data->id);
		::CloseHandle(data->handle);
		data->handle = nullptr;
		data->id = 0;
	}
}

void EToolkit::Thread::suspend(){
	if(isRunning() == true){
		::SuspendThread(data->handle);
	}
}

void EToolkit::Thread::resume(){
	if(isRunning() == true){
		::ResumeThread(data->handle);
	}
}

void EToolkit::Thread::join(){
	if(isRunning() == true){
		::WaitForSingleObject(data->handle, INFINITE);
	}
}

void EToolkit::Thread::join(unsigned long int time){
	if(isRunning() == true){
		::WaitForSingleObject(data->handle, time);
	}
}

void EToolkit::Thread::sleep(unsigned long int time){
	if(isRunning() == true){
		::Sleep(time);
	}
}

void EToolkit::Thread::run(){
	if(data != nullptr && data->runnable != nullptr){
		data->runnable->run();
	}
}

