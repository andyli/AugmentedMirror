#ifndef INCLUDED_sandy_events_BubbleEvent
#define INCLUDED_sandy_events_BubbleEvent

#include <hxcpp.h>

#include <neash/events/Event.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(sandy,events,BubbleEvent)
namespace sandy{
namespace events{


class BubbleEvent_obj : public ::neash::events::Event_obj{
	public:
		typedef ::neash::events::Event_obj super;
		typedef BubbleEvent_obj OBJ_;
		BubbleEvent_obj();
		Void __construct(::String e,Dynamic oT,Dynamic p_Info);

	public:
		static hx::ObjectPtr< BubbleEvent_obj > __new(::String e,Dynamic oT,Dynamic p_Info);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BubbleEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"BubbleEvent",11); }

		Dynamic info; /* REM */ 
		Dynamic object; /* REM */ 
		Dynamic m_oTarget; /* REM */ 
		virtual Dynamic __getObject( );
		Dynamic __getObject_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

};

} // end namespace sandy
} // end namespace events

#endif /* INCLUDED_sandy_events_BubbleEvent */ 
