#ifndef ESTRING_HPP
#define ESTRING_HPP

#include <EToolkit>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{
	//forward declaration of private class
	class StringPrivate;

	/*
	 * @description: Class that represent a text.
	 */
	class ETOOLKIT_API String{
		public:
			/*
			 * @description: Default constructor that initialize object without characters.
			 * @return: None.
			 */
			String();

			/*
			 * @description: Constructor that initializes the object with a copy of the given 'character'.
			 * @return: None.
			 */
			String(char character);

			/*
			 * @description: Constructor that initializes the object with a copy of the given 'string'.
			 * @return: None.
			 */
			String(const char* string);

			/*
			 * @description: Constructor that initializes the object with a copy of the the given 'string'.
			 * @return: None.
			 */
			String(const String& string);

			/*
			 * @description: Default inheritable destructor that clear the object.
			 * @return: None.
			 */
			virtual ~String();

			/*
			 * @description: Operator that set the content of the object with the given 'character'.
			 * @return: Reference to itself.
			 */
			String& operator=(char character);

			/*
			 * @description: Operator that set the content of the object with the given 'string'.
			 * @return: Reference to itself.
			 */
			String& operator=(const char* string);

			/*
			 * @description: Operator that set the content of the object with the given 'string'.
			 * @return: Reference to itself.
			 */
			String& operator=(const String& string);

			/*
			 * @description: Operator what append the 'character' into a new text with current text.
			 * @return: Copy of appended text.
			 */
			String operator+(char character) const;

			/*
			 * @description: Operator what append the 'string' into a new text with current text.
			 * @return: Copy of appended text.
			 */
			String operator+(const char* string) const;

			/*
			 * @description: Operator what append the 'string' into a new text with current text.
			 * @return: Copy of appended text.
			 */
			String operator+(const String& string) const;

			/*
			 * @description: Operator what append the 'character' into the current text.
			 * @return: Reference to itself.
			 */
			String& operator+=(char character);

			/*
			 * @description: Operator what append the 'string' into the current text.
			 * @return: Reference to itself.
			 */
			String& operator+=(const char* string);

			/*
			 * @description: Operator what append the 'string' into the current text.
			 * @return: Reference to itself.
			 */
			String& operator+=(const String& string);

			/*
			 * @description: Operator to get the character of the given 'index'.
			 * @return: Copy of the character if 'index' is valid of 0 otherwise.
			 */
			char operator[](unsigned int index) const;

			/*
			 * @description: Function to remove the character in the 'index' position from string if it exist.
			 * @return: None.
			 */
			void remove(unsigned int index);

			/*
			 * @description: Function to remove first character from string if it exist.
			 * @return: None.
			 */
			void removeFront();

			/*
			 * @description: Function to remove last character from string if it exist.
			 * @return: None.
			 */
			void removeBack();

			/*
			 * @description: Function to remove all characters.
			 * @return: None.
			 */
			void clear();

			/*
			 * @description: Operator to get the character of the given 'index'.
			 * @return: Copy of the character, 'index' must be lower than lenght.
			 */
			char get(unsigned int index) const;

			/*
			 * @description: Function to get the first character from string.
			 * @return: Copy of first character if there is any or 0 otherwise.
			 */
			char getFront() const;

			/*
			 * @description: Function to get the last character from string.
			 * @return: Copy of last character if there is any or 0 otherwise.
			 */
			char getBack() const;

			/*
			 * @description: Function to get the pointer to the character sequence.
			 * @return: Constant pointer to the array if exist or null pointer otherwise.
			 */
			const char* getData() const;

			/*
			 * @description: Function to get the number of characters in text.
			 * @return: Copy of number of the characters.
			 */
			unsigned int getLenght() const;

			/*
			 * @description: Check if the number of characters on text is 0.
			 * @return: True if yes and false otherwise.
			 */
			bool isEmpty() const;

		public:
			/*
			 * @description: Get value of 'value' in a new string.
			 * @return: A string with 'true' if true or 'false' otherwise.
			 */
			static String valueOfBoolean(bool value);

			/*
			 * @description: Get value of 'value' character in a new string.
			 * @return: A string with the character.
			 */
			static String valueOfCharacter(char value);

			/*
			 * @description: Get value of 'value' character in a new string.
			 * @return: A string with the character.
			 */
			static String valueOfCharacter(signed char value);

			/*
			 * @description: Get value of 'value' character in a new string.
			 * @return A string with the character.
			 */
			static String valueOfCharacter(unsigned char value);

			/*
			 * @description: Get value of 'value' integer in a new string.
			 * @return: A string with the integer.
			 */
			static String valueOfInteger(signed short int value);

			/*
			 * @description: Get value of 'value' integer in a new string.
			 * @return: A string with the integer.
			 */
			static String valueOfInteger(unsigned short int value);

			/*
			 * @description: Get value of 'value' integer in a new string.
			 * @return: A string with the integer.
			 */
			static String valueOfInteger(signed int value);

			/*
			 * @description: Get value of 'value' integer in a new string.
			 * @return: A string with the integer.
			 */
			static String valueOfInteger(unsigned int value);

			/*
			 * @description: Get value of 'value' integer in a new string.
			 * @return: A string with the integer.
			 */
			static String valueOfInteger(signed long int value);

			/*
			 * @description: Get value of 'value' integer in a new string.
			 * @return: A string with the integer.
			 */
			static String valueOfInteger(unsigned long int value);

			/*
			 * @description: Get value of 'value' integer in a new string.
			 * @return: A string with the integer.
			 */
			static String valueOfInteger(signed long long int value);

			/*
			 * @description: Get value of 'value' integer in a new string.
			 * @return: A string with the integer.
			 */
			static String valueOfInteger(unsigned long long int value);

			/*
			 * @description: Get value of 'value' floating point number in a new string.
			 * @return: A string with the floating point number.
			 */
			static String valueOfFloatingPoint(float value, unsigned int precision = 0);

			/*
			 * @description: Get value of 'value' floating point number in a new string.
			 * @return: A string with the floating point number.
			 */
			static String valueOfFloatingPoint(double value, unsigned int precision = 0);

			/*
			 * @description: Get value of 'value' floating point number in a new string.
			 * @return: A string with the floating point number.
			 */
			static String valueOfFloatingPoint(long double value, unsigned int precision = 0);

		public:
			StringPrivate* data;
	};
}

#endif /* ESTRING_HPP */
