#include "../exceptions/EMemoryAllocationException.hpp"
#include "../string/EString.hpp"

EToolkit::MemoryAllocationException::MemoryAllocationException():
	Exception("cannot allocate memory"){

}

EToolkit::MemoryAllocationException::~MemoryAllocationException(){

}
