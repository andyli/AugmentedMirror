#include <hxcpp.h>

#ifndef INCLUDED_neash_display_PixelSnapping
#include <neash/display/PixelSnapping.h>
#endif
namespace neash{
namespace display{

PixelSnapping PixelSnapping_obj::ALWAYS;

PixelSnapping PixelSnapping_obj::AUTO;

PixelSnapping PixelSnapping_obj::NEVER;

HX_DEFINE_CREATE_ENUM(PixelSnapping_obj)

int PixelSnapping_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"ALWAYS",6)) return 2;
	if (inName==HX_STRING(L"AUTO",4)) return 1;
	if (inName==HX_STRING(L"NEVER",5)) return 0;
	return super::__FindIndex(inName);
}

int PixelSnapping_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"ALWAYS",6)) return 0;
	if (inName==HX_STRING(L"AUTO",4)) return 0;
	if (inName==HX_STRING(L"NEVER",5)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic PixelSnapping_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"ALWAYS",6)) return ALWAYS;
	if (inName==HX_STRING(L"AUTO",4)) return AUTO;
	if (inName==HX_STRING(L"NEVER",5)) return NEVER;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"ALWAYS",6),
	HX_STRING(L"AUTO",4),
	HX_STRING(L"NEVER",5),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(PixelSnapping_obj::ALWAYS);
	hx::MarkMember(PixelSnapping_obj::AUTO);
	hx::MarkMember(PixelSnapping_obj::NEVER);
};

static ::String sMemberFields[] = { ::String(null()) };
Class PixelSnapping_obj::__mClass;

Dynamic __Create_PixelSnapping_obj() { return new PixelSnapping_obj; }

void PixelSnapping_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"neash.display.PixelSnapping",27), hx::TCanCast< PixelSnapping_obj >,sStaticFields,sMemberFields,
	&__Create_PixelSnapping_obj, &__Create,
	&super::__SGetClass(), &CreatePixelSnapping_obj, sMarkStatics);
}

void PixelSnapping_obj::__boot()
{
Static(ALWAYS) = hx::CreateEnum< PixelSnapping_obj >(HX_STRING(L"ALWAYS",6),2);
Static(AUTO) = hx::CreateEnum< PixelSnapping_obj >(HX_STRING(L"AUTO",4),1);
Static(NEVER) = hx::CreateEnum< PixelSnapping_obj >(HX_STRING(L"NEVER",5),0);
}


} // end namespace neash
} // end namespace display
