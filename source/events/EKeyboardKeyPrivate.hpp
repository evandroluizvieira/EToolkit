#ifndef EKEYBOARDKEYPRIVATE_HPP
#define EKEYBOARDKEYPRIVATE_HPP

#include <EEvents>

namespace EToolkit{
	class KeyboardKeyPrivate{
		friend class ControlPrivate;

		private:
			KeyboardKeyPrivate();

		private:
			static KeyboardKey::Key getKeyFrom(unsigned int wParam);
	};
}

#endif /* EKEYBOARDKEYPRIVATE_HPP */
