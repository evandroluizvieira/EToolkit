#ifndef EMEMORYALLOCATIONEXCEPTION_HPP
#define EMEMORYALLOCATIONEXCEPTION_HPP

#include <EException>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{
	/*
	 * @description: A exception class used to throw a memory allocation failure.
	 */
	class ETOOLKIT_API MemoryAllocationException : public Exception{
		public:
			/*
			 * @description: Default constructor what create the exception with the "cannot allocate memory" message.
			 * @return: None.
			 */
			MemoryAllocationException();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~MemoryAllocationException();
	};
}

#endif /* EMEMORYALLOCATIONEXCEPTION_HPP */
