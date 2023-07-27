#ifndef EAPPLICATIONPRIVATE_HPP
#define EAPPLICATIONPRIVATE_HPP

#include "../windows/EBaseWindow.hpp"
#include "../windows/EGLWindow.hpp"

#include <vector>

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
			static std::vector<EToolkit::BaseWindow*>& BaseWindows();
			static std::vector<EToolkit::GLWindow*> GLWindows();
			static void GLWindowsInitialize();
			static void GLWindowsFinalize();
			static void GLWindowsPaint();

		private:
			bool running;
	};
}

#endif /* EAPPLICATIONPRIVATE_HPP */
