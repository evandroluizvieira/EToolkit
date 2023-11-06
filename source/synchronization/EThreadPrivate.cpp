#include "../synchronization/EThread.hpp"
#include "../synchronization/EThreadPrivate.hpp"

EToolkit::ThreadPrivate::ThreadPrivate() :
	runnable(nullptr), handle(nullptr),  id(0){

}

EToolkit::ThreadPrivate::~ThreadPrivate(){

}

DWORD WINAPI EToolkit::ThreadPrivate::ThreadMainProcedure(LPVOID param){
	Thread* thread = reinterpret_cast<Thread*>(param);
	if(thread != nullptr){
		thread->run();
		return thread->data == nullptr ? 0 : thread->data->id;
	}
	return 0;
}
