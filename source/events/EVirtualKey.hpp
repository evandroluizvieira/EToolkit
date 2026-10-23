#ifndef EEVENTVIRTUALKEY_HPP
#define EEVENTVIRTUALKEY_HPP

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: List of virtual keys information.
	 */
	class VirtualKey{
		private:
			/*
			 * @description: Private default constructor that prevents object instantiation.
			 * @return: None.
			 */
			VirtualKey();

		public:
			/*
			 * @description: List of virtual buttons.
			 */
			enum VirtualKeyType{
				//This key is used when the virtual key is unknown.
				VirtualKey_Unknonw,

				//This key is used when the control key is down.
				VirtualKey_Control,

				//This key is used when the left mouse button is down.
				VirtualKey_LeftMouseButton,

				//This key is used when the middle mouse button is down.
				VirtualKey_MiddleMouseButton,

				//This key is used when the right mouse button is down.
				VirtualKey_RightMouseButton,

				//This key is used when the shift key is down.
				VirtualKey_Shift
			};
	};
}

#endif /* EEVENTVIRTUALKEY_HPP */
