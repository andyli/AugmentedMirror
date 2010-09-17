#include <hxcpp.h>

#ifndef INCLUDED_sandy_CoordinateSystem
#include <sandy/CoordinateSystem.h>
#endif
namespace sandy{

CoordinateSystem CoordinateSystem_obj::ABSOLUTE;

CoordinateSystem CoordinateSystem_obj::CAMERA;

CoordinateSystem CoordinateSystem_obj::LOCAL;

HX_DEFINE_CREATE_ENUM(CoordinateSystem_obj)

int CoordinateSystem_obj::__FindIndex(::String inName)
{
	if (inName==HX_STRING(L"ABSOLUTE",8)) return 2;
	if (inName==HX_STRING(L"CAMERA",6)) return 1;
	if (inName==HX_STRING(L"LOCAL",5)) return 0;
	return super::__FindIndex(inName);
}

int CoordinateSystem_obj::__FindArgCount(::String inName)
{
	if (inName==HX_STRING(L"ABSOLUTE",8)) return 0;
	if (inName==HX_STRING(L"CAMERA",6)) return 0;
	if (inName==HX_STRING(L"LOCAL",5)) return 0;
	return super::__FindArgCount(inName);
}

Dynamic CoordinateSystem_obj::__Field(const ::String &inName)
{
	if (inName==HX_STRING(L"ABSOLUTE",8)) return ABSOLUTE;
	if (inName==HX_STRING(L"CAMERA",6)) return CAMERA;
	if (inName==HX_STRING(L"LOCAL",5)) return LOCAL;
	return super::__Field(inName);
}

static ::String sStaticFields[] = {
	HX_STRING(L"ABSOLUTE",8),
	HX_STRING(L"CAMERA",6),
	HX_STRING(L"LOCAL",5),
	::String(null()) };

static void sMarkStatics() {
	hx::MarkMember(CoordinateSystem_obj::ABSOLUTE);
	hx::MarkMember(CoordinateSystem_obj::CAMERA);
	hx::MarkMember(CoordinateSystem_obj::LOCAL);
};

static ::String sMemberFields[] = { ::String(null()) };
Class CoordinateSystem_obj::__mClass;

Dynamic __Create_CoordinateSystem_obj() { return new CoordinateSystem_obj; }

void CoordinateSystem_obj::__register()
{

Static(__mClass) = hx::RegisterClass(HX_STRING(L"sandy.CoordinateSystem",22), hx::TCanCast< CoordinateSystem_obj >,sStaticFields,sMemberFields,
	&__Create_CoordinateSystem_obj, &__Create,
	&super::__SGetClass(), &CreateCoordinateSystem_obj, sMarkStatics);
}

void CoordinateSystem_obj::__boot()
{
Static(ABSOLUTE) = hx::CreateEnum< CoordinateSystem_obj >(HX_STRING(L"ABSOLUTE",8),2);
Static(CAMERA) = hx::CreateEnum< CoordinateSystem_obj >(HX_STRING(L"CAMERA",6),1);
Static(LOCAL) = hx::CreateEnum< CoordinateSystem_obj >(HX_STRING(L"LOCAL",5),0);
}


} // end namespace sandy
