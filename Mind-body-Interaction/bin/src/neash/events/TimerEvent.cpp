#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_TimerEvent
#include <neash/events/TimerEvent.h>
#endif
namespace neash{
namespace events{

Void TimerEvent_obj::__construct(::String type,Dynamic bubbles,Dynamic cancelable)
{
{
	super::__construct(type,bubbles,cancelable);
}
;
	return null();
}

TimerEvent_obj::~TimerEvent_obj() { }

Dynamic TimerEvent_obj::__CreateEmpty() { return  new TimerEvent_obj; }
hx::ObjectPtr< TimerEvent_obj > TimerEvent_obj::__new(::String type,Dynamic bubbles,Dynamic cancelable)
{  hx::ObjectPtr< TimerEvent_obj > result = new TimerEvent_obj();
	result->__construct(type,bubbles,cancelable);
	return result;}

Dynamic TimerEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TimerEvent_obj > result = new TimerEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void TimerEvent_obj::updateAfterEvent( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TimerEvent_obj,updateAfterEvent,(void))

::String TimerEvent_obj::TIMER;

::String TimerEvent_obj::TIMER_COMPLETE;


TimerEvent_obj::TimerEvent_obj()
{
}

void TimerEvent_obj::__Mark()
{
	super::__Mark();
}

Dynamic TimerEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"TIMER",sizeof(wchar_t)*5) ) { return TIMER; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"TIMER_COMPLETE",sizeof(wchar_t)*14) ) { return TIMER_COMPLETE; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"updateAfterEvent",sizeof(wchar_t)*16) ) { return updateAfterEvent_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic TimerEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"TIMER",sizeof(wchar_t)*5) ) { TIMER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"TIMER_COMPLETE",sizeof(wchar_t)*14) ) { TIMER_COMPLETE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void TimerEvent_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"TIMER",5),
	HX_STRING(L"TIMER_COMPLETE",14),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"updateAfterEvent",16),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(TimerEvent_obj::TIMER);
	hx::MarkMember(TimerEvent_obj::TIMER_COMPLETE);
};

Class TimerEvent_obj::__mClass;

void TimerEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.events.TimerEvent",23), hx::TCanCast< TimerEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void TimerEvent_obj::__boot()
{
	hx::Static(TIMER) = HX_STRING(L"timer",5);
	hx::Static(TIMER_COMPLETE) = HX_STRING(L"timerComplete",13);
}

} // end namespace neash
} // end namespace events
