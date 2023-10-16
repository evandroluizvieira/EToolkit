#ifndef EFILEPRIVATE_HPP
#define EFILEPRIVATE_HPP

#include "../core/EToolkitTypes.hpp"

namespace EToolkit{
	class FilePrivate{
		friend class File;

		public:
			FilePrivate();
			virtual ~FilePrivate();

		private:
			uint8* data;
			uint64 size;
	};
}

#endif /* EFILEPRIVATE_HPP */
