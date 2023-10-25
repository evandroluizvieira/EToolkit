#ifndef MUTEX_HPP
#define MUTEX_HPP

#include <EToolkit>

#include "EBaseMutualExclusion.hpp"

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that enforces limits on the access to a piece of code. Inter-process synchronization.
	 */
	class ETOOLKIT_API Mutex : public BaseMutualExclusion{
		public:
			/*
			 * @description: Default constructor.
			 * @return: None.
			 */
			Mutex();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Mutex();

			/*
			 * @description: Blocks access from other threads and so the code can be synchronized.
			 * @return: None.
			 * @note: Access is blocked until 'unlock()' is called.
			 */
			void lock();

			/*
			 * @description: Blocks access from other threads and so the code can be synchronized.
			 * @return: None.
			 * @note: Access is blocked until 'unlock()' is called or specified time period has passed. 'milliseconds' must be greater than zero.
			 */
			void lock(uint32 milliseconds);

			/*
			 * @description: Allows access from other threads and signals that it is no longer controlling synchronization.
			 * @return: None.
			 */
			void unlock();

		private:
			class PrivateMutex;
			PrivateMutex* d;
	};
}

#endif /* MUTEX_HPP */
