#ifndef ETHREAD_HPP
#define ETHREAD_HPP

#include <EToolkit>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{
	class Runnable;
	class ThreadPrivate;

	/*
	 * @description: Class that enables concurrent or parallel execution of a piece of code.
	 * @note: The thread will run its own 'run()' function if you reimplement it, otherwise it will use the given 'runnable' object if it is valid.
	 */
	class ETOOLKIT_API Thread{
		friend class ThreadPrivate;

		public:
			/*
			 * @description: Default constructor.
			 * @return: None.
			 */
			Thread();

			/*
			 * @description: Constructor that initializes the object and set the 'runnable' object.
			 * @return: None.
			 */
			Thread(Runnable* runnable);

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Thread();

			/*
			 * @description: Function to get the thread identification.
			 * @return: Copy of the ID.
			 */
			unsigned int getID() const;

			/*
			 * @description: Function that check if the thread is already running.
			 * @return: True if yes or false otherwise.
			 */
			bool isRunning() const;

			/*
			 * @description: Function to get the attached runnable object.
			 * @return: Pointer to the object if exist or null pointer otherwise.
			 */
			Runnable* getRunnable() const;

			/*
			 * @description: Function that attach a 'runnable' object to be used when the thread 'start()'.
			 * @return: None.
			 * @note: Thread must not 'isRunning()'.
			 */
			void setRunnable(Runnable* runnable);

			/*
			 * @description: Function that creates and start the thread calling 'run()'.
			 * @return: None.
			 * @note: Can 'start()' only when the thread is empty/instantiated or destroyed/'terminate()'.
			 *
			 */
			void start();

			/*
			 * @description: Function that stops and destroys the thread.
			 * @return: None.
			 * @note: Will reset the status to 'start()' can be called again.  Available only on running threads.
			 */
			void terminate();

			/*
			 * @description: Function that causes the thread to stop execution.
			 * @return: None.
			 * @note Will wait until 'resume()' is called. Available only on running threads.
			 */
			void suspend();

			/*
			 * @description: Function that causes the thread to resume execution.
 	 	 	 * @return: None.
 	 	 	 * @note: Can use when 'suspend()' was previously called.
			 */
			void resume();

			/*
			 * @description: Function that causes the code to wait for the thread to finish.
			 * @return: None.
			 * @note: Available only on running threads.
			 */
			void join();

			/*
			 * @description: Function that causes the code wait the 'time' pass or the thread to finish.
			 * @return: None.
			 * @note: 'time' is in milliseconds. Available only on running threads.
			 */
			void join(unsigned long int time);

			/*
			 * @description: Function that suspends current execution for a specific period of time.
			 * @return: None.
			 * @note: 'time' is in milliseconds. Available only on running threads.
			 */
			void sleep(unsigned long int time);

		protected:
			/*
			 * @description: Default inheritable function that is called when the thread 'start()'.
			 * @return: None.
			 * @note: If the thread has a runnable object attached, its 'runnable->run()' will be called, but only if you do not override this thread's 'run()'.
			 */
			virtual void run();

		private:
			ThreadPrivate* data;
	};
}

#endif /* THREAD_HPP */
