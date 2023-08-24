#ifndef EAPPLICATIONPRIVATE_HPP
#define EAPPLICATIONPRIVATE_HPP

#include "../containers/EDynamicArray.hpp"
#include "../windows/EBaseWindow.hpp"
#include "../windows/EGLWindow.hpp"

namespace EToolkit{
	class ApplicationPrivate{
		friend class Application;
		friend class BaseWindowPrivate;
		friend class Window;
		friend class GLWindow;

		public:
			ApplicationPrivate();
			virtual ~ApplicationPrivate();

		private:
			static DynamicArray<BaseWindow*>& BaseWindows();
			static DynamicArray<EToolkit::GLWindow*> GLWindows();
			static void GLWindowsInitialize();
			static void GLWindowsFinalize();
			static void GLWindowsPaint();

		private:
			bool running;
	};
}

#endif /* EAPPLICATIONPRIVATE_HPP */
