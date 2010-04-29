#ifndef INCLUDED_neash_text_KeyCode
#define INCLUDED_neash_text_KeyCode

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,text,KeyCode)
namespace neash{
namespace text{


class KeyCode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef KeyCode_obj OBJ_;
		KeyCode_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< KeyCode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~KeyCode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"KeyCode",7); }

		static int KEY_0; /* REM */ 
		static int KEY_1; /* REM */ 
		static int KEY_2; /* REM */ 
		static int KEY_3; /* REM */ 
		static int KEY_4; /* REM */ 
		static int KEY_5; /* REM */ 
		static int KEY_6; /* REM */ 
		static int KEY_7; /* REM */ 
		static int KEY_8; /* REM */ 
		static int KEY_9; /* REM */ 
		static int A; /* REM */ 
		static int B; /* REM */ 
		static int C; /* REM */ 
		static int D; /* REM */ 
		static int E; /* REM */ 
		static int F; /* REM */ 
		static int G; /* REM */ 
		static int H; /* REM */ 
		static int I; /* REM */ 
		static int J; /* REM */ 
		static int K; /* REM */ 
		static int L; /* REM */ 
		static int M; /* REM */ 
		static int N; /* REM */ 
		static int O; /* REM */ 
		static int P; /* REM */ 
		static int Q; /* REM */ 
		static int R; /* REM */ 
		static int S; /* REM */ 
		static int T; /* REM */ 
		static int U; /* REM */ 
		static int V; /* REM */ 
		static int W; /* REM */ 
		static int X; /* REM */ 
		static int Y; /* REM */ 
		static int Z; /* REM */ 
		static int KP0; /* REM */ 
		static int KP1; /* REM */ 
		static int KP2; /* REM */ 
		static int KP3; /* REM */ 
		static int KP4; /* REM */ 
		static int KP5; /* REM */ 
		static int KP6; /* REM */ 
		static int KP7; /* REM */ 
		static int KP8; /* REM */ 
		static int KP9; /* REM */ 
		static int KP_MULTIPLY; /* REM */ 
		static int KP_ADD; /* REM */ 
		static int KP_ENTER; /* REM */ 
		static int KP_SUBTRACT; /* REM */ 
		static int KP_PERIOD; /* REM */ 
		static int KP_DIVIDE; /* REM */ 
		static int F1; /* REM */ 
		static int F2; /* REM */ 
		static int F3; /* REM */ 
		static int F4; /* REM */ 
		static int F5; /* REM */ 
		static int F6; /* REM */ 
		static int F7; /* REM */ 
		static int F8; /* REM */ 
		static int F9; /* REM */ 
		static int F11; /* REM */ 
		static int F12; /* REM */ 
		static int F13; /* REM */ 
		static int F14; /* REM */ 
		static int F15; /* REM */ 
		static int BACKSPACE; /* REM */ 
		static int TAB; /* REM */ 
		static int ENTER; /* REM */ 
		static int SHIFT; /* REM */ 
		static int CONTROL; /* REM */ 
		static int CAPSLOCK; /* REM */ 
		static int ESCAPE; /* REM */ 
		static int SPACE; /* REM */ 
		static int PAGEUP; /* REM */ 
		static int PAGEDOWN; /* REM */ 
		static int END; /* REM */ 
		static int HOME; /* REM */ 
		static int LEFT; /* REM */ 
		static int RIGHT; /* REM */ 
		static int UP; /* REM */ 
		static int DOWN; /* REM */ 
		static int INSERT; /* REM */ 
		static int DELETE; /* REM */ 
		static int NUMLOCK; /* REM */ 
		static int BREAK; /* REM */ 
		static int ConvertCode( int inNME);
		static Dynamic ConvertCode_dyn();

		static int ConvertASCII( int inNME,bool inShift,bool inControl);
		static Dynamic ConvertASCII_dyn();

		static int ConvertLocation( int inNME);
		static Dynamic ConvertLocation_dyn();

};

} // end namespace neash
} // end namespace text

#endif /* INCLUDED_neash_text_KeyCode */ 
