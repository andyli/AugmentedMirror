#ifndef INCLUDED_neash_events_IOErrorEvent
#define INCLUDED_neash_events_IOErrorEvent

#include <hxcpp.h>

#include <neash/events/Event.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,IOErrorEvent)
namespace neash{
namespace events{


class IOErrorEvent_obj : public ::neash::events::Event_obj{
	public:
		typedef ::neash::events::Event_obj super;
		typedef IOErrorEvent_obj OBJ_;
		IOErrorEvent_obj();
		Void __construct(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic __o_inText);

	public:
		static hx::ObjectPtr< IOErrorEvent_obj > __new(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic __o_inText);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~IOErrorEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"IOErrorEvent",12); }

		::String text; /* REM */ 
		static ::String IO_ERROR; /* REM */ 
};

} // end namespace neash
} // end namespace events

#endif /* INCLUDED_neash_events_IOErrorEvent */ 
