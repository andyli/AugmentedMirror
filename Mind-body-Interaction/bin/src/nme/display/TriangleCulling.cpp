#include <hxcpp.h>

#ifndef INCLUDED_nme_display_TriangleCulling
#include <nme/display/TriangleCulling.h>
#endif
namespace nme{
namespace display{

TriangleCulling TriangleCulling_obj::NEGATIVE;

TriangleCulling TriangleCulling_obj::NONE;

TriangleCulling TriangleCulling_obj::POSITIVE;

HX_DEFINE_CREATE_ENUM(TriangleCulling_obj)

int TriangleCulling_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"NEGATIVE",8)) return 0;
	if (inName==HX_STRING(L"NONE",4)) return 1;
	if (inName==HX_STRING(L"POSITIVE",8)) return 2;
	return super::__FindIndex(inName);
}

int TriangleCulling_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"NEGATIVE",8)) return 0;
	if (inName==HX_STRING(L"NONE",4)) return 0;
	if (inName==HX_STRING(L"POSITIVE",8)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TriangleCulling_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"NEGATIVE",8)) return NEGATIVE;
	if (inName==HX_STRING(L"NONE",4)) return NONE;
	if (inName==HX_STRING(L"POSITIVE",8)) return POSITIVE;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"NEGATIVE",8),
	HX_STRING(L"NONE",4),
	HX_STRING(L"POSITIVE",8),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(TriangleCulling_obj::NEGATIVE);
	hx::MarkMember(TriangleCulling_obj::NONE);
	hx::MarkMember(TriangleCulling_obj::POSITIVE);
};

static ::String sMemberFields[] = { ::String(null()) };
Class TriangleCulling_obj::__mClass;

Dynamic __Create_TriangleCulling_obj() { return new TriangleCulling_obj; }

void TriangleCulling_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.TriangleCulling",27), hx::TCanCast< TriangleCulling_obj >,sStaticFields,sMemberFields,
	&__Create_TriangleCulling_obj, &__Create,
	&super::__SGetClass(), &CreateTriangleCulling_obj, sMarkStatics);
}

void TriangleCulling_obj::__boot()
{
Static(NEGATIVE) = hx::CreateEnum< TriangleCulling_obj >(HX_STRING(L"NEGATIVE",8),0);
Static(NONE) = hx::CreateEnum< TriangleCulling_obj >(HX_STRING(L"NONE",4),1);
Static(POSITIVE) = hx::CreateEnum< TriangleCulling_obj >(HX_STRING(L"POSITIVE",8),2);
}


} // end namespace nme
} // end namespace display
