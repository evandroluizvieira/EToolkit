#include "../exceptions/EWindowsAPIException.hpp"
#include "../string/EString.hpp"

EToolkit::WindowsAPIException::WindowsAPIException(const String& message) :
	Exception(message){

}

EToolkit::WindowsAPIException::~WindowsAPIException(){

}
