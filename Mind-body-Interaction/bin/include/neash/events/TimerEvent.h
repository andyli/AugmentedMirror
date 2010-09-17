#ifndef INCLUDED_neash_events_TimerEvent
#define INCLUDED_neash_events_TimerEvent

#include <hxcpp.h>

#include <neash/events/Event.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,TimerEvent)
namespace neash{
namespace events{


class TimerEvent_obj : public ::neash::events::Event_obj{
	public:
		typedef ::neash::events::Event_obj super;
		typedef TimerEvent_obj OBJ_;
		TimerEvent_obj();
		Void __construct(::String type,Dynamic bubbles,Dynamic cancelable);

	public:
		static hx::ObjectPtr< TimerEvent_obj > __new(::String type,Dynamic bubbles,Dynamic cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TimerEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"TimerEvent",10); }

		virtual Void updateAfterEvent( );
		Dynamic updateAfterEvent_dyn();

		static ::String TIMER; /* REM */ 
		static ::String TIMER_COMPLETE; /* REM */ 
};

} // end namespace neash
} // end namespace events

#endif /* INCLUDED_neash_events_TimerEvent */ 
