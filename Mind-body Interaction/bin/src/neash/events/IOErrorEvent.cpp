#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_IOErrorEvent
#include <neash/events/IOErrorEvent.h>
#endif
namespace neash{
namespace events{

Void IOErrorEvent_obj::__construct(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic __o_inText)
{
::String inText = __o_inText.Default(HX_STRING(L"",0));
{
	super::__construct(type,bubbles,cancelable);
	this->text = inText;
}
;
	return null();
}

IOErrorEvent_obj::~IOErrorEvent_obj() { }

Dynamic IOErrorEvent_obj::__CreateEmpty() { return  new IOErrorEvent_obj; }
hx::ObjectPtr< IOErrorEvent_obj > IOErrorEvent_obj::__new(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic __o_inText)
{  hx::ObjectPtr< IOErrorEvent_obj > result = new IOErrorEvent_obj();
	result->__construct(type,bubbles,cancelable,__o_inText);
	return result;}

Dynamic IOErrorEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< IOErrorEvent_obj > result = new IOErrorEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::String IOErrorEvent_obj::IO_ERROR;


IOErrorEvent_obj::IOErrorEvent_obj()
{
}

void IOErrorEvent_obj::__Mark()
{
	hx::MarkMember(text);
	super::__Mark();
}

Dynamic IOErrorEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"text",sizeof(wchar_t)*4) ) { return text; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"IO_ERROR",sizeof(wchar_t)*8) ) { return IO_ERROR; }
	}
	return super::__Field(inName);
}

Dynamic IOErrorEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"text",sizeof(wchar_t)*4) ) { text=inValue.Cast< ::String >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"IO_ERROR",sizeof(wchar_t)*8) ) { IO_ERROR=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void IOErrorEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"text",4));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"IO_ERROR",8),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"text",4),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(IOErrorEvent_obj::IO_ERROR);
};

Class IOErrorEvent_obj::__mClass;

void IOErrorEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.events.IOErrorEvent",25), hx::TCanCast< IOErrorEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void IOErrorEvent_obj::__boot()
{
	hx::Static(IO_ERROR) = HX_STRING(L"IO_ERROR",8);
}

} // end namespace neash
} // end namespace events
