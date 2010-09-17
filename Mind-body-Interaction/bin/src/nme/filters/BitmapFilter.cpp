#include <hxcpp.h>

#ifndef INCLUDED_nme_filters_BitmapFilter
#include <nme/filters/BitmapFilter.h>
#endif
namespace nme{
namespace filters{

Void BitmapFilter_obj::__construct(::String inType)
{
{
	this->mType = inType;
}
;
	return null();
}

BitmapFilter_obj::~BitmapFilter_obj() { }

Dynamic BitmapFilter_obj::__CreateEmpty() { return  new BitmapFilter_obj; }
hx::ObjectPtr< BitmapFilter_obj > BitmapFilter_obj::__new(::String inType)
{  hx::ObjectPtr< BitmapFilter_obj > result = new BitmapFilter_obj();
	result->__construct(inType);
	return result;}

Dynamic BitmapFilter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BitmapFilter_obj > result = new BitmapFilter_obj();
	result->__construct(inArgs[0]);
	return result;}

::nme::filters::BitmapFilter BitmapFilter_obj::clone( ){
	hx::Throw (HX_STRING(L"clone not implemented",21));
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BitmapFilter_obj,clone,return )


BitmapFilter_obj::BitmapFilter_obj()
{
}

void BitmapFilter_obj::__Mark()
{
	hx::MarkMember(mType);
}

Dynamic BitmapFilter_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"mType",sizeof(wchar_t)*5) ) { return mType; }
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic BitmapFilter_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"mType",sizeof(wchar_t)*5) ) { mType=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void BitmapFilter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_STRING(L"mType",5));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_STRING(L"mType",5),
	HX_STRING(L"clone",5),
	String(null()) };

static void sMarkStatics() {
};

Class BitmapFilter_obj::__mClass;

void BitmapFilter_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.filters.BitmapFilter",24), hx::TCanCast< BitmapFilter_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void BitmapFilter_obj::__boot()
{
}

} // end namespace nme
} // end namespace filters
