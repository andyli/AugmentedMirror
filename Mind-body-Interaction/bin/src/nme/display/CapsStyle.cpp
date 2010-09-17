#include <hxcpp.h>

#ifndef INCLUDED_nme_display_CapsStyle
#include <nme/display/CapsStyle.h>
#endif
namespace nme{
namespace display{

CapsStyle CapsStyle_obj::NONE;

CapsStyle CapsStyle_obj::ROUND;

CapsStyle CapsStyle_obj::SQUARE;

HX_DEFINE_CREATE_ENUM(CapsStyle_obj)

int CapsStyle_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"NONE",4)) return 0;
	if (inName==HX_STRING(L"ROUND",5)) return 1;
	if (inName==HX_STRING(L"SQUARE",6)) return 2;
	return super::__FindIndex(inName);
}

int CapsStyle_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"NONE",4)) return 0;
	if (inName==HX_STRING(L"ROUND",5)) return 0;
	if (inName==HX_STRING(L"SQUARE",6)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic CapsStyle_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"NONE",4)) return NONE;
	if (inName==HX_STRING(L"ROUND",5)) return ROUND;
	if (inName==HX_STRING(L"SQUARE",6)) return SQUARE;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"NONE",4),
	HX_STRING(L"ROUND",5),
	HX_STRING(L"SQUARE",6),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(CapsStyle_obj::NONE);
	hx::MarkMember(CapsStyle_obj::ROUND);
	hx::MarkMember(CapsStyle_obj::SQUARE);
};

static ::String sMemberFields[] = { ::String(null()) };
Class CapsStyle_obj::__mClass;

Dynamic __Create_CapsStyle_obj() { return new CapsStyle_obj; }

void CapsStyle_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"nme.display.CapsStyle",21), hx::TCanCast< CapsStyle_obj >,sStaticFields,sMemberFields,
	&__Create_CapsStyle_obj, &__Create,
	&super::__SGetClass(), &CreateCapsStyle_obj, sMarkStatics);
}

void CapsStyle_obj::__boot()
{
Static(NONE) = hx::CreateEnum< CapsStyle_obj >(HX_STRING(L"NONE",4),0);
Static(ROUND) = hx::CreateEnum< CapsStyle_obj >(HX_STRING(L"ROUND",5),1);
Static(SQUARE) = hx::CreateEnum< CapsStyle_obj >(HX_STRING(L"SQUARE",6),2);
}


} // end namespace nme
} // end namespace display
