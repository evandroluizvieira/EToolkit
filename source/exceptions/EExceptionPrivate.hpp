#ifndef EEXCEPTIONPRIVATE_HPP
#define EEXCEPTIONPRIVATE_HPP

#include "../string/EString.hpp"

namespace EToolkit{
	class ExceptionPrivate{
			friend class Exception;

		public:
			ExceptionPrivate(const String& message);
			virtual ~ExceptionPrivate();

		private:
			String message;
	};
}

#endif /* EEXCEPTIONPRIVATE_HPP */
