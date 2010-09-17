#ifndef INCLUDED_org_casalib_events_ListenerManager
#define INCLUDED_org_casalib_events_ListenerManager

#include <hxcpp.h>

#include <org/casalib/core/Destroyable.h>
#include <org/casalib/events/IRemovableEventDispatcher.h>
HX_DECLARE_CLASS2(neash,events,Event)
HX_DECLARE_CLASS2(neash,events,IEventDispatcher)
HX_DECLARE_CLASS3(org,casalib,core,Destroyable)
HX_DECLARE_CLASS3(org,casalib,core,IDestroyable)
HX_DECLARE_CLASS3(org,casalib,events,IRemovableEventDispatcher)
HX_DECLARE_CLASS3(org,casalib,events,ListenerManager)
HX_DECLARE_CLASS4(org,casalib,events,_ListenerManager,EventInfo)
namespace org{
namespace casalib{
namespace events{


class ListenerManager_obj : public ::org::casalib::core::Destroyable_obj{
	public:
		typedef ::org::casalib::core::Destroyable_obj super;
		typedef ListenerManager_obj OBJ_;
		ListenerManager_obj();
		Void __construct(::neash::events::IEventDispatcher dispatcher);

	public:
		static hx::ObjectPtr< ListenerManager_obj > __new(::neash::events::IEventDispatcher dispatcher);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ListenerManager_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		inline operator ::org::casalib::events::IRemovableEventDispatcher_obj *()
			{ return new ::org::casalib::events::IRemovableEventDispatcher_delegate_< ListenerManager_obj >(this); }
		hx::Object *__ToInterface(const type_info &inType);
		::String __ToString() const { return HX_STRING(L"ListenerManager",15); }

		::neash::events::IEventDispatcher _eventDispatcher; /* REM */ 
		Array< ::org::casalib::events::_ListenerManager::EventInfo > _events; /* REM */ 
		bool _blockRequest; /* REM */ 
		virtual int addEventListener( ::String type,Dynamic listener,Dynamic useCapture,Dynamic priority,Dynamic useWeakReference);
		Dynamic addEventListener_dyn();

		virtual bool dispatchEvent( ::neash::events::Event event);
		Dynamic dispatchEvent_dyn();

		virtual bool hasEventListener( ::String type);
		Dynamic hasEventListener_dyn();

		virtual bool willTrigger( ::String type);
		Dynamic willTrigger_dyn();

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

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual Void RemoveByID( ::String inType,int inID);
		Dynamic RemoveByID_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace events

#endif /* INCLUDED_org_casalib_events_ListenerManager */ 
