#ifndef EFILE_HPP
#define EFILE_HPP

#include <EToolkit>
#include <EString>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{
	//forward declaration of private class
	class FilePrivate;

	/*
	 * @description: File class that holds binary data.
	 */
	class ETOOLKIT_API File{
		public:
			/*
			 * @description: Default constructor.
			 * @return: None.
			 */
			File();

			/*
			 * @description: Default virtual destructor that call 'clear()'.
			 * @return: None.
			 */
			virtual ~File();

			/*
			 * @description: Operator to get the byte of the given 'index'.
			 * @return: Reference of the byte in the 'index' position if 'index' is valid and '\0' otherwise.
			 */
			uint8& operator[](unsigned int index);

			/*
			 * @description: Function to get the pointer to the data memory.
			 * @return: Pointer to the data if exist or null pointer otherwise.
			 */
			uint8* getData() const;

			/*
			 * @description: Function to get bytes size of the file.
			 * @return: Copy of the size.
			 */
			uint64 getSize() const;

			/*
			 * @description: Check if data is empty.
			 * @return: true if it is empty and false otherwise.
			 */
			bool isEmpty() const;

			/*
			 * @description: Function that releases all data.
			 * @return: None.
			 */
			void clear();

			/*
			 * @description: Load data from the 'file' and store the data.
			 * @return: true if success and false otherwise.
			 * @note: File must be 'isEmpty()'.
			 */
			bool load(const String& file);

			/*
			 * @description: Write all data into the 'file'.
			 * @return: true if success and false otherwise.
			 */
			bool save(const String& file);

			/*
			 * @description: Append 'size' bytes of the given 'in' data starting from the given 'index'.
			 * @return: true if success and false otherwise.
			 */
			bool write(void* in, uint64 size, uint64 index);

			 /*
			 * @description: Read 'size' bytes starting from the given 'index' into 'out' data.
			 * @return: true if success and false otherwise.
			 */
			bool read(void* out, uint64 size, uint64 index) const;

			/*
			 * @description: Release 'size' bytes of data starting from the given 'index'.
			 * @return: None.
			 */
			void erase(uint64 size, uint64 index);


		private:
			FilePrivate* data;
	};
}

#endif /* EFILE_HPP */
