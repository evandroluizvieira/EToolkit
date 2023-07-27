#ifndef EWINDOWSAPIEXCEPTION_HPP
#define EWINDOWSAPIEXCEPTION_HPP

#include <EException>

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{
	/*
	 * @description: A custom exception class used to create a exception used in the windows api context.
	 **/
	class ETOOLKIT_API WindowsAPIException : public Exception{
		public:
			/*
			 * @description: Default constructor what create the exception with the given 'message'.
			 * @return: None.
			 */
			WindowsAPIException(const String& message);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~WindowsAPIException();
	};
}

#endif /* EWINDOWSAPIEXCEPTION_HPP */
