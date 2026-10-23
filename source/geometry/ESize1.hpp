#ifndef ESIZE1_HPP
#define ESIZE1_HPP

/*
 * @description: Evandro's C++ Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Class that represent 1 dimensional size.
	 * @note: 'Size1Type' must be numeric.
	 */
	template<class Size1Type>
	class Size1{
		public:
			/*
			 * @description: Default constructor that initialize object with the given 'width' value.
			 */
			Size1(Size1Type width = 0);

			/*
			 * @description: Default destructor.
			 */
			~Size1();

		public:
			Size1Type width;
	};

	typedef Size1<int> Size1i;
}

template<class Size1Type>
EToolkit::Size1<Size1Type>::Size1(Size1Type width) :
	width(width){

}

template<class Size1Type>
EToolkit::Size1<Size1Type>::~Size1(){

}

#endif /* ESIZE1_HPP */
