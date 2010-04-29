#include <hxcpp.h>

#ifndef INCLUDED_org_casalib_events__ListenerManager_EventInfo
#include <org/casalib/events/_ListenerManager/EventInfo.h>
#endif
namespace org{
namespace casalib{
namespace events{
namespace _ListenerManager{

Void EventInfo_obj::__construct(::String type,Dynamic listener,bool useCapture)
{
{
	this->type = type;
	this->listener = listener;
	this->useCapture = useCapture;
}
;
	return null();
}

EventInfo_obj::~EventInfo_obj() { }

Dynamic EventInfo_obj::__CreateEmpty() { return  new EventInfo_obj; }
hx::ObjectPtr< EventInfo_obj > EventInfo_obj::__new(::String type,Dynamic listener,bool useCapture)
{  hx::ObjectPtr< EventInfo_obj > result = new EventInfo_obj();
	result->__construct(type,listener,useCapture);
	return result;}

Dynamic EventInfo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EventInfo_obj > result = new EventInfo_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

bool EventInfo_obj::equals( ::org::casalib::events::_ListenerManager::EventInfo eventInfo){
	return (bool((this->type == eventInfo->type)) && bool((bool((this->listener == eventInfo->listener)) && bool((this->useCapture == eventInfo->useCapture)))));
}


HX_DEFINE_DYNAMIC_FUNC1(EventInfo_obj,equals,return )


EventInfo_obj::EventInfo_obj()
{
}

void EventInfo_obj::__Mark()
{
	hx::MarkMember(type);
	hx::MarkMember(listener);
	hx::MarkMember(useCapture);
}

Dynamic EventInfo_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { return type; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"equals",sizeof(wchar_t)*6) ) { return equals_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"listener",sizeof(wchar_t)*8) ) { return listener; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"useCapture",sizeof(wchar_t)*10) ) { return useCapture; }
	}
	return super::__Field(inName);
}

Dynamic EventInfo_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"type",sizeof(wchar_t)*4) ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"listener",sizeof(wchar_t)*8) ) { listener=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"useCapture",sizeof(wchar_t)*10) ) { useCapture=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void EventInfo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"type",4));
	outFields->push(HX_STRING(L"listener",8));
	outFields->push(HX_STRING(L"useCapture",10));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"type",4),
	HX_STRING(L"listener",8),
	HX_STRING(L"useCapture",10),
	HX_STRING(L"equals",6),
	String(null()) };

static void sMarkStatics() {
};

Class EventInfo_obj::__mClass;

void EventInfo_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"org.casalib.events._ListenerManager.EventInfo",45), hx::TCanCast< EventInfo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void EventInfo_obj::__boot()
{
}

} // end namespace org
} // end namespace casalib
} // end namespace events
} // end namespace _ListenerManager
