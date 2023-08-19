#include "../string/ECString.hpp"
#include "../string/EString.hpp"
#include "../string/EStringPrivate.hpp"

#include <new>
#include <sstream>

EToolkit::String::String() :
	data(new (std::nothrow) StringPrivate()){

}

EToolkit::String::String(char character) :
	data(new (std::nothrow) StringPrivate()){
	if(data != 0){
		data->data = new (std::nothrow) char[2];
		if(data->data != 0){
			data->data[0] = character;
			data->data[1] = '\0';
		}
	}
}

EToolkit::String::String(const char* string) :
	data(new (std::nothrow) StringPrivate()){
	if(data != 0 && string != 0){
		unsigned int stringLength = CString::strlen(string) + 1;
		data->data = new (std::nothrow) char[stringLength];
		if(data->data != 0){
			CString::strcpy(data->data, string);
		}
	}
}

EToolkit::String::String(const String& string) :
	data(new (std::nothrow) StringPrivate()){
	if(data != 0 && string.data != 0){
		char* stringData = string.data->data;
		if(stringData != 0){
			unsigned int stringLength = string.getLength() + 1;
			data->data = new (std::nothrow) char[stringLength];
			if(data->data != 0){
				CString::strcpy(data->data, stringData);
			}
		}
	}
}

EToolkit::String::~String(){
	if(data != 0){
		clear();
		delete data;
		data = 0;
	}
}

EToolkit::String& EToolkit::String::operator=(char character){
	if(data != 0){
		clear();
		data->data = new (std::nothrow) char[2];
		if(data->data != 0){
			data->data[0] = character;
			data->data[1] = '\0';
		}
	}
	return *this;
}

EToolkit::String& EToolkit::String::operator=(const char* string){
	if(data != 0){
		clear();
		if(string != 0){
			unsigned int stringLength = CString::strlen(string) + 1;
			data->data = new (std::nothrow) char[stringLength];
			if(data->data != 0){
				CString::strcpy(data->data, string);
			}
		}
	}
	return *this;
}

EToolkit::String& EToolkit::String::operator=(const String& string){
	if(data != 0){
		clear();
		const char* stringData = string.data->data;
		if(stringData != 0){
			unsigned int stringLength = CString::strlen(stringData) + 1;
			data->data = new (std::nothrow) char[stringLength];
			if(data->data != 0){
				CString::strcpy(data->data, stringData);
			}
		}
	}
	return *this;
}

EToolkit::String EToolkit::String::operator+(char character) const{
	if(data != 0){
		unsigned int length = getLength();
		if(length > 0){
			char newData[length + 2];
			char* newDataPointer = &newData[0];
			CString::strcpy(newDataPointer, data->data);
			newData[length] = character;
			newData[length + 1] = '\0';
			return String(newDataPointer);
		}
	}
	return String(character);
}

EToolkit::String EToolkit::String::operator+(const char* string) const{
	if(data != 0){
		unsigned int currentLength = getLength();
		if(currentLength > 0){
			unsigned int stringLength = string != 0 ? CString::strlen(string) : 0;
			char newData[currentLength + stringLength + 1];
			char* newDataPointer = &newData[0];
			CString::strcpy(newDataPointer, data->data);
			if(stringLength > 0){
				CString::strcat(newDataPointer, string);
			}
			return String(newDataPointer);
		}
	}
	return String(string);
}

EToolkit::String EToolkit::String::operator+(const String& string) const{
	if(data != 0){
		unsigned int currentLength = getLength();
		if(currentLength > 0){
			unsigned int stringLength = string.getLength();
			char newData[currentLength + stringLength + 1];
			char* newDataPointer = &newData[0];
			CString::strcpy(newDataPointer, data->data);
			if(stringLength > 0){
				CString::strcat(newDataPointer, string.data->data);
			}
			return String(newDataPointer);
		}
	}
	return String(string);
}

EToolkit::String& EToolkit::String::operator+=(char character){
	return (*this = (*this + character));
}

EToolkit::String& EToolkit::String::operator+=(const char* string){
	return (*this = (*this + string));
}

EToolkit::String& EToolkit::String::operator+=(const String& string){
	return (*this = (*this + string));
}

char EToolkit::String::operator[](unsigned int index) const{
	return get(index);
}

void EToolkit::String::remove(unsigned int index){
	unsigned int length = getLength();
	if(length == 1){
		if(index == 0){
			clear();
		}
	}else if(length > 1){
		char* data = new (std::nothrow) char[length];
		length++;
		for(unsigned int i = 0, j = 0; i < length; i++){
			if(i == index){
				continue;
			}
			data[j] = this->data->data[i];
			j++;
		}
		clear();
		this->data->data = data;
	}
}

void EToolkit::String::removeFront(){
	remove(0);
}

void EToolkit::String::removeBack(){
	unsigned int length = getLength();
	if(length > 0){
		remove(length - 1);
	}
}

void EToolkit::String::clear(){
	if(data != 0 && data->data != 0){
		delete[] data->data;
		data->data = 0;
	}
}

char EToolkit::String::get(unsigned int index) const{
	if(data != 0){
		unsigned int length = getLength();
		if(length > 0 && index < length){
			return data->data[index];
		}
	}
	return 0;
}

char EToolkit::String::getFront() const{
	return get(0);
}

char EToolkit::String::getBack() const{
	unsigned int length = getLength();
	if(isEmpty() == true){
		return 0;
	}else{
		return get(length-1);
	}
}

const char* EToolkit::String::getData() const{
	if(data == 0 || data->data == 0){
		return "";
	}else{
		return data->data;
	}
}

unsigned int EToolkit::String::getLength() const{
	return data == 0 ? 0 : (data->data == 0 ? 0 : CString::strlen(data->data));
}

bool EToolkit::String::isEmpty() const{
	return getLength() == 0;
}

EToolkit::String EToolkit::String::valueOfCharacter(char value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfCharacter(signed char value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfCharacter(unsigned char value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfInteger(signed short int value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfInteger(unsigned short int value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfInteger(signed int value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfInteger(unsigned int value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfInteger(signed long int value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfInteger(unsigned long int value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfInteger(signed long long int value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfInteger(unsigned long long int value){
	std::ostringstream outputStringStream;
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfFloatingPoint(float value, unsigned int precision){
	std::ostringstream outputStringStream;
	if(precision > 0){
		outputStringStream.precision(precision);
	}
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfFloatingPoint(double value, unsigned int precision){
	std::ostringstream outputStringStream;
	if(precision > 0){
		outputStringStream.precision(precision);
	}
	outputStringStream << value;
	return outputStringStream.str().c_str();
}

EToolkit::String EToolkit::String::valueOfFloatingPoint(long double value, unsigned int precision){
	std::ostringstream outputStringStream;
	if(precision > 0){
		outputStringStream.precision(precision);
	}
	outputStringStream << value;
	return outputStringStream.str().c_str();
}
