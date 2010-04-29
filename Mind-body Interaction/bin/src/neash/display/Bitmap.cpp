#include <hxcpp.h>

#ifndef INCLUDED_neash_display_Bitmap
#include <neash/display/Bitmap.h>
#endif
#ifndef INCLUDED_neash_display_DisplayObject
#include <neash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_neash_display_PixelSnapping
#include <neash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_neash_events_EventDispatcher
#include <neash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_neash_events_IEventDispatcher
#include <neash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_Graphics
#include <nme/display/Graphics.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_geom_Matrix
#include <nme/geom/Matrix.h>
#endif
namespace neash{
namespace display{

Void Bitmap_obj::__construct(::nme::display::BitmapData inBitmapData,::neash::display::PixelSnapping inPixelSnapping,Dynamic inSmoothing)
{
{
	super::__construct();
	this->pixelSnapping = inPixelSnapping;
	this->smoothing = inSmoothing;
	this->mGraphics = ::nme::display::Graphics_obj::__new(null());
	this->SetBitmapData(inBitmapData);
}
;
	return null();
}

Bitmap_obj::~Bitmap_obj() { }

Dynamic Bitmap_obj::__CreateEmpty() { return  new Bitmap_obj; }
hx::ObjectPtr< Bitmap_obj > Bitmap_obj::__new(::nme::display::BitmapData inBitmapData,::neash::display::PixelSnapping inPixelSnapping,Dynamic inSmoothing)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(inBitmapData,inPixelSnapping,inSmoothing);
	return result;}

Dynamic Bitmap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bitmap_obj > result = new Bitmap_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::nme::display::BitmapData Bitmap_obj::SetBitmapData( ::nme::display::BitmapData inBitmapData){
	__SAFE_POINT
	this->bitmapData = inBitmapData;
	this->mGraphics->clear();
	if ((inBitmapData != null())){
		this->mGraphics->beginBitmapFill(inBitmapData,null(),false,this->smoothing);
		this->mGraphics->drawRect(0,0,inBitmapData->getWidth(),inBitmapData->getHeight());
		this->mGraphics->endFill();
	}
	return inBitmapData;
}


HX_DEFINE_DYNAMIC_FUNC1(Bitmap_obj,SetBitmapData,return )

::nme::display::Graphics Bitmap_obj::GetGraphics( ){
	return this->mGraphics;
}


HX_DEFINE_DYNAMIC_FUNC0(Bitmap_obj,GetGraphics,return )


Bitmap_obj::Bitmap_obj()
{
}

void Bitmap_obj::__Mark()
{
	hx::MarkMember(bitmapData);
	hx::MarkMember(pixelSnapping);
	hx::MarkMember(smoothing);
	hx::MarkMember(mGraphics);
	super::__Mark();
}

Dynamic Bitmap_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"smoothing",sizeof(wchar_t)*9) ) { return smoothing; }
		if (!memcmp(inName.__s,L"mGraphics",sizeof(wchar_t)*9) ) { return mGraphics; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"bitmapData",sizeof(wchar_t)*10) ) { return bitmapData; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"GetGraphics",sizeof(wchar_t)*11) ) { return GetGraphics_dyn(); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"pixelSnapping",sizeof(wchar_t)*13) ) { return pixelSnapping; }
		if (!memcmp(inName.__s,L"SetBitmapData",sizeof(wchar_t)*13) ) { return SetBitmapData_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic Bitmap_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 9:
		if (!memcmp(inName.__s,L"smoothing",sizeof(wchar_t)*9) ) { smoothing=inValue.Cast< bool >(); return inValue; }
		if (!memcmp(inName.__s,L"mGraphics",sizeof(wchar_t)*9) ) { mGraphics=inValue.Cast< ::nme::display::Graphics >(); return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"bitmapData",sizeof(wchar_t)*10) ) { return SetBitmapData(inValue); }
		break;
	case 13:
		if (!memcmp(inName.__s,L"pixelSnapping",sizeof(wchar_t)*13) ) { pixelSnapping=inValue.Cast< ::neash::display::PixelSnapping >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Bitmap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"bitmapData",10));
	outFields->push(HX_STRING(L"pixelSnapping",13));
	outFields->push(HX_STRING(L"smoothing",9));
	outFields->push(HX_STRING(L"mGraphics",9));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"bitmapData",10),
	HX_STRING(L"pixelSnapping",13),
	HX_STRING(L"smoothing",9),
	HX_STRING(L"mGraphics",9),
	HX_STRING(L"SetBitmapData",13),
	HX_STRING(L"GetGraphics",11),
	String(null()) };

static void sMarkStatics() {
};

Class Bitmap_obj::__mClass;

void Bitmap_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.Bitmap",20), hx::TCanCast< Bitmap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Bitmap_obj::__boot()
{
}

} // end namespace neash
} // end namespace display
