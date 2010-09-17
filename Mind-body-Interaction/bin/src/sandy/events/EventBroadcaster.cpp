#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_sandy_events_EventBroadcaster
#include <sandy/events/EventBroadcaster.h>
#endif
namespace sandy{
namespace events{

Void EventBroadcaster_obj::__construct()
{
{
	super::__construct(null());
}
;
	return null();
}

EventBroadcaster_obj::~EventBroadcaster_obj() { }

Dynamic EventBroadcaster_obj::__CreateEmpty() { return  new EventBroadcaster_obj; }
hx::ObjectPtr< EventBroadcaster_obj > EventBroadcaster_obj::__new()
{  hx::ObjectPtr< EventBroadcaster_obj > result = new EventBroadcaster_obj();
	result->__construct();
	return result;}

Dynamic EventBroadcaster_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventBroadcaster_obj > result = new EventBroadcaster_obj();
	result->__construct();
	return result;}

bool EventBroadcaster_obj::dispatchEvent( ::neash::events::Event evt){
	__SAFE_POINT
	if ((bool(this->hasEventListener(evt->type)) || bool(evt->bubbles))){
		return this->super::dispatchEvent(evt);
	}
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(EventBroadcaster_obj,dispatchEvent,return )


EventBroadcaster_obj::EventBroadcaster_obj()
{
}

void EventBroadcaster_obj::__Mark()
{
	super::__Mark();
}

Dynamic EventBroadcaster_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 13:
		if (!memcmp(inName.__s,L"dispatchEvent",sizeof(wchar_t)*13) ) { return dispatchEvent_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic EventBroadcaster_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void EventBroadcaster_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"dispatchEvent",13),
	String(null()) };

static void sMarkStatics() {
};

Class EventBroadcaster_obj::__mClass;

void EventBroadcaster_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.events.EventBroadcaster",29), hx::TCanCast< EventBroadcaster_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EventBroadcaster_obj::__boot()
{
}

} // end namespace sandy
} // end namespace events
