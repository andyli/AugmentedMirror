#include <hxcpp.h>

#ifndef INCLUDED_neash_text_KeyCode
#include <neash/text/KeyCode.h>
#endif
#ifndef INCLUDED_nme_KeyCode
#include <nme/KeyCode.h>
#endif
namespace neash{
namespace text{

Void KeyCode_obj::__construct()
{
	return null();
}

KeyCode_obj::~KeyCode_obj() { }

Dynamic KeyCode_obj::__CreateEmpty() { return  new KeyCode_obj; }
hx::ObjectPtr< KeyCode_obj > KeyCode_obj::__new()
{  hx::ObjectPtr< KeyCode_obj > result = new KeyCode_obj();
	result->__construct();
	return result;}

Dynamic KeyCode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyCode_obj > result = new KeyCode_obj();
	result->__construct();
	return result;}

int KeyCode_obj::KEY_0;

int KeyCode_obj::KEY_1;

int KeyCode_obj::KEY_2;

int KeyCode_obj::KEY_3;

int KeyCode_obj::KEY_4;

int KeyCode_obj::KEY_5;

int KeyCode_obj::KEY_6;

int KeyCode_obj::KEY_7;

int KeyCode_obj::KEY_8;

int KeyCode_obj::KEY_9;

int KeyCode_obj::A;

int KeyCode_obj::B;

int KeyCode_obj::C;

int KeyCode_obj::D;

int KeyCode_obj::E;

int KeyCode_obj::F;

int KeyCode_obj::G;

int KeyCode_obj::H;

int KeyCode_obj::I;

int KeyCode_obj::J;

int KeyCode_obj::K;

int KeyCode_obj::L;

int KeyCode_obj::M;

int KeyCode_obj::N;

int KeyCode_obj::O;

int KeyCode_obj::P;

int KeyCode_obj::Q;

int KeyCode_obj::R;

int KeyCode_obj::S;

int KeyCode_obj::T;

int KeyCode_obj::U;

int KeyCode_obj::V;

int KeyCode_obj::W;

int KeyCode_obj::X;

int KeyCode_obj::Y;

int KeyCode_obj::Z;

int KeyCode_obj::KP0;

int KeyCode_obj::KP1;

int KeyCode_obj::KP2;

int KeyCode_obj::KP3;

int KeyCode_obj::KP4;

int KeyCode_obj::KP5;

int KeyCode_obj::KP6;

int KeyCode_obj::KP7;

int KeyCode_obj::KP8;

int KeyCode_obj::KP9;

int KeyCode_obj::KP_MULTIPLY;

int KeyCode_obj::KP_ADD;

int KeyCode_obj::KP_ENTER;

int KeyCode_obj::KP_SUBTRACT;

int KeyCode_obj::KP_PERIOD;

int KeyCode_obj::KP_DIVIDE;

int KeyCode_obj::F1;

int KeyCode_obj::F2;

int KeyCode_obj::F3;

int KeyCode_obj::F4;

int KeyCode_obj::F5;

int KeyCode_obj::F6;

int KeyCode_obj::F7;

int KeyCode_obj::F8;

int KeyCode_obj::F9;

int KeyCode_obj::F11;

int KeyCode_obj::F12;

int KeyCode_obj::F13;

int KeyCode_obj::F14;

int KeyCode_obj::F15;

int KeyCode_obj::BACKSPACE;

int KeyCode_obj::TAB;

int KeyCode_obj::ENTER;

int KeyCode_obj::SHIFT;

int KeyCode_obj::CONTROL;

int KeyCode_obj::CAPSLOCK;

int KeyCode_obj::ESCAPE;

int KeyCode_obj::SPACE;

int KeyCode_obj::PAGEUP;

int KeyCode_obj::PAGEDOWN;

int KeyCode_obj::END;

int KeyCode_obj::HOME;

int KeyCode_obj::LEFT;

int KeyCode_obj::RIGHT;

int KeyCode_obj::UP;

int KeyCode_obj::DOWN;

int KeyCode_obj::INSERT;

int KeyCode_obj::DELETE;

int KeyCode_obj::NUMLOCK;

int KeyCode_obj::BREAK;

int KeyCode_obj::ConvertCode( int inNME){
	if ((bool((inNME <= 32)) || bool(((bool((inNME >= ::neash::text::KeyCode_obj::KEY_0)) && bool((inNME <= ::neash::text::KeyCode_obj::KEY_9)))))))
		return inNME;
	if ((bool((inNME >= 97)) && bool((inNME <= 122))))
		return (((inNME - 97)) + 65);
	if ((bool((inNME >= ::nme::KeyCode_obj::F1)) && bool((inNME <= ::nme::KeyCode_obj::F15))))
		return (((inNME - ::nme::KeyCode_obj::F1)) + ::neash::text::KeyCode_obj::F1);
	if ((bool((inNME >= ::nme::KeyCode_obj::KP0)) && bool((inNME <= ::nme::KeyCode_obj::KP9))))
		return (((inNME - ::nme::KeyCode_obj::KP0)) + ::neash::text::KeyCode_obj::KP0);
	int _switch_1 = (inNME);
	if (  ( _switch_1==::nme::KeyCode_obj::KP_PERIOD)){
		return ::neash::text::KeyCode_obj::KP_PERIOD;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::KP_DIVIDE)){
		return ::neash::text::KeyCode_obj::KP_DIVIDE;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::KP_MULTIPLY)){
		return ::neash::text::KeyCode_obj::KP_MULTIPLY;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::KP_MINUS)){
		return ::neash::text::KeyCode_obj::KP_SUBTRACT;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::KP_PLUS)){
		return ::neash::text::KeyCode_obj::KP_ADD;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::KP_ENTER)){
		return ::neash::text::KeyCode_obj::KP_ENTER;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::UP)){
		return ::neash::text::KeyCode_obj::UP;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::DOWN)){
		return ::neash::text::KeyCode_obj::DOWN;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::RIGHT)){
		return ::neash::text::KeyCode_obj::RIGHT;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::LEFT)){
		return ::neash::text::KeyCode_obj::LEFT;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::INSERT)){
		return ::neash::text::KeyCode_obj::INSERT;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::DELETE)){
		return ::neash::text::KeyCode_obj::DELETE;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::HOME)){
		return ::neash::text::KeyCode_obj::HOME;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::END)){
		return ::neash::text::KeyCode_obj::END;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::PAGEUP)){
		return ::neash::text::KeyCode_obj::PAGEUP;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::PAGEDOWN)){
		return ::neash::text::KeyCode_obj::PAGEDOWN;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::NUMLOCK)){
		return ::neash::text::KeyCode_obj::NUMLOCK;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::CAPSLOCK)){
		return ::neash::text::KeyCode_obj::CAPSLOCK;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::RSHIFT)){
		return ::neash::text::KeyCode_obj::SHIFT;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::LSHIFT)){
		return ::neash::text::KeyCode_obj::SHIFT;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::RCTRL)){
		return ::neash::text::KeyCode_obj::CONTROL;
	}
	else if (  ( _switch_1==::nme::KeyCode_obj::LCTRL)){
		return ::neash::text::KeyCode_obj::CONTROL;
	}
	return 0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(KeyCode_obj,ConvertCode,return )

int KeyCode_obj::ConvertASCII( int inNME,bool inShift,bool inControl){
	if ((bool((inNME >= 97)) && bool((bool((inNME <= 122)) && bool(inShift))))){
		return (((inNME - 97)) + 65);
	}
	else{
		if ((bool((inNME >= 97)) && bool((bool((inNME <= 122)) && bool(inControl)))))
			return (((inNME - 97)) + 1);
	}
	if ((inNME < 128))
		return inNME;
	return 0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(KeyCode_obj,ConvertASCII,return )

int KeyCode_obj::ConvertLocation( int inNME){
	if ((bool((inNME == ::nme::KeyCode_obj::RCTRL)) || bool((inNME == ::nme::KeyCode_obj::RSHIFT))))
		return 1;
	return 0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(KeyCode_obj,ConvertLocation,return )


KeyCode_obj::KeyCode_obj()
{
}

void KeyCode_obj::__Mark()
{
}

Dynamic KeyCode_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"A",sizeof(wchar_t)*1) ) { return A; }
		if (!memcmp(inName.__s,L"B",sizeof(wchar_t)*1) ) { return B; }
		if (!memcmp(inName.__s,L"C",sizeof(wchar_t)*1) ) { return C; }
		if (!memcmp(inName.__s,L"D",sizeof(wchar_t)*1) ) { return D; }
		if (!memcmp(inName.__s,L"E",sizeof(wchar_t)*1) ) { return E; }
		if (!memcmp(inName.__s,L"F",sizeof(wchar_t)*1) ) { return F; }
		if (!memcmp(inName.__s,L"G",sizeof(wchar_t)*1) ) { return G; }
		if (!memcmp(inName.__s,L"H",sizeof(wchar_t)*1) ) { return H; }
		if (!memcmp(inName.__s,L"I",sizeof(wchar_t)*1) ) { return I; }
		if (!memcmp(inName.__s,L"J",sizeof(wchar_t)*1) ) { return J; }
		if (!memcmp(inName.__s,L"K",sizeof(wchar_t)*1) ) { return K; }
		if (!memcmp(inName.__s,L"L",sizeof(wchar_t)*1) ) { return L; }
		if (!memcmp(inName.__s,L"M",sizeof(wchar_t)*1) ) { return M; }
		if (!memcmp(inName.__s,L"N",sizeof(wchar_t)*1) ) { return N; }
		if (!memcmp(inName.__s,L"O",sizeof(wchar_t)*1) ) { return O; }
		if (!memcmp(inName.__s,L"P",sizeof(wchar_t)*1) ) { return P; }
		if (!memcmp(inName.__s,L"Q",sizeof(wchar_t)*1) ) { return Q; }
		if (!memcmp(inName.__s,L"R",sizeof(wchar_t)*1) ) { return R; }
		if (!memcmp(inName.__s,L"S",sizeof(wchar_t)*1) ) { return S; }
		if (!memcmp(inName.__s,L"T",sizeof(wchar_t)*1) ) { return T; }
		if (!memcmp(inName.__s,L"U",sizeof(wchar_t)*1) ) { return U; }
		if (!memcmp(inName.__s,L"V",sizeof(wchar_t)*1) ) { return V; }
		if (!memcmp(inName.__s,L"W",sizeof(wchar_t)*1) ) { return W; }
		if (!memcmp(inName.__s,L"X",sizeof(wchar_t)*1) ) { return X; }
		if (!memcmp(inName.__s,L"Y",sizeof(wchar_t)*1) ) { return Y; }
		if (!memcmp(inName.__s,L"Z",sizeof(wchar_t)*1) ) { return Z; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"F1",sizeof(wchar_t)*2) ) { return F1; }
		if (!memcmp(inName.__s,L"F2",sizeof(wchar_t)*2) ) { return F2; }
		if (!memcmp(inName.__s,L"F3",sizeof(wchar_t)*2) ) { return F3; }
		if (!memcmp(inName.__s,L"F4",sizeof(wchar_t)*2) ) { return F4; }
		if (!memcmp(inName.__s,L"F5",sizeof(wchar_t)*2) ) { return F5; }
		if (!memcmp(inName.__s,L"F6",sizeof(wchar_t)*2) ) { return F6; }
		if (!memcmp(inName.__s,L"F7",sizeof(wchar_t)*2) ) { return F7; }
		if (!memcmp(inName.__s,L"F8",sizeof(wchar_t)*2) ) { return F8; }
		if (!memcmp(inName.__s,L"F9",sizeof(wchar_t)*2) ) { return F9; }
		if (!memcmp(inName.__s,L"UP",sizeof(wchar_t)*2) ) { return UP; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"KP0",sizeof(wchar_t)*3) ) { return KP0; }
		if (!memcmp(inName.__s,L"KP1",sizeof(wchar_t)*3) ) { return KP1; }
		if (!memcmp(inName.__s,L"KP2",sizeof(wchar_t)*3) ) { return KP2; }
		if (!memcmp(inName.__s,L"KP3",sizeof(wchar_t)*3) ) { return KP3; }
		if (!memcmp(inName.__s,L"KP4",sizeof(wchar_t)*3) ) { return KP4; }
		if (!memcmp(inName.__s,L"KP5",sizeof(wchar_t)*3) ) { return KP5; }
		if (!memcmp(inName.__s,L"KP6",sizeof(wchar_t)*3) ) { return KP6; }
		if (!memcmp(inName.__s,L"KP7",sizeof(wchar_t)*3) ) { return KP7; }
		if (!memcmp(inName.__s,L"KP8",sizeof(wchar_t)*3) ) { return KP8; }
		if (!memcmp(inName.__s,L"KP9",sizeof(wchar_t)*3) ) { return KP9; }
		if (!memcmp(inName.__s,L"F11",sizeof(wchar_t)*3) ) { return F11; }
		if (!memcmp(inName.__s,L"F12",sizeof(wchar_t)*3) ) { return F12; }
		if (!memcmp(inName.__s,L"F13",sizeof(wchar_t)*3) ) { return F13; }
		if (!memcmp(inName.__s,L"F14",sizeof(wchar_t)*3) ) { return F14; }
		if (!memcmp(inName.__s,L"F15",sizeof(wchar_t)*3) ) { return F15; }
		if (!memcmp(inName.__s,L"TAB",sizeof(wchar_t)*3) ) { return TAB; }
		if (!memcmp(inName.__s,L"END",sizeof(wchar_t)*3) ) { return END; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"HOME",sizeof(wchar_t)*4) ) { return HOME; }
		if (!memcmp(inName.__s,L"LEFT",sizeof(wchar_t)*4) ) { return LEFT; }
		if (!memcmp(inName.__s,L"DOWN",sizeof(wchar_t)*4) ) { return DOWN; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"KEY_0",sizeof(wchar_t)*5) ) { return KEY_0; }
		if (!memcmp(inName.__s,L"KEY_1",sizeof(wchar_t)*5) ) { return KEY_1; }
		if (!memcmp(inName.__s,L"KEY_2",sizeof(wchar_t)*5) ) { return KEY_2; }
		if (!memcmp(inName.__s,L"KEY_3",sizeof(wchar_t)*5) ) { return KEY_3; }
		if (!memcmp(inName.__s,L"KEY_4",sizeof(wchar_t)*5) ) { return KEY_4; }
		if (!memcmp(inName.__s,L"KEY_5",sizeof(wchar_t)*5) ) { return KEY_5; }
		if (!memcmp(inName.__s,L"KEY_6",sizeof(wchar_t)*5) ) { return KEY_6; }
		if (!memcmp(inName.__s,L"KEY_7",sizeof(wchar_t)*5) ) { return KEY_7; }
		if (!memcmp(inName.__s,L"KEY_8",sizeof(wchar_t)*5) ) { return KEY_8; }
		if (!memcmp(inName.__s,L"KEY_9",sizeof(wchar_t)*5) ) { return KEY_9; }
		if (!memcmp(inName.__s,L"ENTER",sizeof(wchar_t)*5) ) { return ENTER; }
		if (!memcmp(inName.__s,L"SHIFT",sizeof(wchar_t)*5) ) { return SHIFT; }
		if (!memcmp(inName.__s,L"SPACE",sizeof(wchar_t)*5) ) { return SPACE; }
		if (!memcmp(inName.__s,L"RIGHT",sizeof(wchar_t)*5) ) { return RIGHT; }
		if (!memcmp(inName.__s,L"BREAK",sizeof(wchar_t)*5) ) { return BREAK; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"KP_ADD",sizeof(wchar_t)*6) ) { return KP_ADD; }
		if (!memcmp(inName.__s,L"ESCAPE",sizeof(wchar_t)*6) ) { return ESCAPE; }
		if (!memcmp(inName.__s,L"PAGEUP",sizeof(wchar_t)*6) ) { return PAGEUP; }
		if (!memcmp(inName.__s,L"INSERT",sizeof(wchar_t)*6) ) { return INSERT; }
		if (!memcmp(inName.__s,L"DELETE",sizeof(wchar_t)*6) ) { return DELETE; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"CONTROL",sizeof(wchar_t)*7) ) { return CONTROL; }
		if (!memcmp(inName.__s,L"NUMLOCK",sizeof(wchar_t)*7) ) { return NUMLOCK; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"KP_ENTER",sizeof(wchar_t)*8) ) { return KP_ENTER; }
		if (!memcmp(inName.__s,L"CAPSLOCK",sizeof(wchar_t)*8) ) { return CAPSLOCK; }
		if (!memcmp(inName.__s,L"PAGEDOWN",sizeof(wchar_t)*8) ) { return PAGEDOWN; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"KP_PERIOD",sizeof(wchar_t)*9) ) { return KP_PERIOD; }
		if (!memcmp(inName.__s,L"KP_DIVIDE",sizeof(wchar_t)*9) ) { return KP_DIVIDE; }
		if (!memcmp(inName.__s,L"BACKSPACE",sizeof(wchar_t)*9) ) { return BACKSPACE; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"KP_MULTIPLY",sizeof(wchar_t)*11) ) { return KP_MULTIPLY; }
		if (!memcmp(inName.__s,L"KP_SUBTRACT",sizeof(wchar_t)*11) ) { return KP_SUBTRACT; }
		if (!memcmp(inName.__s,L"ConvertCode",sizeof(wchar_t)*11) ) { return ConvertCode_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"ConvertASCII",sizeof(wchar_t)*12) ) { return ConvertASCII_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"ConvertLocation",sizeof(wchar_t)*15) ) { return ConvertLocation_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic KeyCode_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"A",sizeof(wchar_t)*1) ) { A=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"B",sizeof(wchar_t)*1) ) { B=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"C",sizeof(wchar_t)*1) ) { C=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"D",sizeof(wchar_t)*1) ) { D=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"E",sizeof(wchar_t)*1) ) { E=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F",sizeof(wchar_t)*1) ) { F=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"G",sizeof(wchar_t)*1) ) { G=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"H",sizeof(wchar_t)*1) ) { H=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"I",sizeof(wchar_t)*1) ) { I=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"J",sizeof(wchar_t)*1) ) { J=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"K",sizeof(wchar_t)*1) ) { K=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"L",sizeof(wchar_t)*1) ) { L=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"M",sizeof(wchar_t)*1) ) { M=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"N",sizeof(wchar_t)*1) ) { N=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"O",sizeof(wchar_t)*1) ) { O=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"P",sizeof(wchar_t)*1) ) { P=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"Q",sizeof(wchar_t)*1) ) { Q=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"R",sizeof(wchar_t)*1) ) { R=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"S",sizeof(wchar_t)*1) ) { S=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"T",sizeof(wchar_t)*1) ) { T=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"U",sizeof(wchar_t)*1) ) { U=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"V",sizeof(wchar_t)*1) ) { V=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"W",sizeof(wchar_t)*1) ) { W=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"X",sizeof(wchar_t)*1) ) { X=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"Y",sizeof(wchar_t)*1) ) { Y=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"Z",sizeof(wchar_t)*1) ) { Z=inValue.Cast< int >(); return inValue; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"F1",sizeof(wchar_t)*2) ) { F1=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F2",sizeof(wchar_t)*2) ) { F2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F3",sizeof(wchar_t)*2) ) { F3=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F4",sizeof(wchar_t)*2) ) { F4=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F5",sizeof(wchar_t)*2) ) { F5=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F6",sizeof(wchar_t)*2) ) { F6=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F7",sizeof(wchar_t)*2) ) { F7=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F8",sizeof(wchar_t)*2) ) { F8=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F9",sizeof(wchar_t)*2) ) { F9=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"UP",sizeof(wchar_t)*2) ) { UP=inValue.Cast< int >(); return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"KP0",sizeof(wchar_t)*3) ) { KP0=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP1",sizeof(wchar_t)*3) ) { KP1=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP2",sizeof(wchar_t)*3) ) { KP2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP3",sizeof(wchar_t)*3) ) { KP3=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP4",sizeof(wchar_t)*3) ) { KP4=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP5",sizeof(wchar_t)*3) ) { KP5=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP6",sizeof(wchar_t)*3) ) { KP6=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP7",sizeof(wchar_t)*3) ) { KP7=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP8",sizeof(wchar_t)*3) ) { KP8=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP9",sizeof(wchar_t)*3) ) { KP9=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F11",sizeof(wchar_t)*3) ) { F11=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F12",sizeof(wchar_t)*3) ) { F12=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F13",sizeof(wchar_t)*3) ) { F13=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F14",sizeof(wchar_t)*3) ) { F14=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"F15",sizeof(wchar_t)*3) ) { F15=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"TAB",sizeof(wchar_t)*3) ) { TAB=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"END",sizeof(wchar_t)*3) ) { END=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"HOME",sizeof(wchar_t)*4) ) { HOME=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"LEFT",sizeof(wchar_t)*4) ) { LEFT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DOWN",sizeof(wchar_t)*4) ) { DOWN=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"KEY_0",sizeof(wchar_t)*5) ) { KEY_0=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KEY_1",sizeof(wchar_t)*5) ) { KEY_1=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KEY_2",sizeof(wchar_t)*5) ) { KEY_2=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KEY_3",sizeof(wchar_t)*5) ) { KEY_3=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KEY_4",sizeof(wchar_t)*5) ) { KEY_4=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KEY_5",sizeof(wchar_t)*5) ) { KEY_5=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KEY_6",sizeof(wchar_t)*5) ) { KEY_6=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KEY_7",sizeof(wchar_t)*5) ) { KEY_7=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KEY_8",sizeof(wchar_t)*5) ) { KEY_8=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KEY_9",sizeof(wchar_t)*5) ) { KEY_9=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"ENTER",sizeof(wchar_t)*5) ) { ENTER=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SHIFT",sizeof(wchar_t)*5) ) { SHIFT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"SPACE",sizeof(wchar_t)*5) ) { SPACE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"RIGHT",sizeof(wchar_t)*5) ) { RIGHT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BREAK",sizeof(wchar_t)*5) ) { BREAK=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"KP_ADD",sizeof(wchar_t)*6) ) { KP_ADD=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"ESCAPE",sizeof(wchar_t)*6) ) { ESCAPE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"PAGEUP",sizeof(wchar_t)*6) ) { PAGEUP=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"INSERT",sizeof(wchar_t)*6) ) { INSERT=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"DELETE",sizeof(wchar_t)*6) ) { DELETE=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"CONTROL",sizeof(wchar_t)*7) ) { CONTROL=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"NUMLOCK",sizeof(wchar_t)*7) ) { NUMLOCK=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"KP_ENTER",sizeof(wchar_t)*8) ) { KP_ENTER=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"CAPSLOCK",sizeof(wchar_t)*8) ) { CAPSLOCK=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"PAGEDOWN",sizeof(wchar_t)*8) ) { PAGEDOWN=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"KP_PERIOD",sizeof(wchar_t)*9) ) { KP_PERIOD=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP_DIVIDE",sizeof(wchar_t)*9) ) { KP_DIVIDE=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"BACKSPACE",sizeof(wchar_t)*9) ) { BACKSPACE=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"KP_MULTIPLY",sizeof(wchar_t)*11) ) { KP_MULTIPLY=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"KP_SUBTRACT",sizeof(wchar_t)*11) ) { KP_SUBTRACT=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void KeyCode_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"KEY_0",5),
	HX_STRING(L"KEY_1",5),
	HX_STRING(L"KEY_2",5),
	HX_STRING(L"KEY_3",5),
	HX_STRING(L"KEY_4",5),
	HX_STRING(L"KEY_5",5),
	HX_STRING(L"KEY_6",5),
	HX_STRING(L"KEY_7",5),
	HX_STRING(L"KEY_8",5),
	HX_STRING(L"KEY_9",5),
	HX_STRING(L"A",1),
	HX_STRING(L"B",1),
	HX_STRING(L"C",1),
	HX_STRING(L"D",1),
	HX_STRING(L"E",1),
	HX_STRING(L"F",1),
	HX_STRING(L"G",1),
	HX_STRING(L"H",1),
	HX_STRING(L"I",1),
	HX_STRING(L"J",1),
	HX_STRING(L"K",1),
	HX_STRING(L"L",1),
	HX_STRING(L"M",1),
	HX_STRING(L"N",1),
	HX_STRING(L"O",1),
	HX_STRING(L"P",1),
	HX_STRING(L"Q",1),
	HX_STRING(L"R",1),
	HX_STRING(L"S",1),
	HX_STRING(L"T",1),
	HX_STRING(L"U",1),
	HX_STRING(L"V",1),
	HX_STRING(L"W",1),
	HX_STRING(L"X",1),
	HX_STRING(L"Y",1),
	HX_STRING(L"Z",1),
	HX_STRING(L"KP0",3),
	HX_STRING(L"KP1",3),
	HX_STRING(L"KP2",3),
	HX_STRING(L"KP3",3),
	HX_STRING(L"KP4",3),
	HX_STRING(L"KP5",3),
	HX_STRING(L"KP6",3),
	HX_STRING(L"KP7",3),
	HX_STRING(L"KP8",3),
	HX_STRING(L"KP9",3),
	HX_STRING(L"KP_MULTIPLY",11),
	HX_STRING(L"KP_ADD",6),
	HX_STRING(L"KP_ENTER",8),
	HX_STRING(L"KP_SUBTRACT",11),
	HX_STRING(L"KP_PERIOD",9),
	HX_STRING(L"KP_DIVIDE",9),
	HX_STRING(L"F1",2),
	HX_STRING(L"F2",2),
	HX_STRING(L"F3",2),
	HX_STRING(L"F4",2),
	HX_STRING(L"F5",2),
	HX_STRING(L"F6",2),
	HX_STRING(L"F7",2),
	HX_STRING(L"F8",2),
	HX_STRING(L"F9",2),
	HX_STRING(L"F11",3),
	HX_STRING(L"F12",3),
	HX_STRING(L"F13",3),
	HX_STRING(L"F14",3),
	HX_STRING(L"F15",3),
	HX_STRING(L"BACKSPACE",9),
	HX_STRING(L"TAB",3),
	HX_STRING(L"ENTER",5),
	HX_STRING(L"SHIFT",5),
	HX_STRING(L"CONTROL",7),
	HX_STRING(L"CAPSLOCK",8),
	HX_STRING(L"ESCAPE",6),
	HX_STRING(L"SPACE",5),
	HX_STRING(L"PAGEUP",6),
	HX_STRING(L"PAGEDOWN",8),
	HX_STRING(L"END",3),
	HX_STRING(L"HOME",4),
	HX_STRING(L"LEFT",4),
	HX_STRING(L"RIGHT",5),
	HX_STRING(L"UP",2),
	HX_STRING(L"DOWN",4),
	HX_STRING(L"INSERT",6),
	HX_STRING(L"DELETE",6),
	HX_STRING(L"NUMLOCK",7),
	HX_STRING(L"BREAK",5),
	HX_STRING(L"ConvertCode",11),
	HX_STRING(L"ConvertASCII",12),
	HX_STRING(L"ConvertLocation",15),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(KeyCode_obj::KEY_0);
	hx::MarkMember(KeyCode_obj::KEY_1);
	hx::MarkMember(KeyCode_obj::KEY_2);
	hx::MarkMember(KeyCode_obj::KEY_3);
	hx::MarkMember(KeyCode_obj::KEY_4);
	hx::MarkMember(KeyCode_obj::KEY_5);
	hx::MarkMember(KeyCode_obj::KEY_6);
	hx::MarkMember(KeyCode_obj::KEY_7);
	hx::MarkMember(KeyCode_obj::KEY_8);
	hx::MarkMember(KeyCode_obj::KEY_9);
	hx::MarkMember(KeyCode_obj::A);
	hx::MarkMember(KeyCode_obj::B);
	hx::MarkMember(KeyCode_obj::C);
	hx::MarkMember(KeyCode_obj::D);
	hx::MarkMember(KeyCode_obj::E);
	hx::MarkMember(KeyCode_obj::F);
	hx::MarkMember(KeyCode_obj::G);
	hx::MarkMember(KeyCode_obj::H);
	hx::MarkMember(KeyCode_obj::I);
	hx::MarkMember(KeyCode_obj::J);
	hx::MarkMember(KeyCode_obj::K);
	hx::MarkMember(KeyCode_obj::L);
	hx::MarkMember(KeyCode_obj::M);
	hx::MarkMember(KeyCode_obj::N);
	hx::MarkMember(KeyCode_obj::O);
	hx::MarkMember(KeyCode_obj::P);
	hx::MarkMember(KeyCode_obj::Q);
	hx::MarkMember(KeyCode_obj::R);
	hx::MarkMember(KeyCode_obj::S);
	hx::MarkMember(KeyCode_obj::T);
	hx::MarkMember(KeyCode_obj::U);
	hx::MarkMember(KeyCode_obj::V);
	hx::MarkMember(KeyCode_obj::W);
	hx::MarkMember(KeyCode_obj::X);
	hx::MarkMember(KeyCode_obj::Y);
	hx::MarkMember(KeyCode_obj::Z);
	hx::MarkMember(KeyCode_obj::KP0);
	hx::MarkMember(KeyCode_obj::KP1);
	hx::MarkMember(KeyCode_obj::KP2);
	hx::MarkMember(KeyCode_obj::KP3);
	hx::MarkMember(KeyCode_obj::KP4);
	hx::MarkMember(KeyCode_obj::KP5);
	hx::MarkMember(KeyCode_obj::KP6);
	hx::MarkMember(KeyCode_obj::KP7);
	hx::MarkMember(KeyCode_obj::KP8);
	hx::MarkMember(KeyCode_obj::KP9);
	hx::MarkMember(KeyCode_obj::KP_MULTIPLY);
	hx::MarkMember(KeyCode_obj::KP_ADD);
	hx::MarkMember(KeyCode_obj::KP_ENTER);
	hx::MarkMember(KeyCode_obj::KP_SUBTRACT);
	hx::MarkMember(KeyCode_obj::KP_PERIOD);
	hx::MarkMember(KeyCode_obj::KP_DIVIDE);
	hx::MarkMember(KeyCode_obj::F1);
	hx::MarkMember(KeyCode_obj::F2);
	hx::MarkMember(KeyCode_obj::F3);
	hx::MarkMember(KeyCode_obj::F4);
	hx::MarkMember(KeyCode_obj::F5);
	hx::MarkMember(KeyCode_obj::F6);
	hx::MarkMember(KeyCode_obj::F7);
	hx::MarkMember(KeyCode_obj::F8);
	hx::MarkMember(KeyCode_obj::F9);
	hx::MarkMember(KeyCode_obj::F11);
	hx::MarkMember(KeyCode_obj::F12);
	hx::MarkMember(KeyCode_obj::F13);
	hx::MarkMember(KeyCode_obj::F14);
	hx::MarkMember(KeyCode_obj::F15);
	hx::MarkMember(KeyCode_obj::BACKSPACE);
	hx::MarkMember(KeyCode_obj::TAB);
	hx::MarkMember(KeyCode_obj::ENTER);
	hx::MarkMember(KeyCode_obj::SHIFT);
	hx::MarkMember(KeyCode_obj::CONTROL);
	hx::MarkMember(KeyCode_obj::CAPSLOCK);
	hx::MarkMember(KeyCode_obj::ESCAPE);
	hx::MarkMember(KeyCode_obj::SPACE);
	hx::MarkMember(KeyCode_obj::PAGEUP);
	hx::MarkMember(KeyCode_obj::PAGEDOWN);
	hx::MarkMember(KeyCode_obj::END);
	hx::MarkMember(KeyCode_obj::HOME);
	hx::MarkMember(KeyCode_obj::LEFT);
	hx::MarkMember(KeyCode_obj::RIGHT);
	hx::MarkMember(KeyCode_obj::UP);
	hx::MarkMember(KeyCode_obj::DOWN);
	hx::MarkMember(KeyCode_obj::INSERT);
	hx::MarkMember(KeyCode_obj::DELETE);
	hx::MarkMember(KeyCode_obj::NUMLOCK);
	hx::MarkMember(KeyCode_obj::BREAK);
};

Class KeyCode_obj::__mClass;

void KeyCode_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.text.KeyCode",18), hx::TCanCast< KeyCode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void KeyCode_obj::__boot()
{
	hx::Static(KEY_0) = 48;
	hx::Static(KEY_1) = 49;
	hx::Static(KEY_2) = 50;
	hx::Static(KEY_3) = 51;
	hx::Static(KEY_4) = 52;
	hx::Static(KEY_5) = 53;
	hx::Static(KEY_6) = 54;
	hx::Static(KEY_7) = 55;
	hx::Static(KEY_8) = 56;
	hx::Static(KEY_9) = 57;
	hx::Static(A) = 65;
	hx::Static(B) = 66;
	hx::Static(C) = 67;
	hx::Static(D) = 68;
	hx::Static(E) = 69;
	hx::Static(F) = 70;
	hx::Static(G) = 71;
	hx::Static(H) = 72;
	hx::Static(I) = 73;
	hx::Static(J) = 74;
	hx::Static(K) = 75;
	hx::Static(L) = 76;
	hx::Static(M) = 77;
	hx::Static(N) = 78;
	hx::Static(O) = 79;
	hx::Static(P) = 80;
	hx::Static(Q) = 81;
	hx::Static(R) = 82;
	hx::Static(S) = 83;
	hx::Static(T) = 84;
	hx::Static(U) = 85;
	hx::Static(V) = 86;
	hx::Static(W) = 87;
	hx::Static(X) = 88;
	hx::Static(Y) = 89;
	hx::Static(Z) = 90;
	hx::Static(KP0) = 96;
	hx::Static(KP1) = 97;
	hx::Static(KP2) = 98;
	hx::Static(KP3) = 99;
	hx::Static(KP4) = 100;
	hx::Static(KP5) = 101;
	hx::Static(KP6) = 102;
	hx::Static(KP7) = 103;
	hx::Static(KP8) = 104;
	hx::Static(KP9) = 105;
	hx::Static(KP_MULTIPLY) = 106;
	hx::Static(KP_ADD) = 107;
	hx::Static(KP_ENTER) = 108;
	hx::Static(KP_SUBTRACT) = 109;
	hx::Static(KP_PERIOD) = 110;
	hx::Static(KP_DIVIDE) = 111;
	hx::Static(F1) = 112;
	hx::Static(F2) = 113;
	hx::Static(F3) = 114;
	hx::Static(F4) = 115;
	hx::Static(F5) = 116;
	hx::Static(F6) = 117;
	hx::Static(F7) = 118;
	hx::Static(F8) = 119;
	hx::Static(F9) = 120;
	hx::Static(F11) = 122;
	hx::Static(F12) = 123;
	hx::Static(F13) = 124;
	hx::Static(F14) = 125;
	hx::Static(F15) = 126;
	hx::Static(BACKSPACE) = 8;
	hx::Static(TAB) = 9;
	hx::Static(ENTER) = 13;
	hx::Static(SHIFT) = 16;
	hx::Static(CONTROL) = 17;
	hx::Static(CAPSLOCK) = 18;
	hx::Static(ESCAPE) = 27;
	hx::Static(SPACE) = 32;
	hx::Static(PAGEUP) = 33;
	hx::Static(PAGEDOWN) = 34;
	hx::Static(END) = 35;
	hx::Static(HOME) = 36;
	hx::Static(LEFT) = 37;
	hx::Static(RIGHT) = 38;
	hx::Static(UP) = 39;
	hx::Static(DOWN) = 40;
	hx::Static(INSERT) = 45;
	hx::Static(DELETE) = 46;
	hx::Static(NUMLOCK) = 144;
	hx::Static(BREAK) = 19;
}

} // end namespace neash
} // end namespace text
