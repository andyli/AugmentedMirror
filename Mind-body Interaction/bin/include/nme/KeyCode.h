#ifndef INCLUDED_nme_KeyCode
#define INCLUDED_nme_KeyCode

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,KeyCode)
namespace nme{


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

		static int UNKNOWN; /* REM */ 
		static int FIRST; /* REM */ 
		static int BACKSPACE; /* REM */ 
		static int TAB; /* REM */ 
		static int CLEAR; /* REM */ 
		static int RETURN; /* REM */ 
		static int PAUSE; /* REM */ 
		static int ESCAPE; /* REM */ 
		static int SPACE; /* REM */ 
		static int EXCLAIM; /* REM */ 
		static int QUOTEDBL; /* REM */ 
		static int HASH; /* REM */ 
		static int DOLLAR; /* REM */ 
		static int AMPERSAND; /* REM */ 
		static int QUOTE; /* REM */ 
		static int LEFTPAREN; /* REM */ 
		static int RIGHTPAREN; /* REM */ 
		static int ASTERISK; /* REM */ 
		static int PLUS; /* REM */ 
		static int COMMA; /* REM */ 
		static int MINUS; /* REM */ 
		static int PERIOD; /* REM */ 
		static int SLASH; /* REM */ 
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
		static int COLON; /* REM */ 
		static int SEMICOLON; /* REM */ 
		static int LESS; /* REM */ 
		static int EQUALS; /* REM */ 
		static int GREATER; /* REM */ 
		static int QUESTION; /* REM */ 
		static int AT; /* REM */ 
		static int LEFTBRACKET; /* REM */ 
		static int BACKSLASH; /* REM */ 
		static int RIGHTBRACKET; /* REM */ 
		static int CARET; /* REM */ 
		static int UNDERSCORE; /* REM */ 
		static int BACKQUOTE; /* REM */ 
		static int a; /* REM */ 
		static int b; /* REM */ 
		static int c; /* REM */ 
		static int d; /* REM */ 
		static int e; /* REM */ 
		static int f; /* REM */ 
		static int g; /* REM */ 
		static int h; /* REM */ 
		static int i; /* REM */ 
		static int j; /* REM */ 
		static int k; /* REM */ 
		static int l; /* REM */ 
		static int m; /* REM */ 
		static int n; /* REM */ 
		static int o; /* REM */ 
		static int p; /* REM */ 
		static int q; /* REM */ 
		static int r; /* REM */ 
		static int s; /* REM */ 
		static int t; /* REM */ 
		static int u; /* REM */ 
		static int v; /* REM */ 
		static int w; /* REM */ 
		static int x; /* REM */ 
		static int y; /* REM */ 
		static int z; /* REM */ 
		static int DELETE; /* REM */ 
		static int WORLD_0; /* REM */ 
		static int WORLD_1; /* REM */ 
		static int WORLD_2; /* REM */ 
		static int WORLD_3; /* REM */ 
		static int WORLD_4; /* REM */ 
		static int WORLD_5; /* REM */ 
		static int WORLD_6; /* REM */ 
		static int WORLD_7; /* REM */ 
		static int WORLD_8; /* REM */ 
		static int WORLD_9; /* REM */ 
		static int WORLD_10; /* REM */ 
		static int WORLD_11; /* REM */ 
		static int WORLD_12; /* REM */ 
		static int WORLD_13; /* REM */ 
		static int WORLD_14; /* REM */ 
		static int WORLD_15; /* REM */ 
		static int WORLD_16; /* REM */ 
		static int WORLD_17; /* REM */ 
		static int WORLD_18; /* REM */ 
		static int WORLD_19; /* REM */ 
		static int WORLD_20; /* REM */ 
		static int WORLD_21; /* REM */ 
		static int WORLD_22; /* REM */ 
		static int WORLD_23; /* REM */ 
		static int WORLD_24; /* REM */ 
		static int WORLD_25; /* REM */ 
		static int WORLD_26; /* REM */ 
		static int WORLD_27; /* REM */ 
		static int WORLD_28; /* REM */ 
		static int WORLD_29; /* REM */ 
		static int WORLD_30; /* REM */ 
		static int WORLD_31; /* REM */ 
		static int WORLD_32; /* REM */ 
		static int WORLD_33; /* REM */ 
		static int WORLD_34; /* REM */ 
		static int WORLD_35; /* REM */ 
		static int WORLD_36; /* REM */ 
		static int WORLD_37; /* REM */ 
		static int WORLD_38; /* REM */ 
		static int WORLD_39; /* REM */ 
		static int WORLD_40; /* REM */ 
		static int WORLD_41; /* REM */ 
		static int WORLD_42; /* REM */ 
		static int WORLD_43; /* REM */ 
		static int WORLD_44; /* REM */ 
		static int WORLD_45; /* REM */ 
		static int WORLD_46; /* REM */ 
		static int WORLD_47; /* REM */ 
		static int WORLD_48; /* REM */ 
		static int WORLD_49; /* REM */ 
		static int WORLD_50; /* REM */ 
		static int WORLD_51; /* REM */ 
		static int WORLD_52; /* REM */ 
		static int WORLD_53; /* REM */ 
		static int WORLD_54; /* REM */ 
		static int WORLD_55; /* REM */ 
		static int WORLD_56; /* REM */ 
		static int WORLD_57; /* REM */ 
		static int WORLD_58; /* REM */ 
		static int WORLD_59; /* REM */ 
		static int WORLD_60; /* REM */ 
		static int WORLD_61; /* REM */ 
		static int WORLD_62; /* REM */ 
		static int WORLD_63; /* REM */ 
		static int WORLD_64; /* REM */ 
		static int WORLD_65; /* REM */ 
		static int WORLD_66; /* REM */ 
		static int WORLD_67; /* REM */ 
		static int WORLD_68; /* REM */ 
		static int WORLD_69; /* REM */ 
		static int WORLD_70; /* REM */ 
		static int WORLD_71; /* REM */ 
		static int WORLD_72; /* REM */ 
		static int WORLD_73; /* REM */ 
		static int WORLD_74; /* REM */ 
		static int WORLD_75; /* REM */ 
		static int WORLD_76; /* REM */ 
		static int WORLD_77; /* REM */ 
		static int WORLD_78; /* REM */ 
		static int WORLD_79; /* REM */ 
		static int WORLD_80; /* REM */ 
		static int WORLD_81; /* REM */ 
		static int WORLD_82; /* REM */ 
		static int WORLD_83; /* REM */ 
		static int WORLD_84; /* REM */ 
		static int WORLD_85; /* REM */ 
		static int WORLD_86; /* REM */ 
		static int WORLD_87; /* REM */ 
		static int WORLD_88; /* REM */ 
		static int WORLD_89; /* REM */ 
		static int WORLD_90; /* REM */ 
		static int WORLD_91; /* REM */ 
		static int WORLD_92; /* REM */ 
		static int WORLD_93; /* REM */ 
		static int WORLD_94; /* REM */ 
		static int WORLD_95; /* REM */ 
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
		static int KP_PERIOD; /* REM */ 
		static int KP_DIVIDE; /* REM */ 
		static int KP_MULTIPLY; /* REM */ 
		static int KP_MINUS; /* REM */ 
		static int KP_PLUS; /* REM */ 
		static int KP_ENTER; /* REM */ 
		static int KP_EQUALS; /* REM */ 
		static int UP; /* REM */ 
		static int DOWN; /* REM */ 
		static int RIGHT; /* REM */ 
		static int LEFT; /* REM */ 
		static int INSERT; /* REM */ 
		static int HOME; /* REM */ 
		static int END; /* REM */ 
		static int PAGEUP; /* REM */ 
		static int PAGEDOWN; /* REM */ 
		static int F1; /* REM */ 
		static int F2; /* REM */ 
		static int F3; /* REM */ 
		static int F4; /* REM */ 
		static int F5; /* REM */ 
		static int F6; /* REM */ 
		static int F7; /* REM */ 
		static int F8; /* REM */ 
		static int F9; /* REM */ 
		static int F10; /* REM */ 
		static int F11; /* REM */ 
		static int F12; /* REM */ 
		static int F13; /* REM */ 
		static int F14; /* REM */ 
		static int F15; /* REM */ 
		static int NUMLOCK; /* REM */ 
		static int CAPSLOCK; /* REM */ 
		static int SCROLLOCK; /* REM */ 
		static int RSHIFT; /* REM */ 
		static int LSHIFT; /* REM */ 
		static int RCTRL; /* REM */ 
		static int LCTRL; /* REM */ 
		static int RALT; /* REM */ 
		static int LALT; /* REM */ 
		static int RMETA; /* REM */ 
		static int LMETA; /* REM */ 
		static int LSUPER; /* REM */ 
		static int RSUPER; /* REM */ 
		static int MODE; /* REM */ 
		static int COMPOSE; /* REM */ 
		static int HELP; /* REM */ 
		static int PRINT; /* REM */ 
		static int SYSREQ; /* REM */ 
		static int BREAK; /* REM */ 
		static int MENU; /* REM */ 
		static int POWER; /* REM */ 
		static int EURO; /* REM */ 
		static int UNDO; /* REM */ 
};

} // end namespace nme

#endif /* INCLUDED_nme_KeyCode */ 
