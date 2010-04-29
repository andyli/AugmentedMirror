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
#ifndef INCLUDED_neash_events_KeyboardEvent
#include <neash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
namespace neash{
namespace display{

Void InteractiveObject_obj::__construct()
{
{
	super::__construct();
	this->tabEnabled = false;
	this->mouseEnabled = true;
	this->SetTabIndex(0);
	this->name = HX_STRING(L"InteractiveObject",17);
}
;
	return null();
}

InteractiveObject_obj::~InteractiveObject_obj() { }

Dynamic InteractiveObject_obj::__CreateEmpty() { return  new InteractiveObject_obj; }
hx::ObjectPtr< InteractiveObject_obj > InteractiveObject_obj::__new()
{  hx::ObjectPtr< InteractiveObject_obj > result = new InteractiveObject_obj();
	result->__construct();
	return result;}

Dynamic InteractiveObject_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InteractiveObject_obj > result = new InteractiveObject_obj();
	result->__construct();
	return result;}

::String InteractiveObject_obj::toString( ){
	return this->name;
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,toString,return )

Void InteractiveObject_obj::OnKey( ::neash::events::KeyboardEvent inKey){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,OnKey,(void))

::neash::display::InteractiveObject InteractiveObject_obj::AsInteractiveObject( ){
	return this;
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,AsInteractiveObject,return )

int InteractiveObject_obj::SetTabIndex( int inIndex){
	this->tabIndex = inIndex;
	return inIndex;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,SetTabIndex,return )

bool InteractiveObject_obj::__getDoubleClickEnabled( ){
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,__getDoubleClickEnabled,return )

bool InteractiveObject_obj::__setDoubleClickEnabled( bool v){
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,__setDoubleClickEnabled,return )

Void InteractiveObject_obj::OnFocusIn( bool inMouse){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InteractiveObject_obj,OnFocusIn,(void))

Void InteractiveObject_obj::OnFocusOut( ){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InteractiveObject_obj,OnFocusOut,(void))

Void InteractiveObject_obj::OnMouseDown( int inX,int inY){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InteractiveObject_obj,OnMouseDown,(void))

Void InteractiveObject_obj::OnMouseUp( int inX,int inY){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InteractiveObject_obj,OnMouseUp,(void))

Void InteractiveObject_obj::OnMouseDrag( int inX,int inY){
{
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InteractiveObject_obj,OnMouseDrag,(void))


InteractiveObject_obj::InteractiveObject_obj()
{
}

void InteractiveObject_obj::__Mark()
{
	hx::MarkMember(doubleClickEnabled);
	hx::MarkMember(mouseEnabled);
	hx::MarkMember(tabEnabled);
	hx::MarkMember(tabIndex);
	super::__Mark();
}

Dynamic InteractiveObject_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"OnKey",sizeof(wchar_t)*5) ) { return OnKey_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"tabIndex",sizeof(wchar_t)*8) ) { return tabIndex; }
		if (!memcmp(inName.__s,L"toString",sizeof(wchar_t)*8) ) { return toString_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"OnFocusIn",sizeof(wchar_t)*9) ) { return OnFocusIn_dyn(); }
		if (!memcmp(inName.__s,L"OnMouseUp",sizeof(wchar_t)*9) ) { return OnMouseUp_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"tabEnabled",sizeof(wchar_t)*10) ) { return tabEnabled; }
		if (!memcmp(inName.__s,L"OnFocusOut",sizeof(wchar_t)*10) ) { return OnFocusOut_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"SetTabIndex",sizeof(wchar_t)*11) ) { return SetTabIndex_dyn(); }
		if (!memcmp(inName.__s,L"OnMouseDown",sizeof(wchar_t)*11) ) { return OnMouseDown_dyn(); }
		if (!memcmp(inName.__s,L"OnMouseDrag",sizeof(wchar_t)*11) ) { return OnMouseDrag_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mouseEnabled",sizeof(wchar_t)*12) ) { return mouseEnabled; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"doubleClickEnabled",sizeof(wchar_t)*18) ) { return __getDoubleClickEnabled(); }
		break;
	case 19:
		if (!memcmp(inName.__s,L"AsInteractiveObject",sizeof(wchar_t)*19) ) { return AsInteractiveObject_dyn(); }
		break;
	case 23:
		if (!memcmp(inName.__s,L"__getDoubleClickEnabled",sizeof(wchar_t)*23) ) { return __getDoubleClickEnabled_dyn(); }
		if (!memcmp(inName.__s,L"__setDoubleClickEnabled",sizeof(wchar_t)*23) ) { return __setDoubleClickEnabled_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic InteractiveObject_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"tabIndex",sizeof(wchar_t)*8) ) { return SetTabIndex(inValue); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"tabEnabled",sizeof(wchar_t)*10) ) { tabEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mouseEnabled",sizeof(wchar_t)*12) ) { mouseEnabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (!memcmp(inName.__s,L"doubleClickEnabled",sizeof(wchar_t)*18) ) { return __setDoubleClickEnabled(inValue); }
	}
	return super::__SetField(inName,inValue);
}

void InteractiveObject_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"doubleClickEnabled",18));
	outFields->push(HX_STRING(L"mouseEnabled",12));
	outFields->push(HX_STRING(L"tabEnabled",10));
	outFields->push(HX_STRING(L"tabIndex",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"doubleClickEnabled",18),
	HX_STRING(L"mouseEnabled",12),
	HX_STRING(L"tabEnabled",10),
	HX_STRING(L"tabIndex",8),
	HX_STRING(L"toString",8),
	HX_STRING(L"OnKey",5),
	HX_STRING(L"AsInteractiveObject",19),
	HX_STRING(L"SetTabIndex",11),
	HX_STRING(L"__getDoubleClickEnabled",23),
	HX_STRING(L"__setDoubleClickEnabled",23),
	HX_STRING(L"OnFocusIn",9),
	HX_STRING(L"OnFocusOut",10),
	HX_STRING(L"OnMouseDown",11),
	HX_STRING(L"OnMouseUp",9),
	HX_STRING(L"OnMouseDrag",11),
	String(null()) };

static void sMarkStatics() {
};

Class InteractiveObject_obj::__mClass;

void InteractiveObject_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.InteractiveObject",31), hx::TCanCast< InteractiveObject_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InteractiveObject_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
