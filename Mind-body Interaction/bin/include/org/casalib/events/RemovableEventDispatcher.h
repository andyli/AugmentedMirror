#ifndef INCLUDED_org_casalib_events_RemovableEventDispatcher
#define INCLUDED_org_casalib_events_RemovableEventDispatcher

#include <hxcpp.h>

#include <neash/events/EventDispatcher.h>
#include <org/casalib/core/IDestroyable.h>
#include <org/casalib/events/IRemovableEventDispatcher.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,EventDispatcher)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS3(org,casalib,core,Destroyable)
HX_DECLARE_CLASS3(org,casalib,core,IDestroyable)
HX_DECLARE_CLASS3(org,casalib,events,IRemovableEventDispatcher)
HX_DECLARE_CLASS3(org,casalib,events,ListenerManager)
HX_DECLARE_CLASS3(org,casalib,events,RemovableEventDispatcher)
namespace org{
namespace casalib{
namespace events{


class RemovableEventDispatcher_obj : public ::neash::events::EventDispatcher_obj{
	public:
		typedef ::neash::events::EventDispatcher_obj super;
		typedef RemovableEventDispatcher_obj OBJ_;
		RemovableEventDispatcher_obj();
		Void __construct(::neash::events::IEventDispatcher target);

	public:
		static hx::ObjectPtr< RemovableEventDispatcher_obj > __new(::neash::events::IEventDispatcher target);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~RemovableEventDispatcher_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::org::casalib::core::IDestroyable_obj *()
			{ return new ::org::casalib::core::IDestroyable_delegate_< RemovableEventDispatcher_obj >(this); }
		inline operator ::org::casalib::events::IRemovableEventDispatcher_obj *()
			{ return new ::org::casalib::events::IRemovableEventDispatcher_delegate_< RemovableEventDispatcher_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"RemovableEventDispatcher",24); }

		bool destroyed; /* REM */ 
		::org::casalib::events::ListenerManager _listenerManager; /* REM */ 
		bool _isDestroyed; /* REM */ 
		virtual bool dispatchEvent( ::neash::events::Event event);
		Dynamic dispatchEvent_dyn();

		virtual int addEventListener( ::String type,Dynamic listener,Dynamic useCapture,Dynamic priority,Dynamic useWeakReference);
		Dynamic addEventListener_dyn();

		virtual Void removeEventListener( ::String type,Dynamic listener,Dynamic useCapture);
		Dynamic removeEventListener_dyn();

		virtual Void removeEventsForType( ::String type);
		Dynamic removeEventsForType_dyn();

		virtual Void removeEventsForListener( Dynamic listener);
		Dynamic removeEventsForListener_dyn();

		virtual Void removeEventListeners( );
		Dynamic removeEventListeners_dyn();

		virtual int getTotalEventListeners( ::String type);
		Dynamic getTotalEventListeners_dyn();

		virtual bool getDestroyed( );
		Dynamic getDestroyed_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace events

#endif /* INCLUDED_org_casalib_events_RemovableEventDispatcher */ 
