#ifndef EAPPLICATION_HPP
#define EAPPLICATION_HPP

#include <EToolkit>
#include <EGame>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{
	//forward declaration of private class
	class ApplicationPrivate;

	/*
	 * @description: Class used to create a main loop to process events.
	 */
	class ETOOLKIT_API Application{
		public:
			/*
			 * @description: Default constructor.
			 * @return: None.
			 */
			Application();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Application();

			/*
			 * @description: Start the application main loop to process events.
			 * @return: Exit code value.
			 */
			int execute();

			/*
			 * @description: Start the application main loop to process events of the 'game' to draw in the 'glWindow'.
			 * @return: Exit code.
			 * @note: When 'glWindow' is closing, execution will finalize.
			 */
			int execute(Game& game);

			/*
			 * @description: Signalizes to finish the main loop if running.
			 * @return: None.
			 */
			void interrupt();

		private:
			ApplicationPrivate* data;
	};
}

#endif /* EAPPLICATION_HPP */
