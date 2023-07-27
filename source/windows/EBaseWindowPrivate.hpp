#ifndef WINDOWS_EBASEWINDOWPRIVATE_HPP
#define WINDOWS_EBASEWINDOWPRIVATE_HPP

#include <EString>

#include "../controls/EControlPrivate.hpp"

#include <windows.h>


namespace EToolkit{
	class Control;

	class BaseWindowPrivate : public ControlPrivate{
			friend class ApplicationPrivate;
			friend class Window;
			friend class GLWindow;

		public:
			BaseWindowPrivate(Control* owner);
			virtual ~BaseWindowPrivate();

		public:
			static LRESULT CALLBACK WindowMainProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

		private:
			virtual LRESULT procedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

		private:
			bool createWindow(const String& identifier);
			void destroyWindow();

			bool createGLWindow(const String& identifier);
			void destroyGLWindow();

			void swapBufferGL();
			void activeGL(bool makeCurrent);

		private:
			ATOM atom;
			HDC hdc;
			HGLRC hglrc;
	};
}

#endif /* WINDOWS_EBASEWINDOWPRIVATE_HPP */
