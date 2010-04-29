#include <hxcpp.h>

#ifndef INCLUDED_nme_display_InterpolationMethod
#include <nme/display/InterpolationMethod.h>
#endif
namespace nme{
namespace display{

InterpolationMethod InterpolationMethod_obj::LINEAR_RGB;

InterpolationMethod InterpolationMethod_obj::RGB;

HX_DEFINE_CREATE_ENUM(InterpolationMethod_obj)

int InterpolationMethod_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"LINEAR_RGB",10)) return 1;
	if (inName==HX_STRING(L"RGB",3)) return 0;
	return super::__FindIndex(inName);
}

int InterpolationMethod_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"LINEAR_RGB",10)) return 0;
	if (inName==HX_STRING(L"RGB",3)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic InterpolationMethod_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"LINEAR_RGB",10)) return LINEAR_RGB;
	if (inName==HX_STRING(L"RGB",3)) return RGB;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"LINEAR_RGB",10),
	HX_STRING(L"RGB",3),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(InterpolationMethod_obj::LINEAR_RGB);
	hx::MarkMember(InterpolationMethod_obj::RGB);
};

static ::String sMemberFields[] = { ::String(null()) };
Class InterpolationMethod_obj::__mClass;

Dynamic __Create_InterpolationMethod_obj() { return new InterpolationMethod_obj; }

void InterpolationMethod_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.InterpolationMethod",31), hx::TCanCast< InterpolationMethod_obj >,sStaticFields,sMemberFields,
	&__Create_InterpolationMethod_obj, &__Create,
	&super::__SGetClass(), &CreateInterpolationMethod_obj, sMarkStatics);
}

void InterpolationMethod_obj::__boot()
{
Static(LINEAR_RGB) = hx::CreateEnum< InterpolationMethod_obj >(HX_STRING(L"LINEAR_RGB",10),1);
Static(RGB) = hx::CreateEnum< InterpolationMethod_obj >(HX_STRING(L"RGB",3),0);
}


} // end namespace nme
} // end namespace display
