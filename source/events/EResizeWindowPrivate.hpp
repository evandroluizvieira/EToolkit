#ifndef ERESIZEWINDOWPRIVATE_HPP
#define ERESIZEWINDOWPRIVATE_HPP

#include <EEventsData>

namespace EToolkit{
	class ResizeWindowPrivate{
		friend class ControlPrivate;

		private:
			ResizeWindowPrivate();

		private:
			static ResizeWindow::ResizeWindowType getResizeFlagFrom(unsigned int wParam);
	};
}

#endif /* ERESIZEWINDOWPRIVATE_HPP */
