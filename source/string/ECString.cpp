#include "../string/ECString.hpp"

void* EToolkit::CString::memchr(const void* data, unsigned char byte, unsigned int size){
	const unsigned char* dataAuxiliary = (const unsigned char*)data;

	while(size-- != 0){
		if(*dataAuxiliary == byte){
			return (void*)dataAuxiliary;
		}

		dataAuxiliary++;
	}

	return 0;
}

int EToolkit::CString::memcmp(const void* data1, const void* data2, unsigned int size){
	const unsigned char* lastByteData1 = (const unsigned char*)data1;
	const unsigned char* lastByteData2 = (const unsigned char*)data2;

	while(size-- != 0){
		if(*lastByteData1 != *lastByteData2){
			return (*lastByteData1 < *lastByteData2) ? -1 : +1;
		}

		lastByteData1++;
		lastByteData2++;
	}

	return 0;
}

void* EToolkit::CString::memcpy(void* destination, const void* source, unsigned int size){
	char* destinationAuxiliary = (char*)destination;
	const char* sourceAuxiliary = (const char*)source;

	while(size-- != 0){
		*destinationAuxiliary++ = *sourceAuxiliary++;
	}

	return destination;
}

void* EToolkit::CString::memmove(void* destination, const void* source, unsigned int size){
	char* destinationAuxiliary = (char*)destination;
	const char* sourceAuxiliary = (const char*)source;

	if(sourceAuxiliary < destinationAuxiliary && destinationAuxiliary < sourceAuxiliary + size){
		sourceAuxiliary += size;
		destinationAuxiliary += size;

		while(size-- != 0){
			*--destinationAuxiliary = *--sourceAuxiliary;
		}
	}else{
		while(size-- != 0){
			*destinationAuxiliary++ = *sourceAuxiliary++;
		}
	}

	return destination;
}

void* EToolkit::CString::memset(void* data, unsigned char byte, unsigned int size){
	unsigned char* auxiliaryData = (unsigned char*)data;

	while(size-- != 0){
		*auxiliaryData++ = byte;
	}

	return data;
}

char* EToolkit::CString::strcat(char* destination, const char* source){
	char* destinationEnds = destination;

	while(*destinationEnds != '\0'){
		destinationEnds++;
	}

	CString::strcpy(destinationEnds, source);

	return destination;
}

char* EToolkit::CString::strchr(const char* string, char character){
	while(*string != '\0' && *string != character){
		string++;
	}

	return ((*string == character) ? (char*)string : 0);
}

int EToolkit::CString::strcmp(const char* string1, const char* string2){
	while(*string1 != '\0' && *string1 == *string2){
		string1++;
		string2++;
	}

	unsigned char lastCharacterString1 = (*(unsigned char *)string1);
	unsigned char lastCharacterString2 = (*(unsigned char *)string2);

	return ((lastCharacterString1 < lastCharacterString2) ? -1 : (lastCharacterString1 > lastCharacterString2));
}

char* EToolkit::CString::strcpy(char* destination, const char* source){
	char* destinationAuxiliary = destination;
	const char* sourceAuxiliary = source;

	while((*destinationAuxiliary++ = *sourceAuxiliary++) != '\0'){

	}

	return destination;
}

unsigned int EToolkit::CString::strcspn(const char* string1, const char* string2){
	const char* auxiliary = string1;

	for(; *auxiliary != '\0'; auxiliary++){
		if(CString::strchr(string2, *auxiliary) != 0){
			return (auxiliary - string1);
		}
	}

	return auxiliary - string1;
}

unsigned int EToolkit::CString::strlen(const char* string){
	const char* auxiliary = string;

	while(*auxiliary != '\0'){
		auxiliary++;
	}

	return (unsigned int)(auxiliary - string);
}

char* EToolkit::CString::strncat(char* string1, const char* string2, unsigned int lenght){
	char* auxiliary = string1;

	while(*auxiliary != '\0'){
		auxiliary++;
	}

	while(lenght != 0 && (*auxiliary = *string2++) != '\0'){
		lenght--;
		auxiliary++;
	}

	if(*auxiliary != '\0'){
		*auxiliary = '\0';
	}

	return string1;
}

int EToolkit::CString::strncmp(const char* string1, const char* string2, unsigned int lenght){
	if(lenght == 0){
		return 0;
	}

	while(lenght-- > 0 && *string1 == *string2){
		if(lenght == 0 || *string1 == '\0'){
			return 0;
		}
		string1++;
		string2++;
	}

	unsigned char lastCharacterString1 = (*(unsigned char *)string1);
	unsigned char lastCharacterString2 = (*(unsigned char *)string2);

	return ((lastCharacterString1 < lastCharacterString2) ? -1 : (lastCharacterString1 > lastCharacterString2));
}

char* EToolkit::CString::strncpy(char* destination, const char* source, unsigned int lenght){
	char* destinationAuxiliary = destination;
	const char* sourceAuxiliary = source;

	while(lenght > 0){
		lenght--;
		if((*destinationAuxiliary++ = *sourceAuxiliary++) == '\0'){

			CString::memset(destinationAuxiliary, '\0', lenght);
			break;
		}
	}

	return destination;
}

char* EToolkit::CString::strpbrk(const char* string1, const char* string2){
	const char* auxiliary = string1;

	for(; *auxiliary != '\0'; auxiliary++){
		if(CString::strchr(string2, *auxiliary) != 0){
			return (char *)auxiliary;
		}
	}

	return 0;
}

char* EToolkit::CString::strrchr(const char* string, char character){
	if(character == '\0'){
		return CString::strchr(string, character);
	}

	const char* lastCharacter = 0;
	while((string = CString::strchr(string, character)) != 0){
		lastCharacter = string;
		string++;
	}

	return (char*)lastCharacter;
}

unsigned int EToolkit::CString::strspn(const char* string1, const char* string2){
	const char* auxiliary = string1;

	for(; *auxiliary != '\0'; auxiliary++){
		if(CString::strchr(string2, *auxiliary) == 0){
			return (auxiliary - string1);
		}
	}

	return auxiliary - string1;
}

char* EToolkit::CString::strstr(const char* string1, const char* string2){
	if(*string2 == '\0'){
		return (char*)string1;
	}

	unsigned int string2Lenght = CString::strlen(string2);
	for(; (string1 = CString::strchr(string1, *string2)) != 0; string1++){
		if(CString::strncmp(string1, string2, string2Lenght) == 0){
			return (char*)string1;
		}
	}

	return 0;
}

char* EToolkit::CString::strtok(char* string, const char* delimiters){
	char* token = 0;

	if(string != 0){
		token = string;
	}else if(token == 0){
		return 0;
	}

	string = token + CString::strspn(token, delimiters);
	token = string + CString::strcspn(string, delimiters);

	if(token == string){
		return token = 0;
	}

	token = *token ? *token = 0, token + 1 : 0;

	return string;
}
