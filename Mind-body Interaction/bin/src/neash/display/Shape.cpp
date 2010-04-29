#include <hxcpp.h>

#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_Shape
#include <neash/display/Shape.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
namespace neash{
namespace display{

Void Shape_obj::__construct()
{
{
	super::__construct();
	this->mGraphics = ::nme::display::Graphics_obj::__new(null());
	this->name = (HX_STRING(L"Shape ",6) + ::neash::display::DisplayObject_obj::mNameID++);
}
;
	return null();
}

Shape_obj::~Shape_obj() { }

Dynamic Shape_obj::__CreateEmpty() { return  new Shape_obj; }
hx::ObjectPtr< Shape_obj > Shape_obj::__new()
{  hx::ObjectPtr< Shape_obj > result = new Shape_obj();
	result->__construct();
	return result;}

Dynamic Shape_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Shape_obj > result = new Shape_obj();
	result->__construct();
	return result;}

::nme::display::Graphics Shape_obj::GetGraphics( ){
	return this->mGraphics;
}


HX_DEFINE_DYNAMIC_FUNC0(Shape_obj,GetGraphics,return )


Shape_obj::Shape_obj()
{
}

void Shape_obj::__Mark()
{
	hx::MarkMember(mGraphics);
	hx::MarkMember(graphics);
	super::__Mark();
}

Dynamic Shape_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"graphics",sizeof(wchar_t)*8) ) { return GetGraphics(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mGraphics",sizeof(wchar_t)*9) ) { return mGraphics; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"GetGraphics",sizeof(wchar_t)*11) ) { return GetGraphics_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Shape_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"graphics",sizeof(wchar_t)*8) ) { graphics=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mGraphics",sizeof(wchar_t)*9) ) { mGraphics=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Shape_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mGraphics",9));
	outFields->push(HX_STRING(L"graphics",8));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mGraphics",9),
	HX_STRING(L"graphics",8),
	HX_STRING(L"GetGraphics",11),
	String(null()) };

static void sMarkStatics() {
};

Class Shape_obj::__mClass;

void Shape_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.Shape",19), hx::TCanCast< Shape_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Shape_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
