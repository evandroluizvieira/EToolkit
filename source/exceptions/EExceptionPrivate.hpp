#ifndef EEXCEPTIONPRIVATE_HPP
#define EEXCEPTIONPRIVATE_HPP

#include <EString>

namespace EToolkit{
	class ExceptionPrivate{
			friend class Exception;

		public:
			explicit ExceptionPrivate(const String& message);
			virtual ~ExceptionPrivate();

		private:
			String message;
	};
}

#endif /* EEXCEPTIONPRIVATE_HPP */
