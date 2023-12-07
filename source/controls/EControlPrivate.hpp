#ifndef ECONTROLPRIVATE_HPP
#define ECONTROLPRIVATE_HPP

#include <windows.h>

namespace EToolkit{
	class Control;
	class BaseWindow;
	class Button;
	class Label;

	class ControlPrivate{
		friend class BaseWindow;
		friend class BaseWindowPrivate;
		friend class GLWindow;
		friend class Window;
		friend class Menu;
		friend class MenuPrivate;
		friend class Control;
		friend class Button;
		friend class Label;

		public:
			ControlPrivate(Control* owner);
			virtual ~ControlPrivate();

		private:
			void processAllEvents(UINT message, WPARAM wParam, LPARAM lParam);
			void processBaseWindowEvents(BaseWindow* baseWindow, UINT message, WPARAM wParam, LPARAM lParam);
			void processButtonEvents(Button* button, UINT message, WPARAM wParam, LPARAM lParam);
			void processLabelEvents(Label* button, UINT message, WPARAM wParam, LPARAM lParam);

		private:
			bool hasStyle(DWORD checkStyle);
			void addStyle(DWORD style, bool refresh = true);
			void removeStyle(DWORD style, bool refresh = true);

		private:
			Control* owner;
			HWND hwnd;
			unsigned int id;
			int type;
	};
}

#endif /* ECONTROLPRIVATE_HPP */
