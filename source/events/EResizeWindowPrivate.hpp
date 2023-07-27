#ifndef ERESIZEWINDOWPRIVATE_HPP
#define ERESIZEWINDOWPRIVATE_HPP

#include <EEvents>

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
