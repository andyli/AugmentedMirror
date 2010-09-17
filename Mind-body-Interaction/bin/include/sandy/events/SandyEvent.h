#ifndef INCLUDED_sandy_events_SandyEvent
#define INCLUDED_sandy_events_SandyEvent

#include <hxcpp.h>

#include <neash/events/Event.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(sandy,events,SandyEvent)
namespace sandy{
namespace events{


class SandyEvent_obj : public ::neash::events::Event_obj{
	public:
		typedef ::neash::events::Event_obj super;
		typedef SandyEvent_obj OBJ_;
		SandyEvent_obj();
		Void __construct(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable);

	public:
		static hx::ObjectPtr< SandyEvent_obj > __new(::String type,Dynamic __o_bubbles,Dynamic __o_cancelable);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SandyEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"SandyEvent",10); }

		virtual ::neash::events::Event clone( );
		Dynamic clone_dyn();

		static ::String LIGHT_ADDED; /* REM */ 
		static ::String LIGHT_UPDATED; /* REM */ 
		static ::String LIGHT_COLOR_CHANGED; /* REM */ 
		static ::String SCENE_RENDER; /* REM */ 
		static ::String SCENE_RENDER_FINISH; /* REM */ 
		static ::String SCENE_CULL; /* REM */ 
		static ::String SCENE_UPDATE; /* REM */ 
		static ::String SCENE_RENDER_DISPLAYLIST; /* REM */ 
		static ::String CONTAINER_CREATED; /* REM */ 
		static ::String QUEUE_COMPLETE; /* REM */ 
		static ::String QUEUE_LOADER_ERROR; /* REM */ 
};

} // end namespace sandy
} // end namespace events

#endif /* INCLUDED_sandy_events_SandyEvent */ 
