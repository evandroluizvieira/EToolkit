#ifndef WINDOWS_EBASEWINDOWPRIVATE_HPP
#define WINDOWS_EBASEWINDOWPRIVATE_HPP

#include "../containers/EDynamicArray.hpp"
#include "../controls/EControl.hpp"
#include "../controls/EControlPrivate.hpp"
#include "../string/EString.hpp"

#include <windows.h>

namespace EToolkit{
	class Control;

	class BaseWindowPrivate : public ControlPrivate{
			friend class ApplicationPrivate;
			friend class BaseWindow;
			friend class Window;
			friend class GLWindow;
			friend class Button;
			friend class Label;

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

			void addControl(Control* control);
			void removeControl(Control* control);
			void clearControls();

		private:
			ATOM atom;
			HDC hdc;
			HGLRC hglrc;

			MenuBar* menuBar;
			DynamicArray<Control*> controls;

	};
}

#endif /* WINDOWS_EBASEWINDOWPRIVATE_HPP */
