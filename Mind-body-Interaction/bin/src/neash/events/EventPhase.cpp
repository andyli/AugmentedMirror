#include <hxcpp.h>

#ifndef INCLUDED_neash_events_EventPhase
#include <neash/events/EventPhase.h>
#endif
namespace neash{
namespace events{

Void EventPhase_obj::__construct()
{
	return null();
}

EventPhase_obj::~EventPhase_obj() { }

Dynamic EventPhase_obj::__CreateEmpty() { return  new EventPhase_obj; }
hx::ObjectPtr< EventPhase_obj > EventPhase_obj::__new()
{  hx::ObjectPtr< EventPhase_obj > result = new EventPhase_obj();
	result->__construct();
	return result;}

Dynamic EventPhase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventPhase_obj > result = new EventPhase_obj();
	result->__construct();
	return result;}

int EventPhase_obj::CAPTURING_PHASE;

int EventPhase_obj::AT_TARGET;

int EventPhase_obj::BUBBLING_PHASE;


EventPhase_obj::EventPhase_obj()
{
}

void EventPhase_obj::__Mark()
{
}

Dynamic EventPhase_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"AT_TARGET",sizeof(wchar_t)*9) ) { return AT_TARGET; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"BUBBLING_PHASE",sizeof(wchar_t)*14) ) { return BUBBLING_PHASE; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"CAPTURING_PHASE",sizeof(wchar_t)*15) ) { return CAPTURING_PHASE; }
	}
	return super::__Field(inName);
}

Dynamic EventPhase_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"AT_TARGET",sizeof(wchar_t)*9) ) { AT_TARGET=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"BUBBLING_PHASE",sizeof(wchar_t)*14) ) { BUBBLING_PHASE=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"CAPTURING_PHASE",sizeof(wchar_t)*15) ) { CAPTURING_PHASE=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void EventPhase_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"CAPTURING_PHASE",15),
	HX_STRING(L"AT_TARGET",9),
	HX_STRING(L"BUBBLING_PHASE",14),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(EventPhase_obj::CAPTURING_PHASE);
	hx::MarkMember(EventPhase_obj::AT_TARGET);
	hx::MarkMember(EventPhase_obj::BUBBLING_PHASE);
};

Class EventPhase_obj::__mClass;

void EventPhase_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.events.EventPhase",23), hx::TCanCast< EventPhase_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EventPhase_obj::__boot()
{
	hx::Static(CAPTURING_PHASE) = 0;
	hx::Static(AT_TARGET) = 1;
	hx::Static(BUBBLING_PHASE) = 2;
}

} // end namespace neash
} // end namespace events
