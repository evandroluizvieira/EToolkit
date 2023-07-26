#include "../exceptions/EException.hpp"
#include "../exceptions/EExceptionPrivate.hpp"

EToolkit::ExceptionPrivate::ExceptionPrivate(const String& message) :
	message(message){

}

EToolkit::ExceptionPrivate::~ExceptionPrivate(){

}
