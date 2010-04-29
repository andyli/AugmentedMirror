#ifndef INCLUDED_nme_EventType
#define INCLUDED_nme_EventType

#include <hxcpp.h>

HX_DECLARE_CLASS1(nme,EventType)
namespace nme{


class EventType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef EventType_obj OBJ_;

	public:
		EventType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_STRING(L"nme.EventType",13); }
		::String __ToString() const { return HX_STRING(L"EventType.",10) + tag; }

		static EventType et_active;
		static EventType et_joystickball;
		static EventType et_joystickbutton;
		static EventType et_joystickhat;
		static EventType et_joystickmove;
		static EventType et_keydown;
		static EventType et_keyup;
		static EventType et_mousebutton_down;
		static EventType et_mousebutton_up;
		static EventType et_mousemove;
		static EventType et_noevent;
		static EventType et_quit;
		static EventType et_resize;
		static EventType et_soundfinished;
		static EventType et_syswm;
		static EventType et_user;
};

} // end namespace nme

#endif /* INCLUDED_nme_EventType */ 
