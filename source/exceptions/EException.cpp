#include "../exceptions/EException.hpp"
#include "../exceptions/EExceptionPrivate.hpp"

EToolkit::Exception::Exception(const String& message) :
	data(0){

}

EToolkit::Exception::~Exception(){
	if(data != 0){
		delete data;
		data = 0;
	}
}

EToolkit::String EToolkit::Exception::what() const{
	String message;
	if(data != 0){
		message = data->message;
	}
	return message;
}
