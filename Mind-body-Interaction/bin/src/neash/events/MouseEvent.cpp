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
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_MouseEvent
#include <neash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
namespace neash{
namespace events{

Void MouseEvent_obj::__construct(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic in_localX,Dynamic in_localY,::neash::display::InteractiveObject in_relatedObject,Dynamic in_ctrlKey,Dynamic in_altKey,Dynamic in_shiftKey,Dynamic in_buttonDown,Dynamic in_delta)
{
{
	super::__construct(type,bubbles,cancelable);
	this->shiftKey = (in_shiftKey == null()) ? Dynamic( false ) : Dynamic( in_shiftKey );
	this->altKey = (in_altKey == null()) ? Dynamic( false ) : Dynamic( in_altKey );
	this->ctrlKey = (in_ctrlKey == null()) ? Dynamic( false ) : Dynamic( in_ctrlKey );
	bubbles = (in_buttonDown == null()) ? Dynamic( false ) : Dynamic( in_buttonDown );
	this->relatedObject = in_relatedObject;
	this->delta = (in_delta == null()) ? Dynamic( 0 ) : Dynamic( in_delta );
	this->localX = (in_localX == null()) ? Dynamic( 0 ) : Dynamic( in_localX );
	this->localY = (in_localY == null()) ? Dynamic( 0 ) : Dynamic( in_localY );
	this->buttonDown = (in_buttonDown == null()) ? Dynamic( false ) : Dynamic( in_buttonDown );
}
;
	return null();
}

MouseEvent_obj::~MouseEvent_obj() { }

Dynamic MouseEvent_obj::__CreateEmpty() { return  new MouseEvent_obj; }
hx::ObjectPtr< MouseEvent_obj > MouseEvent_obj::__new(::String type,Dynamic bubbles,Dynamic cancelable,Dynamic in_localX,Dynamic in_localY,::neash::display::InteractiveObject in_relatedObject,Dynamic in_ctrlKey,Dynamic in_altKey,Dynamic in_shiftKey,Dynamic in_buttonDown,Dynamic in_delta)
{  hx::ObjectPtr< MouseEvent_obj > result = new MouseEvent_obj();
	result->__construct(type,bubbles,cancelable,in_localX,in_localY,in_relatedObject,in_ctrlKey,in_altKey,in_shiftKey,in_buttonDown,in_delta);
	return result;}

Dynamic MouseEvent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MouseEvent_obj > result = new MouseEvent_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10]);
	return result;}

Void MouseEvent_obj::updateAfterEvent( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MouseEvent_obj,updateAfterEvent,(void))

::String MouseEvent_obj::CLICK;

::String MouseEvent_obj::DOUBLE_CLICK;

::String MouseEvent_obj::MOUSE_DOWN;

::String MouseEvent_obj::MOUSE_MOVE;

::String MouseEvent_obj::MOUSE_OUT;

::String MouseEvent_obj::MOUSE_OVER;

::String MouseEvent_obj::MOUSE_UP;

::String MouseEvent_obj::MOUSE_WHEEL;

::String MouseEvent_obj::ROLL_OUT;

::String MouseEvent_obj::ROLL_OVER;


MouseEvent_obj::MouseEvent_obj()
{
}

void MouseEvent_obj::__Mark()
{
	hx::MarkMember(altKey);
	hx::MarkMember(buttonDown);
	hx::MarkMember(ctrlKey);
	hx::MarkMember(delta);
	hx::MarkMember(localX);
	hx::MarkMember(localY);
	hx::MarkMember(relatedObject);
	hx::MarkMember(shiftKey);
	hx::MarkMember(stageX);
	hx::MarkMember(stageY);
	super::__Mark();
}

Dynamic MouseEvent_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"CLICK",sizeof(wchar_t)*5) ) { return CLICK; }
		if (!memcmp(inName.__s,L"delta",sizeof(wchar_t)*5) ) { return delta; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"altKey",sizeof(wchar_t)*6) ) { return altKey; }
		if (!memcmp(inName.__s,L"localX",sizeof(wchar_t)*6) ) { return localX; }
		if (!memcmp(inName.__s,L"localY",sizeof(wchar_t)*6) ) { return localY; }
		if (!memcmp(inName.__s,L"stageX",sizeof(wchar_t)*6) ) { return stageX; }
		if (!memcmp(inName.__s,L"stageY",sizeof(wchar_t)*6) ) { return stageY; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"ctrlKey",sizeof(wchar_t)*7) ) { return ctrlKey; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"MOUSE_UP",sizeof(wchar_t)*8) ) { return MOUSE_UP; }
		if (!memcmp(inName.__s,L"ROLL_OUT",sizeof(wchar_t)*8) ) { return ROLL_OUT; }
		if (!memcmp(inName.__s,L"shiftKey",sizeof(wchar_t)*8) ) { return shiftKey; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"MOUSE_OUT",sizeof(wchar_t)*9) ) { return MOUSE_OUT; }
		if (!memcmp(inName.__s,L"ROLL_OVER",sizeof(wchar_t)*9) ) { return ROLL_OVER; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"MOUSE_DOWN",sizeof(wchar_t)*10) ) { return MOUSE_DOWN; }
		if (!memcmp(inName.__s,L"MOUSE_MOVE",sizeof(wchar_t)*10) ) { return MOUSE_MOVE; }
		if (!memcmp(inName.__s,L"MOUSE_OVER",sizeof(wchar_t)*10) ) { return MOUSE_OVER; }
		if (!memcmp(inName.__s,L"buttonDown",sizeof(wchar_t)*10) ) { return buttonDown; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"MOUSE_WHEEL",sizeof(wchar_t)*11) ) { return MOUSE_WHEEL; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"DOUBLE_CLICK",sizeof(wchar_t)*12) ) { return DOUBLE_CLICK; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"relatedObject",sizeof(wchar_t)*13) ) { return relatedObject; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"updateAfterEvent",sizeof(wchar_t)*16) ) { return updateAfterEvent_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic MouseEvent_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"CLICK",sizeof(wchar_t)*5) ) { CLICK=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"delta",sizeof(wchar_t)*5) ) { delta=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"altKey",sizeof(wchar_t)*6) ) { altKey=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"localX",sizeof(wchar_t)*6) ) { localX=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"localY",sizeof(wchar_t)*6) ) { localY=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"stageX",sizeof(wchar_t)*6) ) { stageX=inValue.Cast< double >(); return inValue; }
		if (!memcmp(inName.__s,L"stageY",sizeof(wchar_t)*6) ) { stageY=inValue.Cast< double >(); return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"ctrlKey",sizeof(wchar_t)*7) ) { ctrlKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"MOUSE_UP",sizeof(wchar_t)*8) ) { MOUSE_UP=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"ROLL_OUT",sizeof(wchar_t)*8) ) { ROLL_OUT=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"shiftKey",sizeof(wchar_t)*8) ) { shiftKey=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"MOUSE_OUT",sizeof(wchar_t)*9) ) { MOUSE_OUT=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"ROLL_OVER",sizeof(wchar_t)*9) ) { ROLL_OVER=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"MOUSE_DOWN",sizeof(wchar_t)*10) ) { MOUSE_DOWN=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"MOUSE_MOVE",sizeof(wchar_t)*10) ) { MOUSE_MOVE=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"MOUSE_OVER",sizeof(wchar_t)*10) ) { MOUSE_OVER=inValue.Cast< ::String >(); return inValue; }
		if (!memcmp(inName.__s,L"buttonDown",sizeof(wchar_t)*10) ) { buttonDown=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"MOUSE_WHEEL",sizeof(wchar_t)*11) ) { MOUSE_WHEEL=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"DOUBLE_CLICK",sizeof(wchar_t)*12) ) { DOUBLE_CLICK=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"relatedObject",sizeof(wchar_t)*13) ) { relatedObject=inValue.Cast< ::neash::display::InteractiveObject >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void MouseEvent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"altKey",6));
	outFields->push(HX_STRING(L"buttonDown",10));
	outFields->push(HX_STRING(L"ctrlKey",7));
	outFields->push(HX_STRING(L"delta",5));
	outFields->push(HX_STRING(L"localX",6));
	outFields->push(HX_STRING(L"localY",6));
	outFields->push(HX_STRING(L"relatedObject",13));
	outFields->push(HX_STRING(L"shiftKey",8));
	outFields->push(HX_STRING(L"stageX",6));
	outFields->push(HX_STRING(L"stageY",6));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"CLICK",5),
	HX_STRING(L"DOUBLE_CLICK",12),
	HX_STRING(L"MOUSE_DOWN",10),
	HX_STRING(L"MOUSE_MOVE",10),
	HX_STRING(L"MOUSE_OUT",9),
	HX_STRING(L"MOUSE_OVER",10),
	HX_STRING(L"MOUSE_UP",8),
	HX_STRING(L"MOUSE_WHEEL",11),
	HX_STRING(L"ROLL_OUT",8),
	HX_STRING(L"ROLL_OVER",9),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"altKey",6),
	HX_STRING(L"buttonDown",10),
	HX_STRING(L"ctrlKey",7),
	HX_STRING(L"delta",5),
	HX_STRING(L"localX",6),
	HX_STRING(L"localY",6),
	HX_STRING(L"relatedObject",13),
	HX_STRING(L"shiftKey",8),
	HX_STRING(L"stageX",6),
	HX_STRING(L"stageY",6),
	HX_STRING(L"updateAfterEvent",16),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(MouseEvent_obj::CLICK);
	hx::MarkMember(MouseEvent_obj::DOUBLE_CLICK);
	hx::MarkMember(MouseEvent_obj::MOUSE_DOWN);
	hx::MarkMember(MouseEvent_obj::MOUSE_MOVE);
	hx::MarkMember(MouseEvent_obj::MOUSE_OUT);
	hx::MarkMember(MouseEvent_obj::MOUSE_OVER);
	hx::MarkMember(MouseEvent_obj::MOUSE_UP);
	hx::MarkMember(MouseEvent_obj::MOUSE_WHEEL);
	hx::MarkMember(MouseEvent_obj::ROLL_OUT);
	hx::MarkMember(MouseEvent_obj::ROLL_OVER);
};

Class MouseEvent_obj::__mClass;

void MouseEvent_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.events.MouseEvent",23), hx::TCanCast< MouseEvent_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MouseEvent_obj::__boot()
{
	hx::Static(CLICK) = HX_STRING(L"click",5);
	hx::Static(DOUBLE_CLICK) = HX_STRING(L"doubleClick",11);
	hx::Static(MOUSE_DOWN) = HX_STRING(L"mouseDown",9);
	hx::Static(MOUSE_MOVE) = HX_STRING(L"mouseMove",9);
	hx::Static(MOUSE_OUT) = HX_STRING(L"mouseOut",8);
	hx::Static(MOUSE_OVER) = HX_STRING(L"mouseOver",9);
	hx::Static(MOUSE_UP) = HX_STRING(L"mouseUp",7);
	hx::Static(MOUSE_WHEEL) = HX_STRING(L"mouseWheel",10);
	hx::Static(ROLL_OUT) = HX_STRING(L"rollOut",7);
	hx::Static(ROLL_OVER) = HX_STRING(L"rollOver",8);
}

} // end namespace neash
} // end namespace events
