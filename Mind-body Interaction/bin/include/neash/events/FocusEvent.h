#ifndef INCLUDED_neash_events_FocusEvent
#define INCLUDED_neash_events_FocusEvent

#include <hxcpp.h>

#include <neash/events/Event.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,FocusEvent)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
namespace neash{
namespace events{


class FocusEvent_obj : public ::neash::events::Event_obj{
	public:
		typedef ::neash::events::Event_obj super;
		typedef FocusEvent_obj OBJ_;
		FocusEvent_obj();
		Void __construct(::String type,Dynamic bubbles,Dynamic cancelable,::neash::display::InteractiveObject inObject,Dynamic inShiftKey,Dynamic inKeyCode);

	public:
		static hx::ObjectPtr< FocusEvent_obj > __new(::String type,Dynamic bubbles,Dynamic cancelable,::neash::display::InteractiveObject inObject,Dynamic inShiftKey,Dynamic inKeyCode);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FocusEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"FocusEvent",10); }

		int keyCode; /* REM */ 
		bool shiftKey; /* REM */ 
		::neash::display::InteractiveObject relatedObject; /* REM */ 
		static ::String FOCUS_IN; /* REM */ 
		static ::String FOCUS_OUT; /* REM */ 
		static ::String KEY_FOCUS_CHANGE; /* REM */ 
		static ::String MOUSE_FOCUS_CHANGE; /* REM */ 
};

} // end namespace neash
} // end namespace events

#endif /* INCLUDED_neash_events_FocusEvent */ 
