#ifndef ESTRINGPRIVATE_HPP
#define ESTRINGPRIVATE_HPP

namespace EToolkit{
	class StringPrivate{
		friend class String;

		public:
			explicit StringPrivate();
			virtual ~StringPrivate();

		private:
			char* data;
	};
}

#endif /* ESTRINGPRIVATE_HPP */
