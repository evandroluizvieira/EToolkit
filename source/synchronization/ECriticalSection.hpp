#ifndef ECRITICALSECTION_HPP
#define ECRITICALSECTION_HPP

#include <EToolkit>

#include "EBaseMutualExclusion.hpp"

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that enforces limits on the access to a piece of code. Intra-process synchronization.
	 */
	class ETOOLKIT_API CriticalSection : public BaseMutualExclusion{
		public:
			/*
			 * @description: Default constructor.
			 * @return: None.
			 */
			CriticalSection();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~CriticalSection();

			/*
			 * @description: Blocks access from other threads and so the code can be synchronized.
			 * @return: None.
			 * @note: Access is blocked until 'unlock()' is called.
			 */
			void lock();

			/*
			 * @description: Allows access from other threads and signals that it is no longer controlling synchronization.
			 * @return: None.
			 */
			void unlock();

		private:
			class PrivateCriticalSection;
			PrivateCriticalSection* d;
	};
}

#endif /* ECRITICALSECTION_HPP */
