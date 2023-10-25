#ifndef EBASEMUTUALEXCLUSION_HPP
#define EBASEMUTUALEXCLUSION_HPP

#include <EToolkit>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Mutual exclusion synchronization base class.
	 * @note: Can't use, instead use 'Mutex' or 'CriticalSection' to synchronize code.
	 */
	class ETOOLKIT_API BaseMutualExclusion{
		friend class CriticalSection;
		friend class Mutex;

		public:
			/*
			 * @description: List of all possibles states of an mutual exclusion synchronization.
			 */
			enum State{
				Empty,
				Created,
				Locked,
				Unlocked = Created
			};

		private:
			/*
			 * @description: Private default constructor that prevents object instantiation.
			 * @return: None.
			 */
			BaseMutualExclusion();

		public:
			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~BaseMutualExclusion();

			/*
			 * @description: Get the current state.
			 * @return: Copy of current state.
			 */
			State getState() const;

		private:
			State state;
	};
}

#endif /* EBASEMUTUALEXCLUSION_HPP */
