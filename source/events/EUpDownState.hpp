#ifndef EUPDOWNSTATE_HPP
#define EUPDOWNSTATE_HPP

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: List of state of the mouse and keyboard information state.
	 */
	class UpDownState{
		private:
			/*
			 * @description: Private default constructor what prevent object instantiation.
			 * @return: None.
			 */
		UpDownState();

		public:
			/*
			 * @description: List mouse and keyboard state.
			 */
			enum State{
				//This flag is used when the keyboard key or mouse button state is unknown.
				State_Unknonw,

				//This flag is used when the keyboard key or mouse button state is up.
				State_Up,

				//This flag is used when the keyboard key or mouse button state is down.
				State_Down
			};
	};
}

#endif /* EUPDOWNSTATE_HPP */
