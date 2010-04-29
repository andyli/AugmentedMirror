#include <hxcpp.h>

#ifndef INCLUDED_neash_text_FontInstanceMode
#include <neash/text/FontInstanceMode.h>
#endif
namespace neash{
namespace text{

FontInstanceMode FontInstanceMode_obj::fimSolid;

HX_DEFINE_CREATE_ENUM(FontInstanceMode_obj)

int FontInstanceMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"fimSolid",8)) return 0;
	return super::__FindIndex(inName);
}

int FontInstanceMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"fimSolid",8)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic FontInstanceMode_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"fimSolid",8)) return fimSolid;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"fimSolid",8),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(FontInstanceMode_obj::fimSolid);
};

static ::String sMemberFields[] = { ::String(null()) };
Class FontInstanceMode_obj::__mClass;

Dynamic __Create_FontInstanceMode_obj() { return new FontInstanceMode_obj; }

void FontInstanceMode_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.text.FontInstanceMode",27), hx::TCanCast< FontInstanceMode_obj >,sStaticFields,sMemberFields,
	&__Create_FontInstanceMode_obj, &__Create,
	&super::__SGetClass(), &CreateFontInstanceMode_obj, sMarkStatics);
}

void FontInstanceMode_obj::__boot()
{
Static(fimSolid) = hx::CreateEnum< FontInstanceMode_obj >(HX_STRING(L"fimSolid",8),0);
}


} // end namespace neash
} // end namespace text
