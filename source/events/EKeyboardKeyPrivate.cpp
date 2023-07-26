#include "../events/EKeyboardKeyPrivate.hpp"

#include <windows.h>

EToolkit::KeyboardKey::Key EToolkit::KeyboardKeyPrivate::getKeyFrom(unsigned int wParam){
	KeyboardKey::Key type = KeyboardKey::Key_Unknonw;

	if(0x30 == wParam){
		type = KeyboardKey::Key_0;
	}else if(0x31 == wParam){
		type = KeyboardKey::Key_1;
	}else if(0x32 == wParam){
		type = KeyboardKey::Key_2;
	}else if(0x33 == wParam){
		type = KeyboardKey::Key_3;
	}else if(0x34 == wParam){
		type = KeyboardKey::Key_4;
	}else if(0x35 == wParam){
		type = KeyboardKey::Key_5;
	}else if(0x36 == wParam){
		type = KeyboardKey::Key_6;
	}else if(0x37 == wParam){
		type = KeyboardKey::Key_7;
	}else if(0x38 == wParam){
		type = KeyboardKey::Key_8;
	}else if(0x39 == wParam){
		type = KeyboardKey::Key_9;
	}else if(0x41 == wParam){
		type = KeyboardKey::Key_A;
	}else if(0x42 == wParam){
		type = KeyboardKey::Key_B;
	}else if(0x43 == wParam){
		type = KeyboardKey::Key_C;
	}else if(0x44 == wParam){
		type = KeyboardKey::Key_D;
	}else if(0x45 == wParam){
		type = KeyboardKey::Key_E;
	}else if(0x46 == wParam){
		type = KeyboardKey::Key_F;
	}else if(0x47 == wParam){
		type = KeyboardKey::Key_G;
	}else if(0x48 == wParam){
		type = KeyboardKey::Key_H;
	}else if(0x49 == wParam){
		type = KeyboardKey::Key_I;
	}else if(0x4A == wParam){
		type = KeyboardKey::Key_J;
	}else if(0x4B == wParam){
		type = KeyboardKey::Key_K;
	}else if(0x4C == wParam){
		type = KeyboardKey::Key_L;
	}else if(0x4D == wParam){
		type = KeyboardKey::Key_M;
	}else if(0x4E == wParam){
		type = KeyboardKey::Key_N;
	}else if(0x4F == wParam){
		type = KeyboardKey::Key_O;
	}else if(0x50 == wParam){
		type = KeyboardKey::Key_P;
	}else if(0x51 == wParam){
		type = KeyboardKey::Key_Q;
	}else if(0x52 == wParam){
		type = KeyboardKey::Key_R;
	}else if(0x53 == wParam){
		type = KeyboardKey::Key_S;
	}else if(0x54 == wParam){
		type = KeyboardKey::Key_T;
	}else if(0x55 == wParam){
		type = KeyboardKey::Key_U;
	}else if(0x56 == wParam){
		type = KeyboardKey::Key_V;
	}else if(0x57 == wParam){
		type = KeyboardKey::Key_W;
	}else if(0x58 == wParam){
		type = KeyboardKey::Key_X;
	}else if(0x59 == wParam){
		type = KeyboardKey::Key_Y;
	}else if(0x5A == wParam){
		type = KeyboardKey::Key_Z;
	}else if(VK_F1 == wParam){
		type = KeyboardKey::Key_F1;
	}else if(VK_F2 == wParam){
		type = KeyboardKey::Key_F2;
	}else if(VK_F3 == wParam){
		type = KeyboardKey::Key_F3;
	}else if(VK_F4 == wParam){
		type = KeyboardKey::Key_F4;
	}else if(VK_F5 == wParam){
		type = KeyboardKey::Key_F5;
	}else if(VK_F6 == wParam){
		type = KeyboardKey::Key_F6;
	}else if(VK_F7 == wParam){
		type = KeyboardKey::Key_F7;
	}else if(VK_F8 == wParam){
		type = KeyboardKey::Key_F8;
	}else if(VK_F9 == wParam){
		type = KeyboardKey::Key_F9;
	}else if(VK_F10 == wParam){
		type = KeyboardKey::Key_F10;
	}else if(VK_F11 == wParam){
		type = KeyboardKey::Key_F11;
	}else if(VK_F12 == wParam){
		type = KeyboardKey::Key_F12;
	}else if(VK_F13 == wParam){
		type = KeyboardKey::Key_F13;
	}else if(VK_F14 == wParam){
		type = KeyboardKey::Key_F14;
	}else if(VK_F15 == wParam){
		type = KeyboardKey::Key_F15;
	}else if(VK_F16 == wParam){
		type = KeyboardKey::Key_F16;
	}else if(VK_F17 == wParam){
		type = KeyboardKey::Key_F17;
	}else if(VK_F18 == wParam){
		type = KeyboardKey::Key_F18;
	}else if(VK_F19 == wParam){
		type = KeyboardKey::Key_F19;
	}else if(VK_F20 == wParam){
		type = KeyboardKey::Key_F20;
	}else if(VK_F21 == wParam){
		type = KeyboardKey::Key_F21;
	}else if(VK_F22 == wParam){
		type = KeyboardKey::Key_F22;
	}else if(VK_F23 == wParam){
		type = KeyboardKey::Key_F23;
	}else if(VK_F24 == wParam){
		type = KeyboardKey::Key_F24;
	}else if(VK_NUMPAD0 == wParam){
		type = KeyboardKey::Key_NumPad0;
	}else if(VK_NUMPAD1 == wParam){
		type = KeyboardKey::Key_NumPad1;
	}else if(VK_NUMPAD2 == wParam){
		type = KeyboardKey::Key_NumPad2;
	}else if(VK_NUMPAD3 == wParam){
		type = KeyboardKey::Key_NumPad3;
	}else if(VK_NUMPAD4 == wParam){
		type = KeyboardKey::Key_NumPad4;
	}else if(VK_NUMPAD5 == wParam){
		type = KeyboardKey::Key_NumPad5;
	}else if(VK_NUMPAD6 == wParam){
		type = KeyboardKey::Key_NumPad6;
	}else if(VK_NUMPAD7 == wParam){
		type = KeyboardKey::Key_NumPad7;
	}else if(VK_NUMPAD8 == wParam){
		type = KeyboardKey::Key_NumPad8;
	}else if(VK_NUMPAD9 == wParam){
		type = KeyboardKey::Key_NumPad9;
	}else if(VK_LEFT == wParam){
		type = KeyboardKey::Key_ArrowLeft;
	}else if(VK_UP == wParam){
		type = KeyboardKey::Key_ArrowUp;
	}else if(VK_RIGHT == wParam){
		type = KeyboardKey::Key_ArrowRight;
	}else if(VK_DOWN == wParam){
		type = KeyboardKey::Key_ArrowDown;
	}else if(VK_LWIN == wParam){
		type = KeyboardKey::Key_WindowsLeft;
	}else if(VK_RWIN == wParam){
		type = KeyboardKey::Key_WindowsRight;
	}else if(VK_SHIFT == wParam){
		type = KeyboardKey::Key_Shift;
	}else if(VK_LSHIFT == wParam){
		type = KeyboardKey::Key_ShiftLeft;
	}else if(VK_RSHIFT == wParam){
		type = KeyboardKey::Key_ShiftRight;
	}else if(VK_CONTROL == wParam){
		type = KeyboardKey::Key_Control;
	}else if(VK_LCONTROL == wParam){
		type = KeyboardKey::Key_ControlLeft;
	}else if(VK_RCONTROL == wParam){
		type = KeyboardKey::Key_ControlRight;
	}else if(VK_MENU == wParam){
		type = KeyboardKey::Key_Alt;
	}else if(VK_LMENU == wParam){
		type = KeyboardKey::Key_AltLeft;
	}else if(VK_RMENU == wParam){
		type = KeyboardKey::Key_AltRight;
	}else if(VK_APPS == wParam){
		type = KeyboardKey::Key_Applications;
	}else if(VK_SLEEP == wParam){
		type = KeyboardKey::Key_Sleep;
	}else if(VK_MULTIPLY == wParam){
		type = KeyboardKey::Key_Multiply;
	}else if(VK_ADD == wParam){
		type = KeyboardKey::Key_Add;
	}else if(VK_SEPARATOR == wParam){
		type = KeyboardKey::Key_Separator;
	}else if(VK_SUBTRACT == wParam){
		type = KeyboardKey::Key_Subtract;
	}else if(VK_DECIMAL == wParam){
		type = KeyboardKey::Key_Decimal;
	}else if(VK_DIVIDE == wParam){
		type = KeyboardKey::Key_Divide;
	}else if(VK_NUMLOCK == wParam){
		type = KeyboardKey::Key_NumLock;
	}else if(VK_SCROLL == wParam){
		type = KeyboardKey::Key_ScrollLock;
	}else if(VK_CANCEL == wParam){
		type = KeyboardKey::Key_Cancel;
	}else if(VK_BACK == wParam){
		type = KeyboardKey::Key_BackSpace;
	}else if(VK_TAB == wParam){
		type = KeyboardKey::Key_Tab;
	}else if(VK_CLEAR == wParam){
		type = KeyboardKey::Key_Clear;
	}else if(VK_RETURN == wParam){
		type = KeyboardKey::Key_Return;
	}else if(VK_PAUSE == wParam){
		type = KeyboardKey::Key_Pause;
	}else if(VK_CAPITAL == wParam){
		type = KeyboardKey::Key_CapsLock;
	}else if(VK_ESCAPE == wParam){
		type = KeyboardKey::Key_Esc;
	}else if(VK_SPACE == wParam){
		type = KeyboardKey::Key_SpaceBar;
	}else if(VK_PRIOR == wParam){
		type = KeyboardKey::Key_PageUp;
	}else if(VK_NEXT == wParam){
		type = KeyboardKey::Key_PageDown;
	}else if(VK_END == wParam){
		type = KeyboardKey::Key_End;
	}else if(VK_HOME == wParam){
		type = KeyboardKey::Key_Home;
	}else if(VK_SELECT == wParam){
		type = KeyboardKey::Key_Select;
	}else if(VK_PRINT == wParam){
		type = KeyboardKey::Key_Print;
	}else if(VK_EXECUTE == wParam){
		type = KeyboardKey::Key_Execute;
	}else if(VK_SNAPSHOT == wParam){
		type = KeyboardKey::Key_PrintScreen;
	}else if(VK_INSERT == wParam){
		type = KeyboardKey::Key_Insert;
	}else if(VK_DELETE == wParam){
		type = KeyboardKey::Key_Delete;
	}else if(VK_HELP == wParam){
		type = KeyboardKey::Key_Help;
	}
	return type;
}

