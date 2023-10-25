#include "../synchronization/EMutex.hpp"

#include <new>
#include <windows.h>

class EToolkit::Mutex::PrivateMutex{
	public:
		PrivateMutex() :
			handle(nullptr){

		}

	public:
		HANDLE handle;
};

EToolkit::Mutex::Mutex() :
	BaseMutualExclusion(), d(new (std::nothrow) PrivateMutex()){
	if(d != nullptr){
		if(state == BaseMutualExclusion::Empty){
			d->handle = ::CreateMutex(0, false, 0);
			if(d->handle != 0){
				state = BaseMutualExclusion::Created;
			}
		}
	}
}

EToolkit::Mutex::~Mutex(){
	unlock();

	if(state == BaseMutualExclusion::Created){
		if(::CloseHandle(d->handle) != 0){
			state = BaseMutualExclusion::Empty;
		}
	}

	if(d != nullptr){
		delete d;
		d = nullptr;
	}
}

void EToolkit::Mutex::lock(){
	if(state == BaseMutualExclusion::Created){
		if(::WaitForSingleObject(d->handle, INFINITE) == WAIT_OBJECT_0){
			state = BaseMutualExclusion::Locked;
		}
	}
}

void EToolkit::Mutex::lock(uint32 milliseconds){
	if(state == BaseMutualExclusion::Created){
		if(::WaitForSingleObject(d->handle, milliseconds) == WAIT_TIMEOUT){
			state = BaseMutualExclusion::Locked;
		}
	}
}

void EToolkit::Mutex::unlock(){
	if(state == BaseMutualExclusion::Locked){
		if(::ReleaseMutex(d->handle) != 0){
			state = BaseMutualExclusion::Created;
		}
	}
}
