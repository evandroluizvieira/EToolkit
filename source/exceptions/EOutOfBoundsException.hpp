#ifndef EOUTOFBOUNDSEXCEPTION_HPP
#define EOUTOFBOUNDSEXCEPTION_HPP

#include <EException>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{
	/*
	 * @description: A exception class used to throw a out of bounds access violation.
	 */
	class ETOOLKIT_API OutOfBoundsException : public Exception{
		public:
			/*
			 * @description: Default constructor what create the exception with the "cannot access data" message.
			 * @return: None.
			 */
			OutOfBoundsException();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~OutOfBoundsException();
	};
}

#endif /* EOUTOFBOUNDSEXCEPTION_HPP */
