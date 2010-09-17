#include <hxcpp.h>

#ifndef INCLUDED_nme_display_SpreadMethod
#include <nme/display/SpreadMethod.h>
#endif
namespace nme{
namespace display{

SpreadMethod SpreadMethod_obj::PAD;

SpreadMethod SpreadMethod_obj::REFLECT;

SpreadMethod SpreadMethod_obj::REPEAT;

HX_DEFINE_CREATE_ENUM(SpreadMethod_obj)

int SpreadMethod_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"PAD",3)) return 2;
	if (inName==HX_STRING(L"REFLECT",7)) return 1;
	if (inName==HX_STRING(L"REPEAT",6)) return 0;
	return super::__FindIndex(inName);
}

int SpreadMethod_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"PAD",3)) return 0;
	if (inName==HX_STRING(L"REFLECT",7)) return 0;
	if (inName==HX_STRING(L"REPEAT",6)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic SpreadMethod_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"PAD",3)) return PAD;
	if (inName==HX_STRING(L"REFLECT",7)) return REFLECT;
	if (inName==HX_STRING(L"REPEAT",6)) return REPEAT;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"PAD",3),
	HX_STRING(L"REFLECT",7),
	HX_STRING(L"REPEAT",6),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(SpreadMethod_obj::PAD);
	hx::MarkMember(SpreadMethod_obj::REFLECT);
	hx::MarkMember(SpreadMethod_obj::REPEAT);
};

static ::String sMemberFields[] = { ::String(null()) };
Class SpreadMethod_obj::__mClass;

Dynamic __Create_SpreadMethod_obj() { return new SpreadMethod_obj; }

void SpreadMethod_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.SpreadMethod",24), hx::TCanCast< SpreadMethod_obj >,sStaticFields,sMemberFields,
	&__Create_SpreadMethod_obj, &__Create,
	&super::__SGetClass(), &CreateSpreadMethod_obj, sMarkStatics);
}

void SpreadMethod_obj::__boot()
{
Static(PAD) = hx::CreateEnum< SpreadMethod_obj >(HX_STRING(L"PAD",3),2);
Static(REFLECT) = hx::CreateEnum< SpreadMethod_obj >(HX_STRING(L"REFLECT",7),1);
Static(REPEAT) = hx::CreateEnum< SpreadMethod_obj >(HX_STRING(L"REPEAT",6),0);
}


} // end namespace nme
} // end namespace display
