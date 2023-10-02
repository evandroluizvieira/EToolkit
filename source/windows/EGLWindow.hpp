#ifndef EGLWINDOW_HPP
#define EGLWINDOW_HPP

#include <EToolkit>
#include <EWindow>

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Main window with a OpenGL context.
	 * @note: GLWindow are double buffered.
	 */
	class ETOOLKIT_API GLWindow : public BaseWindow{
			friend class ApplicationPrivate;

		public:
			/*
			 * @description: Default window constructor.
			 * @return: None.
			 */
			GLWindow();

			/*
			 * @description: Default inheritable destructor.
			 * @return: None.
			 */
			virtual ~GLWindow();

		protected:
			/*
			 * @description: Default inheritable function which is called once on beginning of the application 'execute' function.
			 * @return: None.
			 */
			virtual void glInitialize();

			/*
			 * @description: Default inheritable function which is called once on ending of the application 'execute' function.
			 * @return: None.
			 */
			virtual void glFinalize();

			/*
			 * @description: Default inheritable function used to paint using OpenGL which is called every iteration of the application 'execute' function.
			 * @return: None.
			 */
			virtual void glPaint();
	};
}

#endif /* EGLWINDOW_HPP */
