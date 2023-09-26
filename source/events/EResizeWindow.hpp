#ifndef ERESIZEWINDOW_HPP
#define ERESIZEWINDOW_HPP
/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: List of resize window information.
	 */
	class ResizeWindow{
		private:
			/*
			 * @description: Private default constructor that prevents object instantiation.
			 * @return: None.
			 */
			ResizeWindow();

		public:
			/*
			 * @description: List resize window types.
			 */
			enum ResizeWindowType{
				//This flag is used when the window resize is unknown.
				ResizeWindow_Unknonw,

				//This flag is used when the window has been maximized.
				ResizeWindow_Maximized,

				//This flag is used when a message is sent to all pop-up windows when some other window is maximized.
				ResizeWindow_MaximizedHide,

				//This flag is used when a message is sent to all pop-up windows when some other window has been restored to its former size.
				ResizeWindow_MaximizedShow,

				//This flag is used when the window has been minimized.
				ResizeWindow_Minimized,

				//This flag is used when the window has been resized, but neither the Resize_Minimized nor Resize_Maximized value applies.
				ResizeWindow_Restored
			};
	};
}

#endif /* ERESIZEWINDOW_HPP */
