#ifndef ETHREADPRIVATE_HPP
#define ETHREADPRIVATE_HPP

#include "../synchronization/ERunnable.hpp"

#include <windows.h>

namespace EToolkit{
	class Thread;

	class ThreadPrivate{
		friend class Thread;

		public:
			ThreadPrivate();
			virtual ~ThreadPrivate();

		public:
		    static DWORD WINAPI ThreadMainProcedure(LPVOID param);

		private:
		    Runnable* runnable;
			HANDLE handle;
			unsigned int id;
	};
}

#endif /* ETHREADPRIVATE_HPP */
