#include <hxcpp.h>

#ifndef INCLUDED_nme_display_GradientType
#include <nme/display/GradientType.h>
#endif
namespace nme{
namespace display{

GradientType GradientType_obj::LINEAR;

GradientType GradientType_obj::RADIAL;

HX_DEFINE_CREATE_ENUM(GradientType_obj)

int GradientType_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"LINEAR",6)) return 1;
	if (inName==HX_STRING(L"RADIAL",6)) return 0;
	return super::__FindIndex(inName);
}

int GradientType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"LINEAR",6)) return 0;
	if (inName==HX_STRING(L"RADIAL",6)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GradientType_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"LINEAR",6)) return LINEAR;
	if (inName==HX_STRING(L"RADIAL",6)) return RADIAL;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"LINEAR",6),
	HX_STRING(L"RADIAL",6),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(GradientType_obj::LINEAR);
	hx::MarkMember(GradientType_obj::RADIAL);
};

static ::String sMemberFields[] = { ::String(null()) };
Class GradientType_obj::__mClass;

Dynamic __Create_GradientType_obj() { return new GradientType_obj; }

void GradientType_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.GradientType",24), hx::TCanCast< GradientType_obj >,sStaticFields,sMemberFields,
	&__Create_GradientType_obj, &__Create,
	&super::__SGetClass(), &CreateGradientType_obj, sMarkStatics);
}

void GradientType_obj::__boot()
{
Static(LINEAR) = hx::CreateEnum< GradientType_obj >(HX_STRING(L"LINEAR",6),1);
Static(RADIAL) = hx::CreateEnum< GradientType_obj >(HX_STRING(L"RADIAL",6),0);
}


} // end namespace nme
} // end namespace display
