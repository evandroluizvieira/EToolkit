#include "../exceptions/EOutOfBoundsException.hpp"
#include "../string/EString.hpp"

EToolkit::OutOfBoundsException::OutOfBoundsException() :
	Exception("cannot access data"){

}

EToolkit::OutOfBoundsException::~OutOfBoundsException(){

}
