#ifndef ECONTROLPRIVATE_HPP
#define ECONTROLPRIVATE_HPP

#include <windows.h>

namespace EToolkit{
	class Control;

	class ControlPrivate{
		friend class BaseWindowPrivate;
		friend class Control;
		friend class GLWindow;
		friend class Window;

		public:
			ControlPrivate(Control* owner);
			virtual ~ControlPrivate();

		private:
			void processBasicEvents(UINT message, WPARAM wParam, LPARAM lParam);
			void processBaseWindowEvents(UINT message, WPARAM wParam, LPARAM lParam);

		private:
			Control* owner;
			HWND hwnd;
			int id;
			int type;
	};
}

#endif /* ECONTROLPRIVATE_HPP */
