#ifndef INCLUDED_neash_events_MouseEvent
#define INCLUDED_neash_events_MouseEvent

#include <hxcpp.h>

#include <neash/events/Event.h>
HX_DECLARE_CLASS2(neash,display,DisplayObject)
HX_DECLARE_CLASS2(neash,display,InteractiveObject)
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(neash,events,MouseEvent)
HX_DECLARE_CLASS2(nme,display,IBitmapDrawable)
namespace neash{
namespace events{


class MouseEvent_obj : public ::neash::events::Event_obj{
	public:
		typedef ::neash::events::Event_obj super;
		typedef MouseEvent_obj OBJ_;
		MouseEvent_obj();
		Void __construct(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic in_localX,Dynamic in_localY,::neash::display::InteractiveObject in_relatedObject,Dynamic in_ctrlKey,Dynamic in_altKey,Dynamic in_shiftKey,Dynamic in_buttonDown,Dynamic in_delta);

	public:
		static hx::ObjectPtr< MouseEvent_obj > __new(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic in_localX,Dynamic in_localY,::neash::display::InteractiveObject in_relatedObject,Dynamic in_ctrlKey,Dynamic in_altKey,Dynamic in_shiftKey,Dynamic in_buttonDown,Dynamic in_delta);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MouseEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"MouseEvent",10); }

		bool altKey; /* REM */ 
		bool buttonDown; /* REM */ 
		bool ctrlKey; /* REM */ 
		int delta; /* REM */ 
		double localX; /* REM */ 
		double localY; /* REM */ 
		::neash::display::InteractiveObject relatedObject; /* REM */ 
		bool shiftKey; /* REM */ 
		double stageX; /* REM */ 
		double stageY; /* REM */ 
		virtual Void updateAfterEvent( );
		Dynamic updateAfterEvent_dyn();

		static ::String CLICK; /* REM */ 
		static ::String DOUBLE_CLICK; /* REM */ 
		static ::String MOUSE_DOWN; /* REM */ 
		static ::String MOUSE_MOVE; /* REM */ 
		static ::String MOUSE_OUT; /* REM */ 
		static ::String MOUSE_OVER; /* REM */ 
		static ::String MOUSE_UP; /* REM */ 
		static ::String MOUSE_WHEEL; /* REM */ 
		static ::String ROLL_OUT; /* REM */ 
		static ::String ROLL_OVER; /* REM */ 
};

} // end namespace neash
} // end namespace events

#endif /* INCLUDED_neash_events_MouseEvent */ 
