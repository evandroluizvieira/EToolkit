#ifndef ERUNNABLE_HPP
#define ERUNNABLE_HPP

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class represents an objects that runs a piece of code.
	 * @note: Used by Threads.
	 */
	class Runnable{
		friend class Thread;

		public:
			/*
			 * @description: Default constructor.
			 * @return: None.
			 */
			Runnable();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Runnable();

		protected:
			/*
			 * @description: Abstract function which is used mainly in threads.
			 * @return: None.
			 * @note: Must be implemented.
			 */
			virtual void run() = 0;
	};
}

#endif /* ERUNNABLE_HPP */
