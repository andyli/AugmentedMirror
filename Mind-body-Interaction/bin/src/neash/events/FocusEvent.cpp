#include <hxcpp.h>

#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_events_Event
#include <neash/events/Event.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_FocusEvent
#include <neash/events/FocusEvent.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
namespace neash{
namespace events{

Void FocusEvent_obj::__construct(::String type,Dynamic bubbles,Dynamic cancelable,::neash::display::InteractiveObject inObject,Dynamic inShiftKey,Dynamic inKeyCode)
{
{
	super::__construct(type,bubbles,cancelable);
	this->keyCode = inKeyCode;
	this->shiftKey = (inShiftKey == null()) ? Dynamic( false ) : Dynamic( inShiftKey );
	this->target = inObject;
}
;
	return null();
}

FocusEvent_obj::~FocusEvent_obj() { }

Dynamic FocusEvent_obj::__CreateEmpty() { return  new FocusEvent_obj; }
hx::ObjectPtr< FocusEvent_obj > FocusEvent_obj::__new(::String type,Dynamic bubbles,Dynamic cancelable,::neash::display::InteractiveObject inObject,Dynamic inShiftKey,Dynamic inKeyCode)
{  hx::ObjectPtr< FocusEvent_obj > result = new FocusEvent_obj();
	result->__construct(type,bubbles,cancelable,inObject,inShiftKey,inKeyCode);
	return result;}

Dynamic FocusEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FocusEvent_obj > result = new FocusEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

::String FocusEvent_obj::FOCUS_IN;

::String FocusEvent_obj::FOCUS_OUT;

::String FocusEvent_obj::KEY_FOCUS_CHANGE;

::String FocusEvent_obj::MOUSE_FOCUS_CHANGE;


FocusEvent_obj::FocusEvent_obj()
{
}

void FocusEvent_obj::__Mark()
{
	hx::MarkMember(keyCode);
	hx::MarkMember(shiftKey);
	hx::MarkMember(relatedObject);
	super::__Mark();
}

Dynamic FocusEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"keyCode",sizeof(wchar_t)*7) ) { return keyCode; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"FOCUS_IN",sizeof(wchar_t)*8) ) { return FOCUS_IN; }
		if (!memcmp(inName.__s,L"shiftKey",sizeof(wchar_t)*8) ) { return shiftKey; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"FOCUS_OUT",sizeof(wchar_t)*9) ) { return FOCUS_OUT; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"relatedObject",sizeof(wchar_t)*13) ) { return relatedObject; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"KEY_FOCUS_CHANGE",sizeof(wchar_t)*16) ) { return KEY_FOCUS_CHANGE; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"MOUSE_FOCUS_CHANGE",sizeof(wchar_t)*18) ) { return MOUSE_FOCUS_CHANGE; }
	}
	return super::__Field(inName);
}

Dynamic FocusEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"keyCode",sizeof(wchar_t)*7) ) { keyCode=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"FOCUS_IN",sizeof(wchar_t)*8) ) { FOCUS_IN=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"shiftKey",sizeof(wchar_t)*8) ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"FOCUS_OUT",sizeof(wchar_t)*9) ) { FOCUS_OUT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"relatedObject",sizeof(wchar_t)*13) ) { relatedObject=inValue.Cast< ::neash::display::InteractiveObject >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"KEY_FOCUS_CHANGE",sizeof(wchar_t)*16) ) { KEY_FOCUS_CHANGE=inValue.Cast< ::String >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"MOUSE_FOCUS_CHANGE",sizeof(wchar_t)*18) ) { MOUSE_FOCUS_CHANGE=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void FocusEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"keyCode",7));
	outFields->push(HX_STRING(L"shiftKey",8));
	outFields->push(HX_STRING(L"relatedObject",13));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"FOCUS_IN",8),
	HX_STRING(L"FOCUS_OUT",9),
	HX_STRING(L"KEY_FOCUS_CHANGE",16),
	HX_STRING(L"MOUSE_FOCUS_CHANGE",18),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"keyCode",7),
	HX_STRING(L"shiftKey",8),
	HX_STRING(L"relatedObject",13),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(FocusEvent_obj::FOCUS_IN);
	hx::MarkMember(FocusEvent_obj::FOCUS_OUT);
	hx::MarkMember(FocusEvent_obj::KEY_FOCUS_CHANGE);
	hx::MarkMember(FocusEvent_obj::MOUSE_FOCUS_CHANGE);
};

Class FocusEvent_obj::__mClass;

void FocusEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.events.FocusEvent",23), hx::TCanCast< FocusEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void FocusEvent_obj::__boot()
{
	hx::Static(FOCUS_IN) = HX_STRING(L"FOCUS_IN",8);
	hx::Static(FOCUS_OUT) = HX_STRING(L"FOCUS_OUT",9);
	hx::Static(KEY_FOCUS_CHANGE) = HX_STRING(L"KEY_FOCUS_CHANGE",16);
	hx::Static(MOUSE_FOCUS_CHANGE) = HX_STRING(L"MOUSE_FOCUS_CHANGE",18);
}

} // end namespace neash
} // end namespace events
