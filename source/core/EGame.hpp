#ifndef EGAME_HPP
#define EGAME_HPP

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Base interface game class, used to process and draw the game in a GLWindow.
	 */
	class Game{
		friend class Application;

		public:
			/*
			 * @description: Default constructor.
			 * @return: None.
			 */
			Game();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~Game();

		public:
			/*
			 * @description: Default inheritable function which is called once on beginning of the application 'execute' function.
			 * @return: None.
			 */
			virtual void onInitializing();

			/*
			 * @description: Default inheritable function which is called once on ending of the application 'execute' function.
			 * @return: None.
			 */
			virtual void onFinalizing();

			/*
			 * @description: Abstract function which is called every iteration of the application 'execute' function.
			 * @return: None.
			 * @note: Must be implemented.
			 */
			virtual void onUpdate(unsigned int deltaTime) = 0;
	};
}

#endif /* EGAME_HPP */
