#ifndef INCLUDED_neash_events_KeyboardEvent
#define INCLUDED_neash_events_KeyboardEvent

#include <hxcpp.h>

#include <neash/events/Event.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,KeyboardEvent)
namespace neash{
namespace events{


class KeyboardEvent_obj : public ::neash::events::Event_obj{
	public:
		typedef ::neash::events::Event_obj super;
		typedef KeyboardEvent_obj OBJ_;
		KeyboardEvent_obj();
		Void __construct(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic inCharCode,Dynamic inKeyCode,Dynamic inKeyLocation,Dynamic inCtrlKey,Dynamic inAltKey,Dynamic inShiftKey);

	public:
		static hx::ObjectPtr< KeyboardEvent_obj > __new(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic inCharCode,Dynamic inKeyCode,Dynamic inKeyLocation,Dynamic inCtrlKey,Dynamic inAltKey,Dynamic inShiftKey);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~KeyboardEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"KeyboardEvent",13); }

		int keyCode; /* REM */ 
		int charCode; /* REM */ 
		int keyLocation; /* REM */ 
		bool ctrlKey; /* REM */ 
		bool altKey; /* REM */ 
		bool shiftKey; /* REM */ 
		static ::String KEY_DOWN; /* REM */ 
		static ::String KEY_UP; /* REM */ 
};

} // end namespace neash
} // end namespace events

#endif /* INCLUDED_neash_events_KeyboardEvent */ 
