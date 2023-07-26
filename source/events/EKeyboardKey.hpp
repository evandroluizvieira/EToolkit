#ifndef EKEYBOARDKEY_HPP
#define EKEYBOARDKEY_HPP

/*
 * @description: Evandro's toolkit.
 */
namespace EToolkit{

	/*
	 * @description: List of keyboard keys information.
	 */
	class KeyboardKey{
		private:
			/*
			 * @description: Private default constructor what prevent object instantiation.
			 * @return: None.
			 */
			KeyboardKey();

		public:
			/*
			 * @description: List of keyboard keys.
			 */
			enum Key{
				//This flag is used when the keyboard key is unknown.
				Key_Unknonw,

				//This flag is used by number 0 key on the keyboard.
				Key_0,

				//This flag is used by number 1 key on the keyboard.
				Key_1,

				//This flag is used by number 2 key on the keyboard.
				Key_2,

				//This flag is used by number 3 key on the keyboard.
				Key_3,

				//This flag is used by number 4 key on the keyboard.
				Key_4,

				//This flag is used by number 5 key on the keyboard.
				Key_5,

				//This flag is used by number 6 key on the keyboard.
				Key_6,

				//This flag is used by number 7 key on the keyboard.
				Key_7,

				//This flag is used by number 8 key on the keyboard.
				Key_8,

				//This flag is used by number 9 key on the keyboard.
				Key_9,

				//This flag is used by letter A key on the keyboard.
				Key_A,

				//This flag is used by letter B key on the keyboard.
				Key_B,

				//This flag is used by letter C key on the keyboard.
				Key_C,

				//This flag is used by letter D key on the keyboard.
				Key_D,

				//This flag is used by letter E key on the keyboard.
				Key_E,

				//This flag is used by letter F key on the keyboard.
				Key_F,

				//This flag is used by letter G key on the keyboard.
				Key_G,

				//This flag is used by letter H key on the keyboard.
				Key_H,

				//This flag is used by letter I key on the keyboard.
				Key_I,

				//This flag is used by letter J key on the keyboard.
				Key_J,

				//This flag is used by letter K key on the keyboard.
				Key_K,

				//This flag is used by letter L key on the keyboard.
				Key_L,

				//This flag is used by letter M key on the keyboard.
				Key_M,

				//This flag is used by letter N key on the keyboard.
				Key_N,

				//This flag is used by letter O key on the keyboard.
				Key_O,

				//This flag is used by letter P key on the keyboard.
				Key_P,

				//This flag is used by letter Q key on the keyboard.
				Key_Q,

				//This flag is used by letter R key on the keyboard.
				Key_R,

				//This flag is used by letter S key on the keyboard.
				Key_S,

				//This flag is used by letter T key on the keyboard.
				Key_T,

				//This flag is used by letter U key on the keyboard.
				Key_U,

				//This flag is used by letter V key on the keyboard.
				Key_V,

				//This flag is used by letter W key on the keyboard.
				Key_W,

				//This flag is used by letter X key on the keyboard.
				Key_X,

				//This flag is used by letter Y key on the keyboard.
				Key_Y,

				//This flag is used by letter Z key on the keyboard.
				Key_Z,

				//This flag is used by function 1/F1 key on the keyboard.
				Key_F1,

				//This flag is used by function 2/F2 key on the keyboard.
				Key_F2,

				//This flag is used by function 3/F3 key on the keyboard.
				Key_F3,

				//This flag is used by function 4/F4 key on the keyboard.
				Key_F4,

				//This flag is used by function 5/F5 key on the keyboard.
				Key_F5,

				//This flag is used by function 6/F6 key on the keyboard.
				Key_F6,

				//This flag is used by function 7/F7 key on the keyboard.
				Key_F7,

				//This flag is used by function 8/F8 key on the keyboard.
				Key_F8,

				//This flag is used by function 9/F9 key on the keyboard.
				Key_F9,

				//This flag is used by function 10/F10 key on the keyboard.
				Key_F10,

				//This flag is used by function 11/F11 key on the keyboard.
				Key_F11,

				//This flag is used by function 12/F12 key on the keyboard.
				Key_F12,

				//This flag is used by function 13/F13 key on the keyboard.
				Key_F13,

				//This flag is used by function 14/F14 key on the keyboard.
				Key_F14,

				//This flag is used by function 15/F15 key on the keyboard.
				Key_F15,

				//This flag is used by function 16/F16 key on the keyboard.
				Key_F16,

				//This flag is used by function 17/F17 key on the keyboard.
				Key_F17,

				//This flag is used by function 18/F18 key on the keyboard.
				Key_F18,

				//This flag is used by function 19/F19 key on the keyboard.
				Key_F19,

				//This flag is used by function 20/F20 key on the keyboard.
				Key_F20,

				//This flag is used by function 21/F21 key on the keyboard.
				Key_F21,

				//This flag is used by function 22/F22 key on the keyboard.
				Key_F22,

				//This flag is used by function 23/F23 key on the keyboard.
				Key_F23,

				//This flag is used by function 24/F24 key on the keyboard.
				Key_F24,

				//This flag is used by 0 key on the numeric keyboard.
				Key_NumPad0,

				//This flag is used by 1 key on the numeric keyboard.
				Key_NumPad1,

				//This flag is used by 2 key on the numeric keyboard.
				Key_NumPad2,

				//This flag is used by 3 key on the numeric keyboard.
				Key_NumPad3,

				//This flag is used by 4 key on the numeric keyboard.
				Key_NumPad4,

				//This flag is used by 5 key on the numeric keyboard.
				Key_NumPad5,

				//This flag is used by 6 key on the numeric keyboard.
				Key_NumPad6,

				//This flag is used by 7 key on the numeric keyboard.
				Key_NumPad7,

				//This flag is used by 8 key on the numeric keyboard.
				Key_NumPad8,

				//This flag is used by 9 key on the numeric keyboard.
				Key_NumPad9,

				//This flag is used by volume mute key on the keyboard.
				Key_VolumeMute,

				//This flag is used by volume down key on the keyboard.
				Key_VolumeDown,

				//This flag is used by volume up key on the keyboard.
				Key_VolumeUp,

				//This flag is used by left arrow key on the keyboard.
				Key_ArrowLeft,

				//This flag is used by up arrow key on the keyboard.
				Key_ArrowUp,

				//This flag is used by right arrow key on the keyboard.
				Key_ArrowRight,

				//This flag is used by down arrow key on the keyboard.
				Key_ArrowDown,

				//This flag is used by left windows key on the keyboard.
				Key_WindowsLeft,

				//This flag is used by right windows key on the keyboard.
				Key_WindowsRight,

				//This flag is used by shift key on the keyboard.
				Key_Shift,

				//This flag is used by left shift key on the keyboard.
				Key_ShiftLeft,

				//This flag is used by right shift key on the keyboard.
				Key_ShiftRight,

				//This flag is used by control key on the keyboard.
				Key_Control,

				//This flag is used by left control key on the keyboard.
				Key_ControlLeft,

				//This flag is used by right control key on the keyboard.
				Key_ControlRight,

				//This flag is used by alternate key on the keyboard.
				Key_Alt,

				//This flag is used by left alternate key on the keyboard.
				Key_AltLeft,

				//This flag is used by right alternate key on the keyboard.
				Key_AltRight,

				//This flag is used by application key on the keyboard.
				Key_Applications,

				//This flag is used by sleep key on the keyboard.
				Key_Sleep,

				//This flag is used by multiply key on the keyboard.
				Key_Multiply,

				//This flag is used by add key on the keyboard.
				Key_Add,

				//This flag is used by separator key on the keyboard.
				Key_Separator,

				//This flag is used by subtract key on the keyboard.
				Key_Subtract,

				//This flag is used by decimal key on the keyboard.
				Key_Decimal,

				//This flag is used by divide key on the keyboard.
				Key_Divide,

				//This flag is used by numeric lock key on the keyboard.
				Key_NumLock,

				//This flag is used by scroll lock key on the keyboard.
				Key_ScrollLock,

				//This flag is used by cancel key on the keyboard.
				Key_Cancel,

				//This flag is used by back space key on the keyboard.
				Key_BackSpace,

				//This flag is used by tab key on the keyboard.
				Key_Tab,

				//This flag is used by clear key on the keyboard.
				Key_Clear,

				//This flag is used by enter/return key on the keyboard.
				Key_Return,

				//This flag is used by pause key on the keyboard.
				Key_Pause,

				//This flag is used by caps lock key on the keyboard.
				Key_CapsLock,

				//This flag is used by escape key on the keyboard.
				Key_Esc,

				//This flag is used by space bar on the keyboard.
				Key_SpaceBar,

				//This flag is used by page up key on the keyboard.
				Key_PageUp,

				//This flag is used by page down key on the keyboard.
				Key_PageDown,

				//This flag is used by end key on the keyboard.
				Key_End,

				//This flag is used by home key on the keyboard.
				Key_Home,

				//This flag is used by select key on the keyboard.
				Key_Select,

				//This flag is used by print key on the keyboard.
				Key_Print,

				//This flag is used by execute key on the keyboard.
				Key_Execute,

				//This flag is used by print screen key on the keyboard.
				Key_PrintScreen,

				//This flag is used by insert key on the keyboard.
				Key_Insert,

				//This flag is used by delete key on the keyboard.
				Key_Delete,

				//This flag is used by help key on the keyboard.
				Key_Help
			};
	};
}

#endif /* EKEYBOARDKEY_HPP */
