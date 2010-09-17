#include <hxcpp.h>

#ifndef INCLUDED_neash_events_ProgressEvent
#include <neash/events/ProgressEvent.h>
#endif
namespace neash{
namespace events{

Void ProgressEvent_obj::__construct()
{
	return null();
}

ProgressEvent_obj::~ProgressEvent_obj() { }

Dynamic ProgressEvent_obj::__CreateEmpty() { return  new ProgressEvent_obj; }
hx::ObjectPtr< ProgressEvent_obj > ProgressEvent_obj::__new()
{  hx::ObjectPtr< ProgressEvent_obj > result = new ProgressEvent_obj();
	result->__construct();
	return result;}

Dynamic ProgressEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ProgressEvent_obj > result = new ProgressEvent_obj();
	result->__construct();
	return result;}

::String ProgressEvent_obj::PROGRESS;

::String ProgressEvent_obj::SOCKET_DATA;


ProgressEvent_obj::ProgressEvent_obj()
{
}

void ProgressEvent_obj::__Mark()
{
	hx::MarkMember(bytesLoaded);
	hx::MarkMember(bytesTotal);
}

Dynamic ProgressEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"PROGRESS",sizeof(wchar_t)*8) ) { return PROGRESS; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"bytesTotal",sizeof(wchar_t)*10) ) { return bytesTotal; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"SOCKET_DATA",sizeof(wchar_t)*11) ) { return SOCKET_DATA; }
		if (!memcmp(inName.__s,L"bytesLoaded",sizeof(wchar_t)*11) ) { return bytesLoaded; }
	}
	return super::__Field(inName);
}

Dynamic ProgressEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"PROGRESS",sizeof(wchar_t)*8) ) { PROGRESS=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"bytesTotal",sizeof(wchar_t)*10) ) { bytesTotal=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"SOCKET_DATA",sizeof(wchar_t)*11) ) { SOCKET_DATA=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"bytesLoaded",sizeof(wchar_t)*11) ) { bytesLoaded=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void ProgressEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"bytesLoaded",11));
	outFields->push(HX_STRING(L"bytesTotal",10));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"PROGRESS",8),
	HX_STRING(L"SOCKET_DATA",11),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"bytesLoaded",11),
	HX_STRING(L"bytesTotal",10),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(ProgressEvent_obj::PROGRESS);
	hx::MarkMember(ProgressEvent_obj::SOCKET_DATA);
};

Class ProgressEvent_obj::__mClass;

void ProgressEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.events.ProgressEvent",26), hx::TCanCast< ProgressEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void ProgressEvent_obj::__boot()
{
	hx::Static(PROGRESS) = HX_STRING(L"progress",8);
	hx::Static(SOCKET_DATA) = HX_STRING(L"socketData",10);
}

} // end namespace neash
} // end namespace events
