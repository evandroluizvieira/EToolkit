#include "../core/EFile.hpp"
#include "../core/EFilePrivate.hpp"
#include "../exceptions/EOutOfBoundsException.hpp"
#include "../string/ECString.hpp"

#include <new>
#include <fstream>

EToolkit::File::File() :
	data(new (std::nothrow) FilePrivate()){

}

EToolkit::File::~File(){
	clear();

	if(data != nullptr){
		delete data;
		data = nullptr;
	}
}

uint8& EToolkit::File::operator[](unsigned int index){
	if(index < getSize()){
		return data->data[index];
	}else{
		throw OutOfBoundsException();
	}
}

uint8* EToolkit::File::getData() const{
	if(isEmpty() == false){
		return data->data;
	}else{
		return nullptr;
	}
}

uint64 EToolkit::File::getSize() const{
	return data != nullptr ? data->size : 0;
}

bool EToolkit::File::isEmpty() const{
	if(data == nullptr || data->data == nullptr || data->size == 0){
		return true;
	}else{
		return false;
	}
}

void EToolkit::File::clear(){
	if(data->data != nullptr){
		delete data->data;
		data->data = nullptr;
	}
	data->size = 0;
}

bool EToolkit::File::load(const String& filename){
	if(data == nullptr){
		return false;
	}

	if(isEmpty() == false){
		return false;
	}

	std::ifstream file(filename.getData(), std::ios::in | std::ios::binary | std::ios::ate);
	if(file.is_open() == false){
		return false;
	}

	char* buffer = nullptr;
	uint64 size = 0;
	size = file.tellg();
	file.seekg(0, std::ios::beg);
	buffer = new (std::nothrow) char[size];

	if(buffer != nullptr){
		file.read(buffer, size);
	}

	file.close();

	if(size > 0){
		data->data = reinterpret_cast<uint8*>(buffer);
		data->size = size;
	}

	return true;
}

bool EToolkit::File::save(const String& filename){
	if(data == nullptr){
		return false;
	}

	if(data->data == nullptr || data->size == 0){
		std::ofstream file(filename.getData());
		if(!file){
			return false;
		}
		file.close();
	}else{
		std::ofstream file(filename.getData(), std::ios::out | std::ios::binary);
		if(!file){
			return false;
		}
		file.write(reinterpret_cast<const char*>(data->data), data->size);
		file.close();
	}

	return true;
}

bool EToolkit::File::write(void* in, uint64 size, uint64 index){
	if (in == nullptr || size == 0 || index > data->size) {
		return false;
	}

	uint64 newSize = data->size + size;
	uint8* newData = new (std::nothrow) uint8[newSize];

	// Copy data before the write index
	if(index > 0){
		CString::memcpy(newData, data->data, index);
	}

	// Copy 'in' data at the specified index
	CString::memcpy(newData + index, in, size);

	// Copy data after the write index
	if(index < data->size){
		CString::memcpy(newData + index + size, data->data + index, data->size - index);
	}

	delete[] data->data;
	data->data = newData;
	data->size = newSize;

	return true;
}

bool EToolkit::File::read(void* out, uint64 size, uint64 index) const{
	if(isEmpty() == true || out == nullptr || size == 0 || index + (size - 1) >= data->size){
		 return false;
	}

	CString::memcpy(out, data->data + index, size);

	return true;
}

void EToolkit::File::erase(uint64 size, uint64 index){
	if(isEmpty() == true){
		 return;
	}

	if(index >= data->size || size == 0 || size > data->size){
		return;
	}

	if(index + size > data->size){
		return;
	}

	uint64 newSize = data->size - size;
	if(newSize == 0 && index == 0){
		clear();
		return;
	}

	uint8* newData = new (std::nothrow) uint8[newSize];

	// Copy data before the erase range
	if(index > 0){
		CString::memcpy(newData, data->data, index);
	}

	// Copy data after the erase range
	if(index + size < data->size){
		CString::memcpy(newData + index, data->data + index + size, data->size - index - size);
	}

	delete[] data->data;
	data->data = newData;
	data->size = newSize;
}
