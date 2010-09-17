#ifndef INCLUDED_org_casalib_events__ListenerManager_EventInfo
#define INCLUDED_org_casalib_events__ListenerManager_EventInfo

#include <hxcpp.h>

HX_DECLARE_CLASS4(org,casalib,events,_ListenerManager,EventInfo)
namespace org{
namespace casalib{
namespace events{
namespace _ListenerManager{


class EventInfo_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef EventInfo_obj OBJ_;
		EventInfo_obj();
		Void __construct(::String type,Dynamic listener,bool useCapture);

	public:
		static hx::ObjectPtr< EventInfo_obj > __new(::String type,Dynamic listener,bool useCapture);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~EventInfo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"EventInfo",9); }

		::String type; /* REM */ 
		Dynamic listener; /* REM */ 
		bool useCapture; /* REM */ 
		virtual bool equals( ::org::casalib::events::_ListenerManager::EventInfo eventInfo);
		Dynamic equals_dyn();

};

} // end namespace org
} // end namespace casalib
} // end namespace events
} // end namespace _ListenerManager

#endif /* INCLUDED_org_casalib_events__ListenerManager_EventInfo */ 
