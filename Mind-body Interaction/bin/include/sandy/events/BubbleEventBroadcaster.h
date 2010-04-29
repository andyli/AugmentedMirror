#ifndef INCLUDED_sandy_events_BubbleEventBroadcaster
#define INCLUDED_sandy_events_BubbleEventBroadcaster

#include <hxcpp.h>

#include <sandy/events/EventBroadcaster.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS2(sandy,events,BubbleEventBroadcaster)
HX_DECLARE_CLASS2(sandy,events,EventBroadcaster)
namespace sandy{
namespace events{


class BubbleEventBroadcaster_obj : public ::sandy::events::EventBroadcaster_obj{
	public:
		typedef ::sandy::events::EventBroadcaster_obj super;
		typedef BubbleEventBroadcaster_obj OBJ_;
		BubbleEventBroadcaster_obj();
		Void __construct(Dynamic p_oTarget);

	public:
		static hx::ObjectPtr< BubbleEventBroadcaster_obj > __new(Dynamic p_oTarget);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BubbleEventBroadcaster_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"BubbleEventBroadcaster",22); }

		::sandy::events::BubbleEventBroadcaster m_oParent; /* REM */ 
		Dynamic m_oTarget; /* REM */ 
		virtual Void addChild( ::sandy::events::BubbleEventBroadcaster child);
		Dynamic addChild_dyn();

		virtual Void removeChild( ::sandy::events::BubbleEventBroadcaster child);
		Dynamic removeChild_dyn();

		::sandy::events::BubbleEventBroadcaster parent; /* REM */ 
		virtual ::sandy::events::BubbleEventBroadcaster __getParent( );
		Dynamic __getParent_dyn();

		virtual ::sandy::events::BubbleEventBroadcaster __setParent( ::sandy::events::BubbleEventBroadcaster pEB);
		Dynamic __setParent_dyn();

		virtual bool dispatchEvent( ::neash::events::Event e);
		Dynamic dispatchEvent_dyn();

};

} // end namespace sandy
} // end namespace events

#endif /* INCLUDED_sandy_events_BubbleEventBroadcaster */ 
