#include "../string/ECString.hpp"
#include "../string/EString.hpp"
#include "../string/EStringPrivate.hpp"

#include <sstream>

EToolkit::String::String() :
	data(new StringPrivate()){

}

EToolkit::String::String(char character) :
	data(new StringPrivate()){
	if(data != 0){
		data->data = new char[1];
		data->data[0] = character;
	}
}

EToolkit::String::String(const char* string) :
	data(new StringPrivate()){
	if(data != 0 && string != 0){
		unsigned int stringLenght = CString::strlen(string) + 1;
		data->data = new char[stringLenght];
		CString::strcpy(data->data, string);
	}
}

EToolkit::String::String(const String& string) :
	data(new StringPrivate()){
	if(data != 0){
		char* stringData = string.data->data;
		if(stringData != 0){
			unsigned int stringLenght = string.getLenght() + 1;
			data->data = new char[stringLenght];
			CString::strcpy(data->data, stringData);
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
		data->data = new char[2];
		data->data[0] = character;
		data->data[1] = '\0';
	}
	return *this;
}

EToolkit::String& EToolkit::String::operator=(const char* string){
	if(data != 0){
		clear();
		if(string != 0){
			unsigned int stringLenght = CString::strlen(string) + 1;
			data->data = new char[stringLenght];
			CString::strcpy(data->data, string);
		}
	}
	return *this;
}

EToolkit::String& EToolkit::String::operator=(const String& string){
	if(data != 0){
		clear();
		const char* stringData = string.data->data;
		if(stringData != 0){
			unsigned int stringLenght = CString::strlen(stringData) + 1;
			data->data = new char[stringLenght];
			CString::strcpy(data->data, stringData);
		}
	}
	return *this;
}

EToolkit::String EToolkit::String::operator+(char character) const{
	if(data != 0){
		unsigned int lenght = getLenght();
		if(lenght > 0){
			char newData[lenght + 2];
			char* newDataPointer = &newData[0];
			CString::strcpy(newDataPointer, data->data);
			newData[lenght] = character;
			newData[lenght + 1] = '\0';
			return String(newDataPointer);
		}
	}
	return String(character);
}

EToolkit::String EToolkit::String::operator+(const char* string) const{
	if(data != 0){
		unsigned int currentLenght = getLenght();
		if(currentLenght > 0){
			unsigned int stringLenght = string != 0 ? CString::strlen(string) : 0;
			char newData[currentLenght + stringLenght + 1];
			char* newDataPointer = &newData[0];
			CString::strcpy(newDataPointer, data->data);
			if(stringLenght > 0){
				CString::strcat(newDataPointer, string);
			}
			return String(newDataPointer);
		}
	}
	return String(string);
}

EToolkit::String EToolkit::String::operator+(const String& string) const{
	if(data != 0){
		unsigned int currentLenght = getLenght();
		if(currentLenght > 0){
			unsigned int stringLenght = string.getLenght();
			char newData[currentLenght + stringLenght + 1];
			char* newDataPointer = &newData[0];
			CString::strcpy(newDataPointer, data->data);
			if(stringLenght > 0){
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
	unsigned int lenght = getLenght();
	if(index < lenght){
		if(lenght == 1){
			clear();
		}else{
			char* data = new char[lenght-1];
			for(unsigned int i = 0; i < lenght; i++){
				if(i == index){
					continue;
				}
				data[i] = this->data->data[i];
			}
			clear();
			this->data->data = data;
		}
	}
}

void EToolkit::String::removeFront(){
	remove(0);
}

void EToolkit::String::removeBack(){
	remove(getLenght());
}

void EToolkit::String::clear(){
	if(data != 0 && data->data != 0){
		delete[] data->data;
		data->data = 0;
	}
}

char EToolkit::String::get(unsigned int index) const{
	if(index < getLenght()){
		return data->data[index];
	}else{
		return 0;
	}
}

char EToolkit::String::getFront() const{
	return get(0);
}

char EToolkit::String::getBack() const{
	return get(getLenght()-1);
}

const char* EToolkit::String::getData() const{
	if(data != 0){
		return data->data;
	}else{
		return 0;
	}
}

unsigned int EToolkit::String::getLenght() const{
	return data == 0 ? 0 : (data->data == 0 ? 0 : CString::strlen(data->data));
}

bool EToolkit::String::isEmpty() const{
	return getLenght() == 0;
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
