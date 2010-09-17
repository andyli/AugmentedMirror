#include <hxcpp.h>

#ifndef INCLUDED_neash_Lib
#include <neash/Lib.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObjectContainer
#include <neash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_neash_display_InteractiveObject
#include <neash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_neash_display_Sprite
#include <neash/display/Sprite.h>
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
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
#ifndef INCLUDED_nme_geom_Rectangle
#include <nme/geom/Rectangle.h>
#endif
namespace neash{
namespace display{

Void Sprite_obj::__construct()
{
{
	super::__construct();
	this->mGraphics = ::nme::display::Graphics_obj::__new(null());
	this->buttonMode = false;
	this->name = (HX_STRING(L"Sprite ",7) + ::neash::display::DisplayObject_obj::mNameID++);
}
;
	return null();
}

Sprite_obj::~Sprite_obj() { }

Dynamic Sprite_obj::__CreateEmpty() { return  new Sprite_obj; }
hx::ObjectPtr< Sprite_obj > Sprite_obj::__new()
{  hx::ObjectPtr< Sprite_obj > result = new Sprite_obj();
	result->__construct();
	return result;}

Dynamic Sprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sprite_obj > result = new Sprite_obj();
	result->__construct();
	return result;}

Void Sprite_obj::startDrag( Dynamic lockCenter,::nme::geom::Rectangle bounds){
{
		__SAFE_POINT
		::neash::Lib_obj::SetDragged(this,lockCenter,bounds);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Sprite_obj,startDrag,(void))

Void Sprite_obj::stopDrag( ){
{
		__SAFE_POINT
		::neash::Lib_obj::SetDragged(null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite_obj,stopDrag,(void))

Array< ::neash::display::DisplayObject > Sprite_obj::getObjectsUnderPoint( ::nme::geom::Point pPoint){
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite_obj,getObjectsUnderPoint,return )

::nme::geom::Point Sprite_obj::localToGlobal( ::nme::geom::Point pPoint){
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Sprite_obj,localToGlobal,return )

::nme::display::Graphics Sprite_obj::GetGraphics( ){
	return this->mGraphics;
}


HX_DEFINE_DYNAMIC_FUNC0(Sprite_obj,GetGraphics,return )


Sprite_obj::Sprite_obj()
{
}

void Sprite_obj::__Mark()
{
	hx::MarkMember(mGraphics);
	hx::MarkMember(graphics);
	hx::MarkMember(buttonMode);
	super::__Mark();
}

Dynamic Sprite_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"graphics",sizeof(wchar_t)*8) ) { return GetGraphics(); }
		if (!memcmp(inName.__s,L"stopDrag",sizeof(wchar_t)*8) ) { return stopDrag_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mGraphics",sizeof(wchar_t)*9) ) { return mGraphics; }
		if (!memcmp(inName.__s,L"startDrag",sizeof(wchar_t)*9) ) { return startDrag_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"buttonMode",sizeof(wchar_t)*10) ) { return buttonMode; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"GetGraphics",sizeof(wchar_t)*11) ) { return GetGraphics_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"localToGlobal",sizeof(wchar_t)*13) ) { return localToGlobal_dyn(); }
		break;
	case 20:
		if (!memcmp(inName.__s,L"getObjectsUnderPoint",sizeof(wchar_t)*20) ) { return getObjectsUnderPoint_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Sprite_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 8:
		if (!memcmp(inName.__s,L"graphics",sizeof(wchar_t)*8) ) { graphics=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mGraphics",sizeof(wchar_t)*9) ) { mGraphics=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"buttonMode",sizeof(wchar_t)*10) ) { buttonMode=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Sprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mGraphics",9));
	outFields->push(HX_STRING(L"graphics",8));
	outFields->push(HX_STRING(L"buttonMode",10));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mGraphics",9),
	HX_STRING(L"graphics",8),
	HX_STRING(L"buttonMode",10),
	HX_STRING(L"startDrag",9),
	HX_STRING(L"stopDrag",8),
	HX_STRING(L"getObjectsUnderPoint",20),
	HX_STRING(L"localToGlobal",13),
	HX_STRING(L"GetGraphics",11),
	String(null()) };

static void sMarkStatics() {
};

Class Sprite_obj::__mClass;

void Sprite_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.Sprite",20), hx::TCanCast< Sprite_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Sprite_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
