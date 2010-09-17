#ifndef INCLUDED_sandy_events_EventBroadcaster
#define INCLUDED_sandy_events_EventBroadcaster

#include <hxcpp.h>

#include <neash/events/EventDispatcher.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(sandy,events,EventBroadcaster)
namespace sandy{
namespace events{


class EventBroadcaster_obj : public ::neash::events::EventDispatcher_obj{
	public:
		typedef ::neash::events::EventDispatcher_obj super;
		typedef EventBroadcaster_obj OBJ_;
		EventBroadcaster_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< EventBroadcaster_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EventBroadcaster_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"EventBroadcaster",16); }

		virtual bool dispatchEvent( ::neash::events::Event evt);
		Dynamic dispatchEvent_dyn();

};

} // end namespace sandy
} // end namespace events

#endif /* INCLUDED_sandy_events_EventBroadcaster */ 
