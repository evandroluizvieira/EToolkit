#ifndef EVIRTUALKEYPRIVATE_HPP
#define EVIRTUALKEYPRIVATE_HPP

#include <EEvents>

namespace EToolkit{
	class VirtualKeyPrivate{
		friend class ControlPrivate;

		private:
			VirtualKeyPrivate();

		private:
			static VirtualKey::VirtualKeyType getVirtualKeyFrom(unsigned int wParam);
	};
}

#endif /* EVIRTUALKEYPRIVATE_HPP */
