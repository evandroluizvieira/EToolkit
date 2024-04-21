#ifndef EWINDOWSARCHITECTURE_HPP
#define EWINDOWSARCHITECTURE_HPP

/*
 * @description: Evandro's Toolkit.
 */
namespace EToolkit{

	/*
	 * @description: Windows architecture setter class.
	 * @note: Can't use objects, only functions.
	 */
	class WindowsArchitecture{
		private:
			/*
			 * @description: Private default constructor that prevents object instantiation.
			 * @return: None.
			 */
			WindowsArchitecture();

		public:
			/*
			 * @description: List of vertical possible text positions.
			 */
			enum class WindowsVersion{
				//Windows 2000
			    Windows2000 = 500,

				//Windows XP
			    WindowsXP = 501,

				//Windows Server 2003
			    WindowsServer2003 = 502,

				//Windows Server 2008
			    WindowsServer2008 = 600,

				//Windows 7
			    Windows7 = 601,

				//Windows 8
			    Windows8 = 602,

				//Windows 8.1
			    Windows8_1 = 603,

				//Windows 10
			    Windows10 = 1000,

				//Windows 11
			    Windows11 = 1001
			};

			/*
			 * @description: Set the Windows version for conditional compilation.
			 * @return: None.
			 */
			static void SetVersion(WindowsVersion version);
	};
}

#endif /* EWINDOWSARCHITECTURE_HPP */
