#include <hxcpp.h>

#ifndef INCLUDED_sandy_Alignment
#include <sandy/Alignment.h>
#endif
namespace sandy{

Alignment Alignment_obj::XY;

Alignment Alignment_obj::YZ;

Alignment Alignment_obj::ZX;

HX_DEFINE_CREATE_ENUM(Alignment_obj)

int Alignment_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"XY",2)) return 0;
	if (inName==HX_STRING(L"YZ",2)) return 1;
	if (inName==HX_STRING(L"ZX",2)) return 2;
	return super::__FindIndex(inName);
}

int Alignment_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"XY",2)) return 0;
	if (inName==HX_STRING(L"YZ",2)) return 0;
	if (inName==HX_STRING(L"ZX",2)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Alignment_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"XY",2)) return XY;
	if (inName==HX_STRING(L"YZ",2)) return YZ;
	if (inName==HX_STRING(L"ZX",2)) return ZX;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"XY",2),
	HX_STRING(L"YZ",2),
	HX_STRING(L"ZX",2),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(Alignment_obj::XY);
	hx::MarkMember(Alignment_obj::YZ);
	hx::MarkMember(Alignment_obj::ZX);
};

static ::String sMemberFields[] = { ::String(null()) };
Class Alignment_obj::__mClass;

Dynamic __Create_Alignment_obj() { return new Alignment_obj; }

void Alignment_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.Alignment",15), hx::TCanCast< Alignment_obj >,sStaticFields,sMemberFields,
	&__Create_Alignment_obj, &__Create,
	&super::__SGetClass(), &CreateAlignment_obj, sMarkStatics);
}

void Alignment_obj::__boot()
{
Static(XY) = hx::CreateEnum< Alignment_obj >(HX_STRING(L"XY",2),0);
Static(YZ) = hx::CreateEnum< Alignment_obj >(HX_STRING(L"YZ",2),1);
Static(ZX) = hx::CreateEnum< Alignment_obj >(HX_STRING(L"ZX",2),2);
}


} // end namespace sandy
