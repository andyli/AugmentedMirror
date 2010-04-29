#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_nme_Loader
#include <nme/Loader.h>
#endif
#ifndef INCLUDED_nme_display_BitmapData
#include <nme/display/BitmapData.h>
#endif
#ifndef INCLUDED_nme_display_IBitmapDrawable
#include <nme/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_nme_filters_BitmapFilterSet
#include <nme/filters/BitmapFilterSet.h>
#endif
#ifndef INCLUDED_nme_geom_Point
#include <nme/geom/Point.h>
#endif
namespace nme{
namespace filters{

Void BitmapFilterSet_obj::__construct(Array< Dynamic > inFilters)
{
{
	this->mOffset = ::nme::geom::Point_obj::__new(null(),null());
	this->mHandle = ::nme::filters::BitmapFilterSet_obj::nme_create_filter_set(inFilters,this->mOffset);
}
;
	return null();
}

BitmapFilterSet_obj::~BitmapFilterSet_obj() { }

Dynamic BitmapFilterSet_obj::__CreateEmpty() { return  new BitmapFilterSet_obj; }
hx::ObjectPtr< BitmapFilterSet_obj > BitmapFilterSet_obj::__new(Array< Dynamic > inFilters)
{  hx::ObjectPtr< BitmapFilterSet_obj > result = new BitmapFilterSet_obj();
	result->__construct(inFilters);
	return result;}

Dynamic BitmapFilterSet_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapFilterSet_obj > result = new BitmapFilterSet_obj();
	result->__construct(inArgs[0]);
	return result;}

::nme::display::BitmapData BitmapFilterSet_obj::FilterImage( ::nme::display::BitmapData inImage){
	__SAFE_POINT
	Dynamic texture_handle = ::nme::filters::BitmapFilterSet_obj::nme_filter_image(this->mHandle,inImage->handle());
	return ::nme::display::BitmapData_obj::CreateFromHandle(texture_handle);
}


HX_DEFINE_DYNAMIC_FUNC1(BitmapFilterSet_obj,FilterImage,return )

int BitmapFilterSet_obj::GetOffsetX( ){
	__SAFE_POINT
	return ::Std_obj::toInt(this->mOffset->x);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapFilterSet_obj,GetOffsetX,return )

int BitmapFilterSet_obj::GetOffsetY( ){
	__SAFE_POINT
	return ::Std_obj::toInt(this->mOffset->y);
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapFilterSet_obj,GetOffsetY,return )

Dynamic BitmapFilterSet_obj::nme_filter_image;

Dynamic BitmapFilterSet_obj::nme_create_filter_set;


BitmapFilterSet_obj::BitmapFilterSet_obj()
{
}

void BitmapFilterSet_obj::__Mark()
{
	hx::MarkMember(mHandle);
	hx::MarkMember(mOffset);
}

Dynamic BitmapFilterSet_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"mHandle",sizeof(wchar_t)*7) ) { return mHandle; }
		if (!memcmp(inName.__s,L"mOffset",sizeof(wchar_t)*7) ) { return mOffset; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"GetOffsetX",sizeof(wchar_t)*10) ) { return GetOffsetX_dyn(); }
		if (!memcmp(inName.__s,L"GetOffsetY",sizeof(wchar_t)*10) ) { return GetOffsetY_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"FilterImage",sizeof(wchar_t)*11) ) { return FilterImage_dyn(); }
		break;
	case 16:
		if (!memcmp(inName.__s,L"nme_filter_image",sizeof(wchar_t)*16) ) { return nme_filter_image; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_create_filter_set",sizeof(wchar_t)*21) ) { return nme_create_filter_set; }
	}
	return super::__Field(inName);
}

Dynamic BitmapFilterSet_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 7:
		if (!memcmp(inName.__s,L"mHandle",sizeof(wchar_t)*7) ) { mHandle=inValue.Cast< Dynamic >(); return inValue; }
		if (!memcmp(inName.__s,L"mOffset",sizeof(wchar_t)*7) ) { mOffset=inValue.Cast< ::nme::geom::Point >(); return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"nme_filter_image",sizeof(wchar_t)*16) ) { nme_filter_image=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (!memcmp(inName.__s,L"nme_create_filter_set",sizeof(wchar_t)*21) ) { nme_create_filter_set=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapFilterSet_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mHandle",7));
	outFields->push(HX_STRING(L"mOffset",7));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_STRING(L"nme_filter_image",16),
	HX_STRING(L"nme_create_filter_set",21),
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mHandle",7),
	HX_STRING(L"mOffset",7),
	HX_STRING(L"FilterImage",11),
	HX_STRING(L"GetOffsetX",10),
	HX_STRING(L"GetOffsetY",10),
	String(null()) };

static void sMarkStatics() {
	hx::MarkMember(BitmapFilterSet_obj::nme_filter_image);
	hx::MarkMember(BitmapFilterSet_obj::nme_create_filter_set);
};

Class BitmapFilterSet_obj::__mClass;

void BitmapFilterSet_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.filters.BitmapFilterSet",27), hx::TCanCast< BitmapFilterSet_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapFilterSet_obj::__boot()
{
	hx::Static(nme_filter_image) = ::nme::Loader_obj::load(HX_STRING(L"nme_filter_image",16),2);
	hx::Static(nme_create_filter_set) = ::nme::Loader_obj::load(HX_STRING(L"nme_create_filter_set",21),2);
}

} // end namespace nme
} // end namespace filters
