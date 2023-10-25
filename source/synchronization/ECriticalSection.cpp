#include "../synchronization/ECriticalSection.hpp"

#include <new>
#include <windows.h>

class EToolkit::CriticalSection::PrivateCriticalSection{
	public:
		PrivateCriticalSection(){

		}

	public:
		CRITICAL_SECTION criticalSection;
};

EToolkit::CriticalSection::CriticalSection() :
	BaseMutualExclusion(), d(new (std::nothrow) PrivateCriticalSection()){
	if(d != nullptr){
		if(state == BaseMutualExclusion::Empty){
			::InitializeCriticalSection(&d->criticalSection);
			state = BaseMutualExclusion::Created;
		}
	}
}

EToolkit::CriticalSection::~CriticalSection(){
	unlock();

	if(state == BaseMutualExclusion::Created){
		::DeleteCriticalSection(&d->criticalSection);
		state = BaseMutualExclusion::Empty;
	}

	if(d != nullptr){
		delete d;
		d = nullptr;
	}
}

void EToolkit::CriticalSection::lock(){
	if(d != nullptr){
		if(state == BaseMutualExclusion::Created){
			::EnterCriticalSection(&d->criticalSection);
			state = BaseMutualExclusion::Locked;
		}
	}
}

void EToolkit::CriticalSection::unlock(){
	if(d != nullptr){
		if(state == BaseMutualExclusion::Locked){
			::LeaveCriticalSection(&d->criticalSection);
			state = BaseMutualExclusion::Created;
		}
	}
}
