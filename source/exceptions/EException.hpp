#ifndef EEXCEPTION_HPP
#define EEXCEPTION_HPP

#include <EToolkit>
#include <EString>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{
	class ExceptionPrivate;

	/*
	 * @description: A custom exception class used to create a exception used by try/catchs blocks.
	 */
	class ETOOLKIT_API Exception{
		public:
			/*
			 * @description: Default constructor what create the exception with the given 'message'.
			 * @return: None.
			 */
			Exception(const String& message);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Exception();

			/*
			 * @description: Show exception message.
			 * @return: Copy of the exception message.
			 */
			String what() const;

		private:
			ExceptionPrivate* data;
	};
}

#endif /* EEXCEPTION_HPP */
