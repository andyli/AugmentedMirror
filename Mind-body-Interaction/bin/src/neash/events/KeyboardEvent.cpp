#include <hxcpp.h>

#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_KeyboardEvent
#include <neash/events/KeyboardEvent.h>
#endif
namespace neash{
namespace events{

Void KeyboardEvent_obj::__construct(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic inCharCode,Dynamic inKeyCode,Dynamic inKeyLocation,Dynamic inCtrlKey,Dynamic inAltKey,Dynamic inShiftKey)
{
{
	super::__construct(type,bubbles,cancelable);
	this->keyCode = inKeyCode;
	this->keyLocation = (inKeyLocation == null()) ? Dynamic( 0 ) : Dynamic( inKeyLocation );
	this->charCode = (inCharCode == null()) ? Dynamic( 0 ) : Dynamic( inCharCode );
	this->shiftKey = (inShiftKey == null()) ? Dynamic( false ) : Dynamic( inShiftKey );
	this->altKey = (inAltKey == null()) ? Dynamic( false ) : Dynamic( inAltKey );
	this->ctrlKey = (inCtrlKey == null()) ? Dynamic( false ) : Dynamic( inCtrlKey );
}
;
	return null();
}

KeyboardEvent_obj::~KeyboardEvent_obj() { }

Dynamic KeyboardEvent_obj::__CreateEmpty() { return  new KeyboardEvent_obj; }
hx::ObjectPtr< KeyboardEvent_obj > KeyboardEvent_obj::__new(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic inCharCode,Dynamic inKeyCode,Dynamic inKeyLocation,Dynamic inCtrlKey,Dynamic inAltKey,Dynamic inShiftKey)
{  hx::ObjectPtr< KeyboardEvent_obj > result = new KeyboardEvent_obj();
	result->__construct(type,bubbles,cancelable,inCharCode,inKeyCode,inKeyLocation,inCtrlKey,inAltKey,inShiftKey);
	return result;}

Dynamic KeyboardEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KeyboardEvent_obj > result = new KeyboardEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8]);
	return result;}

::String KeyboardEvent_obj::KEY_DOWN;

::String KeyboardEvent_obj::KEY_UP;


KeyboardEvent_obj::KeyboardEvent_obj()
{
}

void KeyboardEvent_obj::__Mark()
{
	hx::MarkMember(keyCode);
	hx::MarkMember(charCode);
	hx::MarkMember(keyLocation);
	hx::MarkMember(ctrlKey);
	hx::MarkMember(altKey);
	hx::MarkMember(shiftKey);
	super::__Mark();
}

Dynamic KeyboardEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"KEY_UP",sizeof(wchar_t)*6) ) { return KEY_UP; }
		if (!memcmp(inName.__s,L"altKey",sizeof(wchar_t)*6) ) { return altKey; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"keyCode",sizeof(wchar_t)*7) ) { return keyCode; }
		if (!memcmp(inName.__s,L"ctrlKey",sizeof(wchar_t)*7) ) { return ctrlKey; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"KEY_DOWN",sizeof(wchar_t)*8) ) { return KEY_DOWN; }
		if (!memcmp(inName.__s,L"charCode",sizeof(wchar_t)*8) ) { return charCode; }
		if (!memcmp(inName.__s,L"shiftKey",sizeof(wchar_t)*8) ) { return shiftKey; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"keyLocation",sizeof(wchar_t)*11) ) { return keyLocation; }
	}
	return super::__Field(inName);
}

Dynamic KeyboardEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"KEY_UP",sizeof(wchar_t)*6) ) { KEY_UP=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"altKey",sizeof(wchar_t)*6) ) { altKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"keyCode",sizeof(wchar_t)*7) ) { keyCode=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"ctrlKey",sizeof(wchar_t)*7) ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"KEY_DOWN",sizeof(wchar_t)*8) ) { KEY_DOWN=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"charCode",sizeof(wchar_t)*8) ) { charCode=inValue.Cast< int >(); return inValue; }
		if (!memcmp(inName.__s,L"shiftKey",sizeof(wchar_t)*8) ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"keyLocation",sizeof(wchar_t)*11) ) { keyLocation=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void KeyboardEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"keyCode",7));
	outFields->push(HX_STRING(L"charCode",8));
	outFields->push(HX_STRING(L"keyLocation",11));
	outFields->push(HX_STRING(L"ctrlKey",7));
	outFields->push(HX_STRING(L"altKey",6));
	outFields->push(HX_STRING(L"shiftKey",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"KEY_DOWN",8),
	HX_STRING(L"KEY_UP",6),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"keyCode",7),
	HX_STRING(L"charCode",8),
	HX_STRING(L"keyLocation",11),
	HX_STRING(L"ctrlKey",7),
	HX_STRING(L"altKey",6),
	HX_STRING(L"shiftKey",8),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(KeyboardEvent_obj::KEY_DOWN);
	hx::MarkMember(KeyboardEvent_obj::KEY_UP);
};

Class KeyboardEvent_obj::__mClass;

void KeyboardEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.events.KeyboardEvent",26), hx::TCanCast< KeyboardEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void KeyboardEvent_obj::__boot()
{
	hx::Static(KEY_DOWN) = HX_STRING(L"KEY_DOWN",8);
	hx::Static(KEY_UP) = HX_STRING(L"KEY_UP",6);
}

} // end namespace neash
} // end namespace events
