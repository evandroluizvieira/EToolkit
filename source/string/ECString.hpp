#ifndef ECSTRING_HPP
#define ECSTRING_HPP

#include <EToolkit>

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{
	/*
	 * @description: Class to use old style 'C string' functions.
	 */
	class ETOOLKIT_API CString{
		private:
			/*
			 * @description: Private default constructor what prevent object instantiation.
			 * @return: None.
			 */
			CString();

		public:
			/*
			 * @description: Same as C library function memchr.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/memchr/.
			 */
			static void* memchr(const void* data, unsigned char byte, unsigned int size);

			/*
			 * @description: Same as C library function memcmp.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/memcmp/.
			 */
			static int memcmp(const void* data1, const void* data2, unsigned int size);

			/*
			 * @description: Same as C library function memcpy.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/memcpy/.
			 */
			static void* memcpy(void* destination, const void* source, unsigned int size);

			/*
			 * @description: Same as C library function memmove.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/memmove/.
			 */
			static void* memmove(void* destination, const void* source, unsigned int size);

			/*
			 * @description: Same as C library function memset.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/memset/.
			 */
			static void* memset(void* data, unsigned char byte, unsigned int size);

			/*
			 * @description: Same as C library function strcat.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strcat/.
			 */
			static char* strcat(char* destination, const char* source);

			/*
			 * @description: Same as C library function strchr.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strchr/.
			 */
			static char* strchr(const char* string, char character);

			/*
			 * @description: Same as C library function strcmp.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strcmp/.
			 */
			static int strcmp(const char* string1, const char* string2);

			/*
			 * @description: Same as C library function strcpy.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strcpy/.
			 */
			static char* strcpy(char* destination, const char* source);

			/*
			 * @description: Same as C library function strcspn.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strcspn/.
			 */
			static unsigned int strcspn(const char* string1, const char* string2);

			/*
			 * @description: Same as C library function strlen.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strlen/.
			 */
			static unsigned int strlen(const char* string);

			/*
			 * @description: Same as C library function strncat.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strncat/.
			 */
			static char* strncat(char* string1, const char* string2, unsigned int lenght);

			/*
			 * @description: Same as C library function strncmp.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strncmp/.
			 */
			static int strncmp(const char* string1, const char* string2, unsigned int lenght);

			/*
			 * @description: Same as C library function strncpy.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strncpy/.
			 */
			static char* strncpy(char* destination, const char* source, unsigned int lenght);

			/*
			 * @description: Same as C library function strpbrk.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strpbrk/.
			 */
			static char* strpbrk(const char* string1, const char* string2);

			/*
			 * @description: Same as C library function strrchr.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strrchr/.
			 */
			static char* strrchr(const char* string, char character);

			/*
			 * @description: Same as C library function strspn.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strspn/.
			 */
			static unsigned int strspn(const char* string1, const char* string2);

			/*
			 * @description: Same as C library function strstr.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strstr/.
			 */
			static char* strstr(const char* string1, const char* string2);

			/*
			 * @description: Same as C library function strtok.
			 * @note: See in: http://www.cplusplus.com/reference/cstring/strtok/.
			 */
			static char* strtok(char* string, const char* delimiters);
	};
}

#endif /* ECSTRING_HPP */
