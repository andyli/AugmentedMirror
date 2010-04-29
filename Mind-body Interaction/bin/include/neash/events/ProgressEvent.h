#ifndef INCLUDED_neash_events_ProgressEvent
#define INCLUDED_neash_events_ProgressEvent

#include <hxcpp.h>

HX_DECLARE_CLASS2(neash,events,ProgressEvent)
namespace neash{
namespace events{


class ProgressEvent_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ProgressEvent_obj OBJ_;
		ProgressEvent_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< ProgressEvent_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~ProgressEvent_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		::String __ToString() const { return HX_STRING(L"ProgressEvent",13); }

		int bytesLoaded; /* REM */ 
		int bytesTotal; /* REM */ 
		static ::String PROGRESS; /* REM */ 
		static ::String SOCKET_DATA; /* REM */ 
};

} // end namespace neash
} // end namespace events

#endif /* INCLUDED_neash_events_ProgressEvent */ 
